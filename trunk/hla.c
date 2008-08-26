/**********************************************/
/*                                            */
/* HLA.C                                      */
/*                                            */
/* This is the "shell" for the HLA compiler.  */
/* The purpose of this program is to collect  */
/* and process Windows/Linux command line     */	 
/* parameters, reformat them, and then run    */
/* the actual HLA compiler, the assembler,    */
/* the linker, and (in the case of Windows)   */
/* the resource compiler.                     */
/*                                            */
/* This program processes a multitude of      */
/* different command line parameters.  Please */
/* see the HLA documentation for a complete   */
/* description of the command line options.   */
/*                                            */
/* Randall Hyde 9/13/1999                     */
/*                                            */
/**********************************************/



#define polinker "polink"
#define mslinker "link"



#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
 
 // MsgOut is the standard output device
 // file handle (this program redirects it
 // between the standard output and the standard
 // error output devices depending upon command
 // line parameters).

 
FILE *MsgOut;

// debug.h must appear before the following
// #IFxxx statements!

#include "debug.h"



#include "common.h"
#include "symbol.h"
#include "hlaparse.h"
#include "version.h"

 
// Override default RatC _name definition
// for tracing through the HLA.EXE code) 

#define _nameDefault "HLABison";

#include "ratc.h"
			

// Source and object code production:
//
//	linker    - selects which linker will process the object files.
//	SourceFmt - specifies the assembly language output format.
//	ObjFmt 	  - specifies the ultimate object code format.
//	Internal  - If true, use internal FASM to directly produce an OBJ file.
//  targetOS  - The OS under which the (user's) compiled code is to run.
//	gasSyntax - Select standard Gas syntax or Mac OSX gas syntax if 
//					SourceFmt is "gas".
			
#if defined(linux_c)

	#undef  windows_c 
	#define unixOS
	enum	OSChoice		targetOS 	= linux_os;
	enum	OSChoice		hostOS	 	= linux_os;
	enum	AsmChoice		SourceFmt 	= gas;
	enum	gasChoice		gasSyntax	= stdGas;
	enum	ObjFormat		ObjFmt 		= elf;
	enum	LinkerChoice	linker 		= ld;
			int				Internal 	= 0;
			char			*OSName		= "Linux";

#elif defined( freeBSD_c )

	#undef  windows_c 
	#define unixOS
	enum	OSChoice		targetOS 	= freeBSD_os;
	enum	OSChoice		hostOS	 	= freeBSD_os;
	enum	AsmChoice		SourceFmt 	= gas;
	enum	gasChoice		gasSyntax	= stdGas;
	enum	ObjFormat		ObjFmt 		= elf;
	enum	LinkerChoice	linker 		= ld;
			int				Internal 	= 0;
			char			*OSName		= "FreeBSD";

#elif defined( macOS_c )

	#undef  windows_c 
	#define unixOS
	enum	OSChoice		targetOS 	= macOS_os;
	enum	OSChoice		hostOS	 	= macOS_os;
	enum	AsmChoice		SourceFmt 	= gas;
	enum	gasChoice		gasSyntax	= macGas;
	enum	ObjFormat		ObjFmt 		= macho;
	enum	LinkerChoice	linker 		= ld;
			int				Internal 	= 0;
			char			*OSName		= "Mac OSX";

#else

	#include <process.h>
	#include <windows.h>

	#define windows_c
	#undef  unixOS
	enum	OSChoice		targetOS 	= windows_os;
	enum	OSChoice		hostOS	 	= windows_os;
	enum	AsmChoice		SourceFmt	= fasm;
	enum	gasChoice		gasSyntax	= stdGas;
	enum	ObjFormat		ObjFmt 		= coff;
	enum	LinkerChoice	linker 		= polink;
			int				Internal 	= 1;
			char			*OSName		= "Windows";

	
#endif

// sourceOutput -
//	Controls whether the output is a (mostly) human-readable text
// file (1) or just a bunch of hexadecimal values encoding the instructions (0).
 
int	sourceOutput = 0;	// Default to hexadecimal opcode output.

// threadSafe-
//	Passes "-thread" command-line parameter on to HLAPARSE

int threadSafe = 0;
			

// Variables used by the main program and command line processing function:

int		MLResult;			// Return result from the assembler (ML.EXE)
int		CurMLResult;
char	CmdLine[8192];		// We'll buffer the command line we build here.
int		TotalErrors = 0;	// Used to abort compilation if there are errors
int		IgnoreErrors = 0;	// Used for testing HLA output.
int		codeFirst = 0;		// Determines if code is emitted before ReadOnly data.
char	*mainName = NULL;	// HLA Main Program name.
							

// Variables used to process the command line.

int		level = high_level;	/* -level=xxxx option					*/
int		SourceOnly = 0;		/* -s option (compile only to .ASM).	*/
int		CompileOnly = 0;	/* -c option (compiles and assembles).	*/
int		ResponseFile = 1;   /* 0=none, 1=typical, 2=extended.		*/
int		WindowsApp = 0;		/* -w option (default is console app).	*/
int		DumpSymbols = 0;	/* -d option (dump symbol table).		*/
int		MapFile = 0;		/* -m option (create map file).			*/
int		Verbose = 0;		/* -v option (verbose compile).			*/
char	*baseName;			/* base name of the file names			*/
char	*ExeName = NULL;	/* -e:executable file name.				*/
char	*BinName = NULL;	/* -b:object binary object file name.	*/
char	*tempPath;			/* -p:path temporary filename path.		*/
char	*objPath = "";		/* -obj:path filename path.				*/
int		FileCnt = 0;		/* # of filenames on the cmd line.		*/
int		CurArg;				/* Current command line argument.		*/
char	ThisArg;			/* Holds a single command argument char	*/
char	LinkName[1024];		/* Contains list of ".link" filenames.	*/
char	Defines[ 256 ];		/* List of "-Dxx=yy" cmd line options.	*/
char	AsmOpts[ 256 ];		/* Assembler command line options.		*/
char	LinkOpts[ 256 ];	/* Linker command line options.			*/
char	ucArg[ 128 ];		/* Current arg converted to upper case	*/
char	*FileList[128];		/* Filenames provided on cmd line.		*/

 

char	*asmStrs[4] = { "MASM", "FASM", "TASM", "GAS" };
char	*linkStrs[4] = { "MSLINK", "POLINK", "LD" };
char	*objStrs[3] = { "coff", "omf", "elf" };
char	*levelStrs[4] =
			{ "-level=machine", "-level=low", "-level=medium", "-level=high" };


int		hlaErr;
char	HlaName [ 128 ];
char	AsmName [ 128 ];
char	ObjName [ 128 ];
char	RCName  [ 128 ];
char	hlaCmdLn[ 256 ];

// Suffix types for the files we will process

enum sfx 
	{
		null_c,
		hla_c, 
		asm_c, 
		rc_c, 
		res_c, 
		obj_c,
		fobj_c, 
		lib_c,
		o_c,
		a_c
	};
	
		
enum sfx Suffixes[128];		/* Suffixes associated with each file	*/
enum sfx Suffix;

int		 HlaFile;


#ifdef unixOS

	char	includeLib[4096];	// #includelib statements.
	char	ilInput[1024];
	char	*sfxStrs[ 10 ] = 
			{ 
				".hla", 
				".hla", 
				".asm", 
				".rc", 
				".res", 
				".obj",
				".o", 
				".lib",
				".o", 
		   		".a"
			};
			
	int sfxLens[10] = {0,4,4,3,4,4,2,4,2,2};
	
	// Borland provides lots of nice string
	// functions with their "standard" library
	// that don't exist under Linux.  The following
	// functions supply the missing code when
	// compiling HLA for Linux.
	
	// strlwr-	converts all upper case characters in the
	//			string passed as a parameter to lower case.
	//			Returns a pointer to the string you pass
	//			as a parameter.

	char *
	strlwr( char *str )
	_begin( strlwr )

		char *s = str;
		
		_while( *s != '\0' )
		
			*s = tolower( *s );
			++s;
			
		_endwhile
		_return str;
		
	_end( strlwr )



	// strupr-	Just like strlwr, except this function converts
	//			all lower case characters to upper case in the
	//			string.

	char *
	strupr( char *str )
	_begin( strupr )

		char *s = str;
		
		_while( *s != '\0' )
		
			*s = toupper( *s );
			++s;
			
		_endwhile
		_return str;
		
	_end( strupr )
	

#elif defined( windows_c )

	char	*sfxStrs[ 10 ] = 
			{ 
				".hla", 
				".hla", 
				".asm", 
				".rc", 
				".res", 
				".obj",
				".obj", 
				".lib",
				".obj", 
				".lib"
			};
			
	int sfxLens[10] = {0,4,4,3,4,4,4,4,4,4};
	
#else

	#error "Unknown host OS specified for compile"

#endif




 



 
 
static void
PressReturnToContinue(void)
_begin( PressReturnToContinue )

	int  i;
	char dummy[16];
	
	_if( MsgOut == stderr )
	
		fprintf( MsgOut, "\nPress the enter key to continue:" );
		fgets( dummy, 8, stdin );
		_for( i=0, i < 100, ++i )
		
			fprintf( MsgOut, "\n" );
			
		_endfor

	_endif
	
_end( PressReturnToContinue )



// Here's the message HLA.EXE displays if the user
// has a mal-formed command line parameter

static void
Usage( void )
_begin( Usage )

	fprintf
	(
		MsgOut,
		"Usage: hla options filename(s)\n"
		"\n"
		"HLA (High Level Assembler - %s back end, %s linker)\n"
		"%s\n"
		"\n"
		"  -?        Display help message.\n"
		"  -license  Display license information.\n",

		asmStrs[ SourceFmt ],
		linkStrs[ linker ],
		VersionInformation
	);

_end( Usage );


// Here's the message HLA.EXE displays if the user asks for
// help.

static void
Help( void )
_begin( Help )

	char inputline[32];

	fprintf
	(
		MsgOut,
		"Usage: hla options filename(s)\n"
		"\n"
		"HLA (High Level Assembler - %s back end, %s linker)\n"
		"%s\n"
		"\n"
		"Generic Options:\n"
		"  -license  Display license information.\n"
		"  -@        Do not generate linker response file.\n"
		"  -@@       Force generation of a new linker response file.\n"
		"  -dxx      Define VAL symbol xx to have type BOOLEAN and value TRUE.\n"
		"  -dxx=str  Defile VAL symbol xx to have type STRING and value str.\n"
		"  -sym      Dump symbol table after compile.\n"
		"  -test     Send diagnostic info to stdout rather than stderr.\n"
		"  -thread   Set @thread to true (for thread-safe code generation).\n"
		"  -v        Verbose compile (also sends output to stdout).\n"
		"  -?        Display this help message.\n"
		"\n"
		"Language Control:\n"
		"\n"
		"  -level=h  High-level assembly language.\n"
		"  -level=m  Medium-level assembly language.\n"
		"  -level=l  Low-level assembly language.\n"
		"  -level=v  Machine-level assembly language (very low level).\n",
		asmStrs[ SourceFmt ],
		linkStrs[ linker ],
		VersionInformation
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"Source Output Control:\n"
		"\n"
		"  -sourcemode Compile to source instructions (rather than hex opcodes)\n"
		"  -s          Compile to .ASM files only (using default ASM syntax).\n"
		"  -sh         Compile to pseudo-HLA source file. (implies sourcemode).\n"
		"  -sm         Compile to MASM source files only.\n"
		"  -sf         Compile to FASM source files only.\n"
		"  -sn         Compile to NASM source files only.\n"
		"  -st         Compile to TASM source files only.\n"
		"  -sg         Compile to GAS source files only.\n"
		"  -sx         Compile to GAS source files for Mac OSX only.\n"
		"  -code1st    Emit machine instructions before data in code segment.\n"
		"  -main:xxxx  Use 'xxxx' as the name of the HLA main program.\n"
		"\n"
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,	
		"HLAPARSE Compiler/Back-end Assembler Output Control:\n"
		"\n"
		"  -c        Compile and assemble to object file only.\n"
		"  -cf       Compile and assemble to object file only (using FASM).\n"
		"  -cn       Compile and assemble to object file only (using NASM).\n"
		"  -cm       Compile/assemble to object using MASM (Windows only).\n"
		"  -ct       Compile/assemble to object using TASM (Windows only).\n"
		"  -cg       Compile/assemble to object using GAS (Linux/FreeBSD only).\n"
		"  -cx       Compile/assemble to object using GAS (Mac only).\n"
		"  -co       Compile/assemble to object using internal FASM back-end (Win32).\n"
		"\n"
		"  -o:omf    Produce OMF files (for Windows).\n"
		"  -o:coff   Produce win32 COFF files (for Windows).\n"
		"  -o:elf    Produce ELF files (for Linux).\n"
		"\n"
		"  -axxxxx   Pass xxxxx as command line parameter to assembler.\n"
		
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"Executable Output Control:\n"
		"\n"
		"  -xf       Compile/assemble/link to executable (using FASM).\n"
		"  -xn       Compile/assemble/link to executable (using NASM).\n"
		"  -xm       Compile/assemble/link to object using MASM (Windows only).\n"
		"  -xt       Compile/assemble/link to object using TASM (Windows only).\n"
		"  -xg       Compile/assemble/link to object using GAS (Linux/FreeBSD only).\n"
		"  -xx       Compile/assemble/link to object using GAS (Mac only).\n"
		"  -xo       Compile/assemble/link to object internal FASM back-end (Windows only).\n"
		"\n"
		"  -win32    Generate code for Win32 OS.\n"
		"  -linux    Generate code for Linux OS.\n"
		"  -freebsd  Generate code for FreeBSD OS.\n"
		"  -macos    Generate code for Mac OSX.\n"
		"\n"
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"Linker Control:\n"
		"\n"
		"  -lxxxxx   Pass xxxxx as command line parameter to linker.\n"
		"  -e:name   Executable output filename "
							"(appends \".exe\" under Windows).\n"
		"  -x:name   "
			"Executable output filename (does not append \".exe\").\n"
		"  -b:name   Binary object file output filename.\n"
		"\n"
		#ifdef windows_c
			"  -m        Create a map file during link\n"
			"  -w        Compile as windows app (default is console app).\n"
			"  -polink   Force use of Pelles C linker/resource compiler.\n"
			"  -mslink   Force use of Microsoft linker/resource compiler.\n"
		#endif
			
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"Temporary file control and assembly control:\n"
		"\n"
		"  -p:path   Use <path> as the working directory for temporary files.\n"
		"            (overrides hlatmp environment variable.)\n"
		"\n"
		"  -r:name   <name> is a text file containing cmd line options.\n"
		"\n" 
		"  -obj:path Use <path> as the directory to hold the object files.\n"
		"\n"
		"  -i:path   Include path (used to override HLAINC "
		             "environment variable).\n"
		"\n"
	    "  -lib:path Library path (used to overide HLALIB "
					 "environment variable).\n"
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"HLA Environment Variables:\n\n"
		
		#ifdef windows_c
			
			"  hlalib=<path>        Sets path to hlalib.lib file \n"
			"                        (e.g., c:\\hla\\hlalib\\hlalib.lib)\n"
			"\n"
			"  hlainc=<path>        Sets path to HLA include subdirectory\n"
			"                         (e.g., c:\\hla\\include)\n"
			"\n"
			"  hlatmp=<path>        Sets path to directory to hold temp "
			                      "files (optional)\n"
								   
		#elif defined( UnixOS ) // Is Linux/BSD/MacOS, use Unix-friendly path:
			
			"  hlalib=<path>        Sets path to hlalib.lib file\n"
			"                         (e.g., /usr/hla/hlalib/hlalib.lib)\n"
			"\n"
			"  hlainc=<path>        Sets path to HLA include subdirectory\n"
			"                         (e.g., /usr/hla/include)\n"
			"\n"
			"  hlatmp=<path>        Sets path to directory to hold temp files\n"
								   
		#endif
			"\n"
		"  hlaasmopt=<options>  Passes the specified command-line options on to the\n"
		"                         underlying assembler.\n"
			"\n"
		"  hlalinkopt=<options> Passes the specified command-line options on to the\n"
		"                         underlying linker.\n"
	);
	PressReturnToContinue();	
	fprintf
	(
		MsgOut,
		"More HLA Environment Variables:\n\n"
		
		"hla=<asm>      Sets default assembler behavior\n"
		"                 <asm>:\n"
		"                    hla-  uses internal version of FASM\n"
		"                    ohla- uses internal version of FASM\n"
		"                    fhla- uses FASM as the back-end assembler\n"
		"                    nhla- uses NASM as the back-end assembler\n"
		"                   Windows Only:\n"
		"                    mhla- uses MASM as the back-end assembler\n"
		"                    thla- uses TASM as the back-end assembler\n"
		"                   Linux Only:\n"
		"                    ghla- uses GAS as the back-end assembler\n"
		"\n"
		"hlalink=<lnkr> Sets default linker behavior\n"
		"                 <lnkr>:\n"
		"                   Windows Only:\n"
		"                    mslink- use Microsoft's link.exe linker\n"
		"                    polink- use the Pelles C polink.exe linker\n"
		"                   Linux Only:\n"
		"                    ld- use the FSF/GNU ld linker\n"
		
	);

_end( Help )




static void
License( void )
_begin( License )

	fprintf
	(
		MsgOut,
		"\n\n\n"
		"*******************************************************\n"
		"*                                                     *\n"
		"*              HLA License Information                *\n"
		"*                                                     *\n"
		"*******************************************************\n"
		"\n\n"
		"The HLA system is built from many different components,\n"
		"each with its own separate end-user license. Because\n"
		"an end-user can mix and match the components that make\n"
		"up the HLA system, it is not possible to provide a single\n"
		"all-encompassing license for the entire HLA system. The\n"
		"following paragraphs will explain how to determine the\n"
		"specific license requirements for your particular HLA\n"
		"configuration.\n"
		"\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"The HLA shell program ('HLA.EXE' under Windows, 'hla'\n"
		"under other operating systems) is open source and public\n"
		"domain. You may do anything you like with this code,\n"
		"without restriction. Here is the official license code\n"
		"for HLA public domain components:\n"
		"\n"

"I, Randall Hyde, hereby agree to waive all claim of copyright (economic \n"
"and moral) in all content contributed by me, the user, and immediately	 \n"
"place any and all contributions by me into the public domain; I grant	 \n"
"anyone the right to use my work for any purpose, without any			 \n"
"conditions, to be changed or destroyed in any manner whatsoever		 \n"
"without any attribution or notice to the creator.  I also absolve myself\n"
"of any responsibility for the use of this code, the user assumes all	 \n"
"responsibilities for using this software in an appropriate manner.		 \n"
"																		 \n"
"Notice of declaration of public domain, 3/2/2007, by Randall Hyde		 \n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"The HLAPARSE compiler module contains public domain code\n"
		"written by Randall Hyde and freely distributable software\n"
		"written by Tomasz Grysztar. As such, this code inherits\n"
		"the FASM license, which is the following:\n"
		"\n"
"flat assembler	version 1.66\n"
"Copyright (c) 1999-2006, Tomasz Grysztar.\n"
"All rights reserved.\n"
"\n"
"This program is free for commercial and non-commercial use as long as \n"
"the following conditions are adhered to.							   \n"
"\n"
"(continued on next screen)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
"(FASM license continues...)\n\n"
"																	   \n"
"Copyright remains Tomasz Grysztar, and as such any Copyright notices  \n"
"in the code are not to be removed.									   \n"
"\n"
"Redistribution and use in source and binary forms, with or without	   \n"
"modification, are permitted provided that the following conditions are\n"
"met:																   \n"
"																	   \n"
"1. Redistributions of source code must retain the above copyright notice,\n"
"   this list of conditions and the following disclaimer.				\n"
"2. Redistributions in binary form must reproduce the above copyright	\n"
"   notice, this list of conditions and the following disclaimer in the	\n"
"   documentation and/or other materials provided with the distribution.\n"
"\n"
"(continued on next screen)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
"(FASM license, continues):\n\n"

"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND			 \n"
"CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES,	 \n"
"INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF		 \n"
"MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE		 \n"
"DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE	 \n"
"LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,			 \n"
"EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED \n"
"TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   \n"
"DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND	 \n"
"ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT		 \n"
"LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING	 \n"
"IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF	 \n"
"THE POSSIBILITY OF SUCH DAMAGE.\n"			  
"\n"
"(continued on next screen)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
"(FASM license continues...)\n\n"
"The licence and distribution terms for any publically available	 \n"
"version or derivative of this code cannot be changed. i.e. this code\n"
"cannot simply be copied and put under another distribution licence\n"
"(including the GNU Public Licence).\n"
"\n"
"(end of FASM license)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"If you use to use HLA in conjunction with MASM,\n"
		"the Microsoft Linker, and Microsoft's RC.EXE\n"
		"resource compiler, then the use of those tools\n"
		"is subject to the Microsoft end-user license\n"
		"agreement (EULA) that accompanies those products.\n"
		"As you are responsible for obtaining these products\n"
		"(they are not provided as part of the HLA package)\n"
		"you need to check the EULA that comes with the\n"
		"distribution of these products that you've obtained.\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"If you use to use HLA in conjunction with FSF's,\n"
		"GAS (as) and linker (ld) programs, then note\n"
		"that those products are licensed under the GPL\n"
		"(see the license text accompanying those products\n"
		"for details). Note that these products are separate\n"
		"applicatons in the HLA system and the fact that they\n"
		"are GPL in no way forces this license onto the rest\n"
		"of the HLA system. As you are responsible for obtaining\n"
		"copies of GAS and LD to use with HLA, please consult\n"
		"your source of these products for a copy of the GPL\n"
		"license. Note that the HLA distributions to not include\n"
		"any FSF GPL'd code. The HLA end-user is responsible\n"
		"for installing HLA in a system that already contains\n"
		"these GPL'd components.\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"If you use to use HLA in conjunction with the,\n"
		"the Pelle C tools (polink.exe and porc.exe)\n"
		"then the use of those particular tools is subject\n"
		"to the license agreement for the Pelles C system.\n"
		"That license applies only to polink.exe and porc.exe\n"
		"it does not apply to the rest of the HLA system.\n"
		"The Pelles C license is replicated here for your\n"
		"information. Note that the phrase 'applies to all\n"
		"parts except the C compiler' means that this license\n"
		"is what covers POLINK.EXE and PORC.EXE, the components\n"
		"that are part of the HLA system.  If the Pelles C\n"
		"compiler appears as part of the HLA download, it will\n"
		"also include a copy of the C compiler license, please\n"
		"see that license for details.\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		
"(Pelle C license for POLINK.EXE and PORC.EXE):\n\n" 
"The following license applies to all parts except the C \n"
"compiler (which is not part of the HLA system):\n"
"															 \n"
"This software is provided 'as-is', without any expressed or \n"
"implied warranty. In no event will the author be held liable\n"
"for any damages arising from the use of this software.		 \n"
"\n"
"(continued)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		
"Permission is granted to anyone to use this software for any\n"
"purpose, including commercial  applications, and to		 \n"
"redistribute it freely, subject to the following			 \n"
"restrictions:										 		 \n"
"															 \n"				 
"1. The origin of this software must not be misrepresented;  \n"
"   you must not claim that you wrote the original software.\n"
"2. Including Pelles C in a CDROM or in other products sold	 \n"
"   for profit needs explicit agreement from the author.	 \n"
"3. This notice may not be removed or altered from any		 \n"				 
"   distribution.											 \n"				 
"\n"
"Pelle Orinius\n"
"Stockholm, Sweden\n"
"\n"
"(end of Pelle license)\n"
	);
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"In general, there are no restrictions on HLA's output.\n"
		"The HLA standard library code is all public domain\n"
		"and the code emitted by the HLA compiler is totally\n"
		"free for any use. When using FASM, GAS, or TASM output\n"
		"there are no restrictions at all on the programs you\n"
		"create with HLA.  If you're using MASM as the back-end\n"
		"of the HLA system, be sure to check the EULA. There has\n"
		"been some discussion that the EULA forbids the creation\n"
		"of certain types of applications using MASM, and if\n"
		"you're using MASM with HLA, any restrictions in the\n"
		"MASM EULA would apply to the code processed by the\n"
		"HLA system when using MASM as a back end. Note that\n"
		"this declaration is not claiming such restrictions\n"
		"exist, only that you should check your MASM EULA\n"
		"if you have concerns.\n"
	);
		
	PressReturnToContinue();
	fprintf
	(
		MsgOut,
		"You can assume that all HLA sample programs written by\n"
		"Randall Hyde and distributed as part of the HLA system\n"
		"are public domain (governed by the public domain \n"
		"declaration given earlier). You are free to use those\n"
		"sample programs in part or in whole as you desire.\n"
		"The HLA Standard Library source code is also public\n"
		"domain and you may use that code in any manner you\n"
		"see fit.\n"
	);
		
_end( License )






/*
** getBaseName-
** Extracts the base name of a filename, without the leading
** path
*/

char*
getBaseName( char* name )
_begin( getBaseName )

	char 	*base;
	char	*rtn;
	
	base = strrchr( name, DIR_SEP_CHAR );
	_if( base == NULL )
	
		base = name - 1;
	
	_endif
	++base;
	rtn = strdup( base );
	assert( rtn != NULL );
	_return rtn;

_end( getBaseName )


/*
** getSuffix
**	Extracts the suffix from a filename if it is one of the following:
**
**	.hla
**	.asm
**	.rc
**	.res
**	.obj
*/

enum sfx
getSuffix( char *name )
_begin( getSuffix )

	char	*bn;
	int		length;
	

	length = strlen( name );
	_if( targetOS != windows_os )
	
		_if( length >= 3 )
		
			_returnif( stricmp( name + length - 2, ".a" ) == 0 ) a_c;
			_returnif( stricmp( name + length - 2, ".o" ) == 0 ) o_c;
			
		_endif
		
	_endif
	_returnif( length >= 4 && stricmp( name+length-3, ".rc" ) == 0 ) rc_c;
	
		
	_if( length >= 5 )
	
		_returnif( stricmp( name + length - 4, ".hla" ) == 0 ) hla_c;
		_returnif( stricmp( name + length - 4, ".asm" ) == 0 ) asm_c;
		_returnif( stricmp( name + length - 4, ".res" ) == 0 ) res_c;
		_returnif( stricmp( name + length - 4, ".obj" ) == 0 ) obj_c;
		_returnif( stricmp( name + length - 4, ".lib" ) == 0 ) lib_c;

	_endif
	_return null_c;
		
_end( getSuffix )





// Process the command line parameters here:

int
doCmdLine( int argc, char **argv )
_begin( doCmdLine)

	char 	*pgmName;
	int		nameLen;
	char	*namePosn;
	char	*hlaName;
	char	*linkerName;
	
	
	// Before doing anything else, scan the command line and see if there
	// is a "win32", "linux", "freebsd", or "macos" argument.
	
	_for( CurArg = 1, CurArg < argc, ++CurArg )
	
		_if( argv[ CurArg ][ 0 ] == '-' )

			strcpy( ucArg, &argv[ CurArg ][1] );
			strupr( ucArg );

			_if( _streq( ucArg, "WIN32" ))
			
				targetOS = windows_os;
				SourceFmt	= fasm;
				gasSyntax	= stdGas;
				ObjFmt 		= coff;
				linker 		= polink;
				Internal 	= 0;
				
			_elseif( _streq( ucArg, "LINUX" ))
			
				targetOS 	= linux_os;
				SourceFmt	= gas;
				gasSyntax	= stdGas;
				ObjFmt 		= elf;
				linker 		= ld;
				Internal 	= 0;
				
			_elseif( _streq( ucArg, "FREEBSD" ))
			
				targetOS 	= freeBSD_os;
				SourceFmt	= gas;
				gasSyntax	= stdGas;
				ObjFmt 		= elf;
				linker 		= ld;
				Internal 	= 0;
				
			_elseif( _streq( ucArg, "MACOS" ))
			
				targetOS 	= macOS_os;
				SourceFmt	= gas;
				gasSyntax	= macGas;
				ObjFmt 		= macho;
				linker 		= ld;
				Internal 	= 0;
				
			_endif
			
		_endif
								
	_endfor
	
	// Second, check the HLA environment variable. Default it to "HLA" if
	// it doesn't exist or if it is assigned an unknown value.
	
	hlaName = getenv( "hla" );
	_if( hlaName == NULL )
	
		hlaName = "HLA";	// Default to HLA.
		
	_endif
	hlaName = strupr( strdup( hlaName ));
	_if
	(
			_strne( hlaName, "MHLA" )
		&&	_strne( hlaName, "THLA" )
		&&	_strne( hlaName, "FHLA" )
		&&	_strne( hlaName, "GHLA" )
		&&	_strne( hlaName, "OHLA" )
		&&	_strne( hlaName, "NHLA" )
	)
	
		free( hlaName );
		hlaName = strdup( "HLA" );
		
	_endif
	
	// Now, check the HLALINK environment variable.
	
	linkerName = getenv( "hlalink" );
	_if( linkerName != NULL )
	
		linkerName = strupr( strdup( linkerName ));
		_if( _streq( linkerName, "MSLINK" ))
		
			_if( targetOS == windows_os )
			
				linker = mslink;

			_else
			
				fprintf
				(
					MsgOut,
					"'hlalink' environment variable is set to 'mslink', "
					"defaulting to ld\n"
				);
				linker = ld;
				free( linkerName );
				linkerName = NULL;
				
			_endif
			
		_elseif( _streq( linkerName, "POLINK" ))
		
			_if( targetOS == windows_os )
			
				linker = polink;

			_else
			
				fprintf
				(
					MsgOut,
					"'hlalink' environment variable is set to 'polink', "
					"defaulting to ld\n"
				);
				linker = ld;
				free( linkerName );
				linkerName = NULL;
				
			_endif
			
		_elseif( _streq( linkerName, "LD" ))
		
			_if( targetOS != windows_os )
		
				linker = ld;
				
			_else
			
				fprintf
				(
					MsgOut,
					"'hlalink' environment variable is set to 'ld' under " 
					"Windows,\n"
					"using default linker instead\n"
				);
				free( linkerName );
				linkerName = NULL;
				
			_endif
			
		_else
		
			fprintf
			( 
				MsgOut, 
				"Warning! Unknown linker specified by HLALINK "
				"environment variable\n" 
			);
			
		_endif
		
	_endif			
	
	
	// Get the program name and set the default language level as follows:
	//
	//	If name is		Default level is
	//	----------		----------------
	//    HLA			High Level (default case)
	//	  MLA			Medium Level
	//	  LLA			Low Level
	//	  VLLA			Very Low Level
	//
	//	  MHLA			High Level (default case)
	//	  THLA			High Level (default case)
	//	  FHLA			High Level (default case)
	//	  NHLA			High Level (default case)
	//    GHLA			High Level (default case)
	//
	// Of course, this can be overridden by the "-level=?" command-line parameter.
	//
	// The executable filename can also determine which back-end
	// assembler HLAPARSE will use.  This is set as follows:
	//
	//	If name is		Default back-end is
	//	----------		-------------------
	//    HLA			Determined by HLA environment variable
	//	  MLA			Determined by HLA environment variable
	//	  LLA			Determined by HLA environment variable
	//	  VLLA			Determined by HLA environment variable
	//	  MHLA			MASM
	//	  THLA			TASM
	//	  FHLA			FASM
	//    GHLA			GAS
	//    OHLA          FASM, producing object-code output.
	//
	// The back-end assembler designation can be overridden with the
	// "-s*" command-line option, though this will only produce a source
	// file that has to be manually assembled.
	//
	//
	//
	// Skip over any path prefix appearing in the name:
	
	namePosn = strrchr( argv[0], '/' );
	_if( namePosn == NULL )
	
		namePosn = strrchr( argv[0], '\\' );
		_if( namePosn == NULL )
		
			namePosn = argv[0];
			
		_else
		
			++namePosn;
			
		_endif
		
	_endif
	
	nameLen = strlen( namePosn );
	pgmName = malloc( nameLen + 1 );
	strcpy( pgmName, namePosn );
	strupr( pgmName );
	_if( strncmp( pgmName, "MLA", 3 ) == 0 )
	
		level = medium_level;
		
	_elseif( strncmp( pgmName, "VLLA", 4 ) == 0 )
	
		level = machine_level;
	
	_elseif( strncmp( pgmName, "LLA", 3 ) == 0 )
	
		level = low_level;
		
	_else // Not a level-specific name, check for back-end asm name
		
		level = high_level;
		_if( strncmp( pgmName, "HLA", 3 ) == 0 )
		
			// If the program name is "HLA", then either
			// use the HLA environment variable value or
			// use the default mode.
			
			free( pgmName );
			pgmName = strdup( hlaName );
			_if( _streq( pgmName, "HLA" ))
			
				// If the environment name is "HLA" (or defaults to this)
				// then we use the statically-defined defaults.
								
			_elseif( _streq( pgmName, "OHLA" ))
			
				// If the environment name is "OHLA" (internal FASM back-end)
				// then we use the internal version of FASM to produce an 
				// OBJ file.
				
				SourceFmt = fasm;
				Internal = 1;
				_if( targetOS == windows_os )
				
					ObjFmt = coff;
					_if( linkerName == NULL )
					
						linker = polink;
						
					_endif
					
				_else
				
					ObjFmt = elf;
					linker = ld;
					
				_endif
				
			_endif
			
		_endif
		_if( strncmp( pgmName, "MHLA", 4 ) == 0 )
		
			SourceFmt = masm;
			ObjFmt = coff;
			Internal = 0;
			_if( linkerName == NULL )
			
				linker = mslink;
				
			_endif
			
		_elseif( strncmp( pgmName, "THLA", 4 ) == 0 )
		
			SourceFmt = tasm;
			ObjFmt = omf;
			Internal = 0;
			_if( linkerName == NULL )
			
				linker = mslink;
				
			_endif
			
		_elseif( strncmp( pgmName, "FHLA", 4 ) == 0 )
		
			SourceFmt = fasm;
			ObjFmt = coff;
			Internal = 0;
			_if( linkerName == NULL )
			
				linker = polink;
				
			_endif
			
		_elseif( strncmp( pgmName, "NHLA", 4 ) == 0 )
		
			SourceFmt = nasm;
			ObjFmt = coff;
			Internal = 0;
			_if( linkerName == NULL )
			
				linker = polink;
				
			_endif
			
		_elseif( strncmp( pgmName, "GHLA", 4 ) == 0 )
		
			SourceFmt = gas;
			ObjFmt = elf;
			linker = ld;
			Internal = 0;
			
		_elseif( strncmp( pgmName, "OHLA", 4 ) == 0 )
		
			SourceFmt = fasm;
			Internal = 1;
			_if( targetOS == windows_os )
			
				ObjFmt = coff;
				_if( linkerName == NULL )
				
					linker = polink;
					
				_endif
			
			_else 
			
				ObjFmt = elf;
				linker = ld;
				
			_endif
			
		_endif
		
	_endif
	free( hlaName );
	free( pgmName );
	
	
	// Grab all the command line arguments from the command line
	// and pick up all the filenames, too.
	
	CurArg = 1;
	_while( CurArg < argc )

		// Determine if it's a command-line option or a filename
		
		_if( argv[ CurArg ][ 0 ] == '-' )

			strcpy( ucArg, &argv[ CurArg ][1] );
			strupr( ucArg );
			ThisArg = *ucArg;

			_if( _streq( ucArg, "LICENSE" ))
			
				License();
				_return 1;
				
			_elseif( _streq( ucArg, "THREAD" ))
			
				threadSafe = 1;
			
			// -level=h, -level=m, -level=l, and -level=v sets
			// the language mode.
			
			_elseif( _streq( ucArg, "LEVEL=H" ))
			
				level = high_level;
				
			_elseif( _streq( ucArg, "LEVEL=M" ))
			
				level = medium_level;
				
			_elseif( _streq( ucArg, "LEVEL=L" ))
			
				level = low_level;
				
			_elseif( _streq( ucArg, "LEVEL=V" ))
			
				level = machine_level;
				

			_elseif( _streq( ucArg, "@@" ))
			
				ResponseFile = 2;
				
			_elseif( ThisArg == '@' )

				ResponseFile = 0;
					 
			_elseif( ThisArg == 'A' )

				// Collect the "-Axx" command line to pass on to
				// the assembler:

				argv[ CurArg ][1] = '-';  // Overwrite 'A'.
				strcat( AsmOpts, &argv[CurArg][1] );
				strcat( AsmOpts, " " );

			// -C   selects "compile and assemble to object" (no link)
			//        using the default assembler.
			//
			// -CF  selects "compile and assemble to object" (no link)
			//        using FASM.
			//
			// -CM  selects "compile and assemble to object" (no link)
			//        using MASM.
			//
			// -CN  selects "compile and assemble to object" (no link)
			//        using NASM.
			//
			// -CT  selects "compile and assemble to object" (no link)
			//        using TASM.
			//
			// -CG  selects "compile and assemble to object" (no link)
			//        using GAS.
			//
			// -CO  selects "compile and assemble to coff object" (no link)
			//        using the internal version of FASM.

			_elseif( _streq( ucArg, "C" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx

			_elseif( _streq( ucArg, "CF" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = fasm;
				Internal = 0;
				_if( targetOS == windows_os )
				
					ObjFmt = coff;
				
				_else
				
					ObjFmt = elf;
					
				_endif
				

			_elseif( _streq( ucArg, "CM" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = masm;
				Internal = 0;

			_elseif( _streq( ucArg, "CN" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = nasm;
				Internal = 0;

			_elseif( _streq( ucArg, "CT" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = tasm;
				Internal = 0;
				ObjFmt = omf;
				

			_elseif( _streq( ucArg, "CG" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = gas;
				gasSyntax = stdGas;
				Internal = 0;
				ObjFmt = elf;

			_elseif( _streq( ucArg, "CX" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = gas;
				gasSyntax = macGas;
				Internal = 0;
				ObjFmt = macho;

			_elseif( _streq( ucArg, "CO" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 1;
				SourceOnly = 0;		// Mutually exclusive with -Sx
				SourceFmt = fasm;
				Internal = 1;
				_if( targetOS == windows_os )
				
					ObjFmt = coff;
				
				_else
				
					printf( "-co option is valid only under Windows\n" );
					Usage();
					_return 1;
				
				_endif
				
			_elseif( _streq( ucArg, "CODE1ST" ))
			
				codeFirst = 1;
				

			// -XF  selects "compile and assemble to object" (no link)
			//        using FASM.
			//
			// -XM  selects "compile and assemble to object" (no link)
			//        using MASM.
			//
			// -XT  selects "compile and assemble to object" (no link)
			//        using TASM.
			//
			// -XG  selects "compile and assemble to object" (no link)
			//        using GAS.
			//
			// -XO  selects "compile and assemble to coff object" (no link)
			//        using the internal version of FASM.
			

			_elseif( _streq( ucArg, "XF" ))
			
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = fasm;
				Internal = 0;
				_if( targetOS == windows_os )
				
					ObjFmt = coff;
					_if( linkerName == NULL )
					
						linker = polink;
						
					_endif
				
				_else
				
					ObjFmt = elf;
					linker = ld;
					
				_endif
				

			_elseif( _streq( ucArg, "XM" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = masm;
				ObjFmt = coff;
				Internal = 0;
				_if( linkerName == NULL )
				
					linker = mslink;
					
				_endif

			_elseif( _streq( ucArg, "XN" ))
			
				// Compile-only, no linking to executable
				
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = nasm;
				ObjFmt = coff;
				Internal = 0;
				_if( linkerName == NULL )
				
					linker = polink;
					
				_endif

			_elseif( _streq( ucArg, "XT" ))
			
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = tasm;
				Internal = 0;
				ObjFmt = omf;
				_if( linkerName == NULL )
				
					linker = mslink;
					
				_endif
				

			_elseif( _streq( ucArg, "XG" ))
			
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = gas;
				gasSyntax = stdGas;
				ObjFmt = elf;
				linker = ld;
				Internal = 0;

			_elseif( _streq( ucArg, "XX" ))
			
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = gas;
				gasSyntax = macGas;
				ObjFmt = macho;
				linker = ld;
				Internal = 0;

			_elseif( _streq( ucArg, "XO" ))
			
				CompileOnly = 0;
				SourceOnly = 0;
				SourceFmt = fasm;
				Internal = 1;
				_if( targetOS == windows_os )
				
					ObjFmt = coff;
					_if( linkerName == NULL )
					
						linker = polink;
						
					_endif
					
				_else
				
					printf( "-xo option is valid only under Windows\n" );
					Usage();
					_return 1;
				
				_endif

			
			// -S selects "assembly output only" (no assemble, no link)
			// -SM, -SG, -ST, -SF selects a particular assembler.
			
			_elseif( _streq( ucArg, "SOURCEMODE" ))
			
				sourceOutput = 1;
				
			_elseif( _streq( ucArg, "S" ))

				SourceOnly = 1;
				CompileOnly = 0;
				Internal = 0;

			_elseif( _streq( ucArg, "SH" ))

				SourceFmt = hla;		// pseudo-HLA source output
				SourceOnly = 1;
				sourceOutput = 1;		// Implied by -SH		
				CompileOnly = 0;
				Internal = 0;
			
			_elseif( _streq( ucArg, "SF" ))

				SourceFmt = fasm;		// FASM source output
				SourceOnly = 1;		
				CompileOnly = 0;
				Internal = 0;
			
			_elseif( _streq( ucArg, "SM" ))

				SourceFmt = masm;		// MASM source output
				SourceOnly = 1;		
				CompileOnly = 0;
				Internal = 0;

			_elseif( _streq( ucArg, "SN" ))

				SourceFmt = nasm;		// NASM source output
				SourceOnly = 1;		
				CompileOnly = 0;
				Internal = 0;

			_elseif( _streq( ucArg, "ST" ))

				SourceFmt = tasm;		// TASM source output
				SourceOnly = 1;
				CompileOnly = 0;
				Internal = 0;
				
			_elseif( _streq( ucArg, "SG" ))

				SourceFmt = gas;		// GNU's as source output
				gasSyntax = stdGas;
				SourceOnly = 1;
				CompileOnly = 0;
				Internal = 0;
				
			_elseif( _streq( ucArg, "SX" ))

				SourceFmt = gas;		// Mac/GNU's as source output
				gasSyntax = macGas;		// Use Mac OSX Gas syntax
				SourceOnly = 1;
				CompileOnly = 0;
				Internal = 0;
				
			// Check for one of the command-line parameters that
			// specify which linker to use:
			// -polink
			// -mslink
			
			_elseif( _streq( ucArg, "POLINK" ))

				linker = polink;				
				
			_elseif( _streq( ucArg, "MSLINK" ))

				linker = mslink;				
				
				
			// The following options select the object code output format:
			// (OMF, COFF/Win32, ELF/Linux/FreeBSD, MACHO/Mac):
			
			_elseif( _streq( ucArg, "O:OMF" ))

				ObjFmt = omf;
				Internal = 0;

			_elseif( _streq( ucArg, "O:COFF" ))

				ObjFmt = coff;

			_elseif( _streq( ucArg, "O:ELF" ))

				ObjFmt = elf;

			_elseif( _streq( ucArg, "O:MACHO" ))

				ObjFmt = macho;


				

			_elseif( ThisArg == 'D' )

				int		ValidID;
				char	*chrPtr;

				// Collect the "-Dxx{=str}" command line to pass on to
				// HLAParse:

				strcat( Defines, "\"" );
				strcat( Defines, argv[CurArg] );
				strcat( Defines, "\" " );


				// Validate that the text after "-D" is an HLA identifier.
				// HLA identifiers are alphanumeric and underscores.

				ValidID =
						( ucArg[1] >= 'A' && ucArg[1] <= 'Z' ) 
					||	ucArg[1] == '_';
					
				chrPtr = &ucArg[2];
				_while( *chrPtr != '\0' && *chrPtr != '=' )

					ValidID = 
							ValidID
						&&	(
									(
											*chrPtr >= 'A' 
										&&	*chrPtr <= 'Z'
									) 
								||	(
											*chrPtr >= '0' 
										&&	*chrPtr <= '9'
									) 
								|| *chrPtr == '_'
							);

					++chrPtr;

				_endwhile

				_if( !ValidID )

					printf
					( 
						"'-Dxxxx' option requres a valid ID after 'D' "
						"(<<%s>>)\n", 
						&ucArg[1] 
					);
					Usage();
					_return 1;

				_endif


			// The 'E' option lets the user select the executable filename:

			_elseif( strncmp( ucArg, "E:", 2 ) == 0 )

				ExeName = &argv[ CurArg ][3];

				
				// If the user did not tack ".EXE" onto the end of the
				// executable filename, do that here. (only under Windows)
			
				_if
				(		targetOS == windows_os 
					&&
						(
								strlen( ExeName ) < 4 
							||	stricmp
								(
									ExeName + strlen( ExeName ) - 4,
									".EXE"
								) != 0
						)
				)

					char *NewExeName;

					NewExeName = malloc( strlen( ExeName ) + 5 );
					assert( NewExeName != NULL );
					strcpy( NewExeName, ExeName );
					strcat( NewExeName, ".exe" );
					ExeName = NewExeName;

				_endif


			// The 'B' option lets the user select the binary object filename:

			_elseif( strncmp( ucArg, "B:", 2 ) == 0 )

				BinName = &argv[ CurArg ][3];

				
				// If the user did not tack ".OBJ" onto the end of the
				// executable filename, do that here. (only under Windows)
			
				_if
				(		targetOS == windows_os 
					&&
						(
								strlen( BinName ) < 4 
							||	stricmp
								(
									BinName + strlen( BinName ) - 4,
									".OBJ"
								) != 0
						)
				)

					char *NewBinName;

					NewBinName = malloc( strlen( BinName ) + 5 );
					assert( NewBinName != NULL );
					strcpy( NewBinName, BinName );
					strcat( NewBinName, ".obj" );
					BinName = NewBinName;

				// Under *nix, see if the user didn't put ".o" on the
				// end of the filename:
				
				_elseif
				(
						strlen( BinName ) < 4 
					||	stricmp
						(
							BinName + strlen( BinName ) - 4,
							".O"
						) != 0
				)

					char *NewBinName;

					NewBinName = malloc( strlen( BinName ) + 5 );
					assert( NewBinName != NULL );
					strcpy( NewBinName, BinName );
					strcat( NewBinName, ".o" );
					BinName = NewBinName;

				_endif
			

			// The 'X' option is really only for Windows, it lets the user 
			// select the executable filename without concatenating an
			// ".exe" to the end of the name:


			_elseif( strncmp( ucArg, "X:", 2 ) == 0 )

				ExeName = &argv[ CurArg ][3];
		

			// Check for the "-I:<path>" command line parameter
			// to specify the include path for header files.
			
			_elseif( strncmp( ucArg, "I:", 2 ) == 0 )
			
				int  lastPosn;
				char *newPath;
				char *incPath;
			
				incPath = &argv[ CurArg ][3];
				lastPosn = strlen( incPath ) - 1;
				_if( lastPosn > 0 )
				
					// Remove any trailing slash or backslash;  We'll
					// manually add this.
					
					_if
					( 
							incPath[ lastPosn ] == '\\' 
						||	incPath[ lastPosn ] == '/' 
					)
					
						incPath[ lastPosn ] = '\0';
						--lastPosn;
						
					_endif
					
					newPath = malloc( lastPosn + 10 );
					strcpy( newPath, "hlainc=" );
					strcpy( newPath+7, incPath );
					newPath[ lastPosn+8 ] = DIR_SEP_CHAR;
					newPath[ lastPosn+9 ] = '\0';
					putenv( newPath );
					
				_endif
				

			// Check for the "-LIB:<path>" command line parameter
			// to specify the include path for header files.
			
			_elseif( strncmp( ucArg, "LIB:", 4 ) == 0 )
			
				int  lastPosn;
				char *newPath;
				char *libPath;
			
				libPath = &argv[ CurArg ][5];
				lastPosn = strlen( libPath ) - 1;
				_if( lastPosn > 0 )
				
					// Remove any trailing slash or backslash
					
					_if
					( 
							libPath[ lastPosn ] == '\\' 
						||	libPath[ lastPosn ] == '/' 
					)
					
						libPath[ lastPosn ] = '\0';
						--lastPosn;
						
					_endif
					
					newPath = malloc( lastPosn + 10 );
					strcpy( newPath, "hlalib=" );
					strcpy( newPath+7, libPath );
					newPath[ lastPosn+8 ] = '\0';
					putenv( newPath );
					
				_endif
				
			// Check for the "-p:<path>" command line parameter
			// to specify the path for temporary files.
			
			_elseif( strncmp( ucArg, "P:", 2 ) == 0 )
			
				int  lastPosn;
				char *newPath;

				tempPath = &argv[ CurArg ][3];
				lastPosn = strlen( tempPath ) - 1;
				_if( lastPosn > 0 )
				
					// Remove any trailing slash or backslash;  HLAPARSE
					// will manually add this.
					
					_if
					( 
							tempPath[ lastPosn ] == '\\' 
						||	tempPath[ lastPosn ] == '/' 
					)
					
						tempPath[ lastPosn ] = '\0';
						--lastPosn;
						
					_endif
					
				_endif				

				
			// "-R:filename" tells HLA to read the command
			// line parameters from the specified response file.
			
			_elseif( strncmp( ucArg, "R:", 2 ) == 0 )
			
				int  localARGC;
				int  lineIndex;
				char *localARGV[256];
				char *tempPath;
				FILE *responseFile;
				char *cl;
				char curLine[256];
			
				tempPath = &argv[ CurArg ][3];
				
				responseFile = fopen( tempPath, "r" );
				_if( responseFile == NULL )
				
					printf
					( 
						"'-R:<filename> -- Could not open response file %s\n",
						tempPath
					);
					Usage();
					_return 1;
					
				_endif
				localARGC = 1;
				_while( fgets( curLine, 256, responseFile ) != NULL )
				
					// Strip trailing whitespace:
					
					lineIndex = strlen( curLine ) - 1;
					_while( curLine > 0 && isspace( curLine[ lineIndex ] ))
					
						--lineIndex;
						
					_endwhile
					curLine[ lineIndex + 1 ] = '\0';
					
					// Strip leading whitespace:
					
					cl = curLine;
					_while( isspace( *cl ))
					
						++cl;
						
					_endwhile;
					localARGV[ localARGC++ ] = strdup( cl );
					
					// Check for command line buffer overflow:
					
					_if( localARGC >= 256 )
						printf
						(
							"Too many commands in response file: %s\n",
							tempPath
						);
						Usage();
						_return 1;
					_endif
				
				_endwhile
				fclose( responseFile );
				_if( Verbose == 1 )
				
					int i;
					printf( "Response File:\n" );
					_for( i = 1, i<localARGC, ++i )
					
						printf( "%d: '%s'\n", i, localARGV[i] );
						
					_endfor
					
				_endif
				doCmdLine( localARGC, localARGV );
					

			// Check for the "-obj:<path>" command line parameter
			// to specify the path for object files.
						
			_elseif( strncmp( ucArg, "OBJ:", 4 ) == 0 )
			
				int  lastPosn;
				char *newPath;
			
				objPath = &argv[ CurArg ][5];
				lastPosn = strlen( objPath ) - 1;
				_if( lastPosn > 0 )
				
					// Remove any trailing slash or backslash;  HLAPARSE
					// will manually add this.
					
					_if
					( 
							objPath[ lastPosn ] == '\\' 
						||	objPath[ lastPosn ] == '/' 
					)
					
						objPath[ lastPosn ] = '\0';
						
					_endif
					
				_endif
				

					

					

			// Check for the "-main:<name>" command line parameter
			// to specify the HLA main program name.
						
			_elseif( strncmp( ucArg, "MAIN:", 5 ) == 0 )
			
				int  lastPosn;
				char *newPath;
			
				mainName = &argv[ CurArg ][6];				

					

			_elseif( ThisArg == 'L' )

				// Collect the "-Lxx" command line to pass on to
				// the linker:

				argv[ CurArg ][1] = '-';  // Overwrite 'L'.
				strcat( LinkOpts, &argv[CurArg][1] );
				strcat( LinkOpts, " " );

			
			// The "M" option tells MASM/TASM to generate a map file:

			_elseif( targetOS == windows_os && _streq( ucArg, "M" ))

				MapFile = 1;
				
			// -SYM tells HLA to dump the symbol table after a compile:
			
			_elseif( _streq( ucArg, "SYM" ))

					DumpSymbols = 1;


			// -TEST tells HLA to send all output to the standard
			// output device (rather than stderr) so we can capture
			// it for testing purpose.
			
			_elseif( _streq( ucArg, "TEST" ))

				MsgOut = stdout;
				IgnoreErrors = 1;
					

			// -V turns on verbose mode
			
			_elseif( ThisArg == 'V' )

				MsgOut = stdout;
				Verbose = 1;
				
				
			
			// -W tells the linker we're producing a Windows GUI app.
			
			_elseif( targetOS == windows_os && ThisArg == 'W' )
			
				WindowsApp = 1;
				

			// -? for a help message.
			
			_elseif( ThisArg == '?' )

				Help();
				_return 1;
				
			_elseif
			(
					_streq( ucArg, "WIN32" )
				||	_streq( ucArg, "LINUX" )
				||	_streq( ucArg, "FREEBSD" )
				||	_streq( ucArg, "MACOS" )
			)
			
				// Already processed these guys, so ignore them.
				
			
			_else
			
				fprintf
				(
					MsgOut,
					"Illegal command line option '%s'\n",
					argv[CurArg]
				);
				Usage();
				_return 1;
				
			_endif

		
		// If the current command line argument doesn't begin with "-"
		// then assume it is some sort of file name.  Filenames should take
		// one of five different forms:
		//
		//	name		HLA source file with default ".HLA" suffix.
		//	name.hla	HLA source file.
		//	name.asm	MASM source file.
		//	name.rc		Resource file.
		//	name.obj	Object code file.
		//	name.res	Compiled resource file.
		//	name.lib	Library file.
		//
		// Any other suffix is assumed to be a special case of the first
		// case above where "name" just happens to contain one or more
		// periods.
		

		_else

			#if defined( windows_c )
			
				int				appendPos;
				int				pathLen;
				int	 			length;
				int  			sufxPosn;
				enum sfx 		suffix;
				WIN32_FIND_DATA	wfd;
				HANDLE			wcIterator;
				char			*pPath;
				char			baseFileName[ MAX_PATH+1 ];
				char			pathName[ MAX_PATH+1 ];

				// The first step is to extract the path to the
				// file because FindFirst* won't return the full path.
				
				pPath = strrchr( argv[ CurArg ], '\\' );
				_if( pPath == NULL )
				
					pPath = strrchr( argv[ CurArg ], '/' );
					
				_endif
				pathLen = 0;
				appendPos = 0;
				_if( pPath != NULL )
				
					pathLen = pPath - argv[ CurArg ];
					pathLen = _ifx(pathLen < MAX_PATH, pathLen, MAX_PATH );
					strncpy( pathName, argv[ CurArg ], pathLen );
					appendPos = pathLen + 1;
					
				_endif 
				pathName[ pathLen ] = '\0';
				
				
				// Now, tack on a ".hla" if the filename does
				// not have a recognized suffix:
				
				strcpy( baseFileName, argv[ CurArg ] );
				suffix = getSuffix( baseFileName );
				_if( suffix == null_c )
				
					strncat( baseFileName, ".hla", MAX_PATH );
					baseFileName[ MAX_PATH ] = '\0';
					suffix = hla_c;
					
				_endif
				
				// Handle wildcards here:
				
				wcIterator = FindFirstFile( baseFileName, &wfd );
				_if( wcIterator != INVALID_HANDLE_VALUE )
				
					_do
				
						// Get the filename and create a set of filenames
						// for all the various programs from it.

						suffix = getSuffix( wfd.cFileName );
						Suffixes[ FileCnt ] = suffix;
						
						length = strlen( wfd.cFileName );
						sufxPosn = length - sfxLens[ suffix ];
						_if( (sufxPosn + pathLen + 2) > MAX_PATH )
						
							fprintf
							( 
								stderr, 
								"Path too long, assembly terminated: '%s/%s'\n",
								pathName,
								wfd.cFileName
							);
							exit(1);
							
						_endif
								
						FileList[ FileCnt ] = malloc( pathLen + sufxPosn + 2 );
						assert( FileList[ FileCnt ] != NULL );
						_if( pathLen != 0 )
						
							memcpy( FileList[ FileCnt ], pathName, pathLen );
							FileList[ FileCnt][pathLen ] = DIR_SEP_CHAR;
							
						_endif
						memcpy
						( 
							&FileList[ FileCnt][appendPos ], 
							wfd.cFileName, 
							sufxPosn 
						);
						FileList[ FileCnt ][ sufxPosn + appendPos ] = '\0';	
						++FileCnt;

					_until( !FindNextFile( wcIterator, &wfd ));
					FindClose( wcIterator );
					
				_else
				
					// If we didn't find the file, it might be a library
					// file whose path is specified by the LIB environment
					// variable. Just pass the name along as-is without
					// wildcard expansion.
					
					length = strlen( baseFileName );
					sufxPosn = length - sfxLens[ suffix ];
					Suffixes[ FileCnt ] = suffix;
					FileList[ FileCnt ] = malloc( sufxPosn + 1 );
					assert( FileList[ FileCnt ] != NULL );
					strncpy
					( 
						FileList[ FileCnt ], 
						baseFileName, 
						sufxPosn 
					);
					FileList[ FileCnt ][ sufxPosn ] = '\0';	
					++FileCnt;
					
					
				_endif
					
				
			#else
			
				int	 length;
				int  sufxPosn;
				enum sfx suffix;

				// Get the filename and create a set of filenames
				// for all the various programs from it.

				suffix = getSuffix( argv[ CurArg ] );
				Suffixes[ FileCnt ] = suffix;
				
				length = strlen( argv[ CurArg ] );
				sufxPosn = length - sfxLens[ suffix ];
				FileList[ FileCnt ] = malloc( sufxPosn + 1 );
				assert( FileList[ FileCnt ] != NULL );
				strncpy( FileList[ FileCnt ], argv[ CurArg ], sufxPosn );
				FileList[ FileCnt ][ sufxPosn ] = '\0';	
				++FileCnt;
			
			#endif
		 
		_endif
		++CurArg;

	_endwhile
	_return 0;

_end( doCmdLine)

// Here's the "shell" for the HLA compiler...

int
main( int argc, char *argv[] )
_begin( main )

	int		pathLen;
	int		rtnVal;
	char 	*startOfFullName;
	char	*envVar;
	char	*libVar;
	char	*linkerOptions;
	char	*backEndAsmOptions;
	char	*testHLAlib;
	char	*testHLAinc;
	char	*envResult;
	char	*hlaThreadSafe;
	char 	fullPath[4096];
	char	hlaPath[4096];
	char	hlalibPath[4096];
	char	libPath[4096];
	char	hlaincPath[4096];
	char	environment[4096];
	
	// If we enable RatC debugging, the following statements tell
	// RatC to write the execution log to the standard output rather
	// than a file:
	
	MsgOut = stderr;				/* Normally send all output to stderr	*/
	
	
	// HLA.EXE uses the following strings to supply command line parameters
	// to other programs.
	
	LinkName[0] = '\0';
	LinkOpts[0] = '\0';
	Defines[0] = '\0';
	AsmOpts[0] = '\0';

	
	// Better have at least one command line argument!
	
	
	_if( argc < 2 )
	
		Usage();
		_return 1;

	_endif

	
	// Process the command-line parameters:
	
	rtnVal = doCmdLine( argc, argv );
	_if( rtnVal != 0 )
	
		_return rtnVal;
		
	_endif
	
	// See if the "hlathreadsafe" environment variable is set to one.
	
	hlaThreadSafe = getenv( "hlathreadsafe" );
	threadSafe = 
			threadSafe 
		||	((hlaThreadSafe != NULL) && _streq( hlaThreadSafe, "1" ));
	
	// If the hlaasm or hlalink environment variables exist, grab their values
	// for use by the back-end assembler and linker.
	
	backEndAsmOptions = getenv( "hlaasmopt" );
	_if( backEndAsmOptions == NULL )
	
		backEndAsmOptions = "";
		
	_endif
	
	linkerOptions = getenv( "hlalinkopt" );
	_if( linkerOptions == NULL )
	
		linkerOptions = "";
		
	_endif
	
	
	// If the path to the hlalib.lib file is specified by the hlalib environment
	// variable, then copy it to hlalibPath, else set hlalibPath to the
	// empty string.
	
	hlalibPath[0] = '\0';
	_begin( getEnvPath )
	
		char *tmpPath;
		
		tmpPath = getenv( _ifx( threadSafe, "hlalib_safe", "hlalib" ) );
		_if( tmpPath != NULL )
		
			strcpy( hlalibPath, tmpPath );
			
		_endif
		
		// If the path to the hlainc directory is specified by the hlainc environment
		// variable, then copy it to hlaincPath, else set hlaincPath to the
		// empty string.
		
		hlaincPath[0] = '\0';
		tmpPath = getenv( "hlainc" );
		_if( tmpPath != NULL )
		
			strcpy( hlaincPath, tmpPath );
			
		_endif

	_end( getEnvPath )
	
	
	
	#ifdef windows_c
	
		/*
		** Under Windows, use the directory containing hlaparse.exe
		** as the base directory for the hlainc and hlalib directories
		** if the environment variables are undefined. This will
		** eliminate a lot of nagging installation problems with
		** beginning HLA users under Windows.
		*/

		startOfFullName = NULL;
		SearchPath
		(
			NULL,
			"hlaparse.exe",
			NULL,
			4000,
			fullPath,
			&startOfFullName
		);
		assert(	startOfFullName != NULL  );
		
		// Create a string with the path to the HLA.EXE file (that does
		// not include "\HLA.EXE" tacked on to the end of the string):
		
		pathLen = startOfFullName - fullPath;
		strncpy( hlaPath, fullPath, pathLen );
		hlaPath[ _ifx( pathLen > 0, pathLen-1, 0 ) ] = '\0'; 
		
		// Okay, let's see if we can find ...\hlalib\hlalib.lib.
		// Note that hlalibPath is *not* the empty string if
		// we found the hlalib environment variable.
		
		_if( hlalibPath[0] == '\0' )  

			// There is no HLALIB environment variable set.
			// First, let's see if we can find the hlalib
			// directory in the same directory that contained
			// hla.exe:
			
			strcpy( hlalibPath, hlaPath );
			strcat
			( 
				hlalibPath, 
				_ifx
				( 
					threadSafe, 
					"\\hlalib\\hlalib_safe.lib", 
					"\\hlalib\\hlalib.lib" 
				) 
			);
			rtnVal = GetFileAttributes( hlalibPath );
			_if( rtnVal == -1 )
			
				// Couldn't find hlalib\hlalib.lib in the same
				// directory holding HLA.EXE, so try "C:\HLA\HLALIB\HLALIB.LIB"
				
				strcpy
				( 
					hlalibPath, 
					_ifx
					(
						threadSafe,
						"c:\\hla\\hlalib\\hlalib_safe.lib",
						"c:\\hla\\hlalib\\hlalib.lib" 
					)
				);
				rtnVal = GetFileAttributes( hlalibPath );
				_if( rtnVal == -1 )
				
					// We can't find the HLALIB directory (and the hlalib.lib
					// file), so print a descriptive error message and bail.
					
					fprintf
					( 
						stderr, 
						"ERROR! Could not locate the HLALIB.LIB file.\n"
						"Have you set the HLALIB environment variable properly?\n"
					);
					_return( 1 );
					
				_endif
					
			_endif

			strcpy( environment, "hlalib=" );
			strcat( environment, hlalibPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_endif
		
		
		// Process the LIB environment variable (used by the linker to
		// find, among other things, the hlalib.lib file).
		//
		// Begin by taking "hlalib.lib" (or whatever filename appears)
		// off the end of the hlalibPath string because the LIB environment
		// variable only wants a path, not including the filename:
		
		strcpy( libPath, hlalibPath );
		testHLAlib = strrchr( libPath, '\\' );
		_if( testHLAlib != NULL )
		
			*testHLAlib = '\0';
			
		_endif
		
		// Okay, append libPath to the end of the LIB environment variable string:
		
		libVar = getenv( "lib" );
		_if( libVar != NULL && *libVar != '\0' )
		
			// If the LIB environment variable exists, tack on the
			// path to hlalib.lib so the linker can find hlalib.lib.
			// If "x:\...\hlalib\hlalib.lib" already appears at the
			// end of the LIB environment variable, we'll tack another
			// copy to the end; oh well, that won't hurt anything.
			
			assert( strlen( libVar ) < 4000 );
			strcpy( environment, "lib=" );
			strcat( environment, libVar );
			strcat( environment, ";" );
			strcat( environment, libPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_else
		
			// If there is no LIB environment variable, create one:
			
			strcpy( environment, "lib=" );
			strcat( environment, libPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_endif
				
		// Okay, let's see if we can find ...\include
		// Note that hlaincPath is *not* the empty string if
		// we found the hlainc environment variable earlier.
		
		_if( hlaincPath[0] == '\0' )  

			// There is no HLAINC environment variable set.
			// First, let's see if we can find the include
			// directory in the same directory that contained
			// hla.exe:
			
			strcpy( hlaincPath, hlaPath );
			strcat( hlaincPath, "\\include" );
			rtnVal = GetFileAttributes( hlaincPath );
			_if( rtnVal == -1 )
			
				// Couldn't find include in the same
				// directory holding HLA.EXE, so try "C:\HLA\INCLUDE"
				
				strcpy( hlaincPath, "C:\\HLA\\INCLUDE" );
				rtnVal = GetFileAttributes( hlaincPath );
				_if( rtnVal == -1 )
				
					// We can't find the include directory , so print a 
					// descriptive error message and bail.
					
					fprintf
					( 
						stderr, 
						"ERROR! Could not locate the HLA INCLUDE directory.\n"
						"Have you set the HLAINC environment variable properly?\n"
					);
					_return( 1 );
					
				_endif
					
			_endif

			strcpy( environment, "hlainc=" );
			strcat( environment, hlaincPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_endif
		
	#else
	{
		struct stat statbuf;
		int 		handle;
		
		// If Linux, FreeBSD, macOS, or some other Unix-based OS,
		// then use "/usr/hla" as the default base directory for
		// find the include and library directories.

		// Okay, let's see if we can find ...\hlalib\hlalib.lib.
		// Note that hlalibPath is *not* the empty string if
		// we found the hlalib environment variable.
		
		_if( hlalibPath[0] == '\0' )  

			// There is no HLALIB environment variable set.
			// First, let's see if we can find the hlalib
			// directory in /usr/hla
			
			strcpy
			( 
				hlalibPath, 
				_ifx
				(
					threadSafe,
					"/usr/hla/hlalib/hlalib_safe.a",
					"/usr/hla/hlalib/hlalib.a"
				) 
			);
			rtnVal = stat( hlalibPath, &statbuf );
			_if( rtnVal == -1 )
			
				// We can't find the HLALIB directory (and the hlalib.lib
				// file), so print a descriptive error message and bail.
				
				fprintf
				( 
					stderr, 
					"ERROR! Could not locate the HLALIB.A file.\n"
					"Have you set the HLALIB environment variable properly?\n"
				);
				_return( 1 );
					
					
			_endif

			strcpy( environment, "hlalib=" );
			strcat( environment, hlalibPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_endif
		
		// Okay, let's see if we can find .../include
		// Note that hlaincPath is *not* the empty string if
		// we found the hlainc environment variable earlier.
		
		_if( hlaincPath[0] == '\0' )  

			// There is no HLAINC environment variable set.
			// First, let's see if we can find the include
			// directory in /usr/hla
			
			strcpy( hlaincPath, "/usr/hla/include" );
			rtnVal = stat( hlaincPath, &statbuf );
			_if( rtnVal == -1 )
			
				// We can't find the include directory , so print a 
				// descriptive error message and bail.
				
				fprintf
				( 
					stderr, 
					"ERROR! Could not locate the HLA INCLUDE directory.\n"
					"Have you set the HLAINC environment variable properly?\n"
				);
				_return( 1 );
					
					
			_endif

			strcpy( environment, "hlainc=" );
			strcat( environment, hlaincPath );
			envResult = strdup( environment );
			assert( envResult != NULL );
			putenv( envResult );
			
		_endif
	}	
	#endif

	// Note: if tempPath is non-NULL, that means that it was set
	// from the command line and we don't want to change it here.
	
	_if( tempPath == NULL )
	
		tempPath = getenv( "hlatmp" );	/* Path for temporary files				*/
		_if( tempPath == NULL )
		
			// If no temporary path environment variable, 
			// default to nothing under Linux, default to
			// the program's path under Windows:
			
			tempPath = "";
				
			
		_elseif( tempPath[ strlen( tempPath ) - 1]  == DIR_SEP_CHAR )
		
			// Remove the backslash at the end of the temp path if one is
			// present.
			
			tempPath[ strlen( tempPath ) - 1] = '\0';
			
		_endif
		
	_endif
	
	
	// Do some sanity checks before trying to compile the program:
	
	_if
	( 
			ObjFmt == coff
		&& 	SourceFmt != masm 
		&&	SourceFmt != fasm
		&&	SourceFmt != nasm
		&&	!SourceOnly 
	)
	
		fprintf
		(
			MsgOut,
			"\n"
			"***************************************************************\n"
			"Warning: COFF output is only available when using MASM or FASM.\n"
			"***************************************************************\n"
			"\n"
		);
		_if( SourceFmt == gas )
		
			ObjFmt = elf;
			
		_elseif( SourceFmt == tasm )
		
			ObjFmt = omf;
			
		_endif
		
	_endif
	 

	_if
	( 
			ObjFmt == elf
		&& 	SourceFmt != gas 
		&&	SourceFmt != fasm 
		&&	!SourceOnly
	)
	
		fprintf
		(
			MsgOut,
			"\n"
			"*************************************************************\n"
			"Warning: ELF output is only available when using GAS or FASM.\n"
			"*************************************************************\n"
			"\n"
		);
		_if( SourceFmt == masm )
		
			ObjFmt = coff;
			
		_elseif( SourceFmt == tasm )
		
			ObjFmt = omf;
			
		_endif
		
	_endif
	
	 

	_if
	( 
			ObjFmt == macho
		&& 	SourceFmt != gas 
		&&	!SourceOnly
	)
	
		fprintf
		(
			MsgOut,
			"\n"
			"*******************************************************\n"
			"Warning: MACHO output is only available when using GAS.\n"
			"*******************************************************\n"
			"\n"
		);
		_if( SourceFmt == masm )
		
			ObjFmt = coff;
			
		_elseif( SourceFmt == tasm )
		
			ObjFmt = omf;
			
		_endif
		
	_endif
	
	_if
	(
			(
					SourceFmt == masm
				||	SourceFmt == tasm
			)
		&&	!SourceOnly
		&&	targetOS != windows_os
	)
	
		fprintf
		(
			MsgOut,
			"\n"
			"*************************************************************\n"
			"Warning: MASM/TASM assembly is only available under Windows.\n"
			"*************************************************************\n"
			"\n"
		);
		SourceOnly = 1;
		CompileOnly = 0;
		
	_endif
	
	_if
	(
			SourceFmt == gas
		&&	!SourceOnly
		&&	targetOS == windows_os
	)
	
		fprintf
		(
			MsgOut,
			"\n"
			"*************************************************************\n"
			"Warning: GAS assembly is not available under Windows.\n"
			"*************************************************************\n"
			"\n"
		);
		SourceOnly = 1;
		CompileOnly = 0;
		
	_endif
	 



	
	// If verbose mode was specified, echo all the command line
	// values (primarily to test the command line argument processor).
	

	_if( Verbose )

		fprintf
		(
			MsgOut,
			"HLA (High Level Assembler)\n"
			"Use '-license' to see licensing information.\n"
			"Version %s\n"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s"
			"%s%s%s"
			"%s%s%s"
			"\n",
			VersionInformation,

			_ifx
			( 
				ResponseFile==0, 
				"-@ active\n",
				_ifx( ResponseFile == 2, "-@@ active\n", ""	)
			),

			_ifx( CompileOnly, "-c active\n", "" ),
			_ifx
			( 
				ObjFmt == coff, 
				"Win32 COFF output\n", 
				_ifx
				(
					ObjFmt == omf,
					"OMF output\n",
					_ifx
					(
						ObjFmt == elf,
						"ELF output\n",
						_ifx
						(
							ObjFmt == macho,
							"Mach-O output\n",						
							"Illegal object code format!\n"
						)
					 )
				)
			),

			_ifx( MapFile, "-M (mapfile) active\n", "" ),
			_ifx( threadSafe, "-thread active\n", "" ),
			_ifx( SourceOnly, "-sXX active\n", "" ),
			_ifx
			(
				SourceFmt == masm,
				"MASM output\n",
				_ifx
				(
					SourceFmt == tasm,
					"TASM output\n",
					_ifx
					(
						SourceFmt == gas,
						_ifx
						( 
							gasSyntax == macGas, 
							"GAS output for Mac OSX\n", 
							"GAS output\n"
						),
						_ifx
						(
							Internal,
							"OBJ output using internal FASM back-end\n",
							_ifx
							(
								SourceFmt == fasm,
								"FASM output\n",
								_ifx
								(
									SourceFmt == nasm,
									"NASM output\n",
									"??? assembler output (?)\n"
								)
							)
						)
					)
				)
			),
			_ifx( WindowsApp, "-w active\n", "" ),
			_ifx( DumpSymbols, "-SYM active\n", "" ),
			_ifx( MsgOut == stdout, "-test active\n", "" ),
			_ifx( ExeName != NULL, "-e:<name> active (", "" ),
			_ifx( ExeName != NULL, ExeName, "" ),
			_ifx( ExeName != NULL, ")\n", "" ),
			_ifx( BinName != NULL, "-b:<name> active (", "" ),
			_ifx( BinName != NULL, BinName, "" ),
			_ifx( BinName != NULL, ")\n", "" ),
			_ifx
			( 
				tempPath != NULL && *tempPath != '\0', 
				"-p:<path> active (", 
				"" 
			),
			_ifx( tempPath != NULL && *tempPath != '\0', tempPath, "" ),
			_ifx( tempPath != NULL && *tempPath != '\0', ")\n", "" ),			
			_ifx
			( 
				objPath != NULL && *objPath != '\0', 
				"-obj:<path> active (", 
				"" 
			),
			_ifx( objPath != NULL && *objPath != '\0', objPath, "" ),
			_ifx( objPath != NULL && *objPath != '\0', ")\n", "" )			
		);


		envVar = getenv( "hlalib" );
		assert( envVar != NULL );
		fprintf( MsgOut, "HLA Lib Path:     %s\n", envVar );
		envVar = getenv( "hlainc" );
		assert( envVar != NULL );
		fprintf( MsgOut, "HLA include path: %s\n", envVar );
		assert( tempPath != NULL );
		fprintf( MsgOut, "HLA temp path:    %s\n", tempPath );
		envVar = getenv( "lib" );
		_if( envVar != NULL )
		
			fprintf( MsgOut, "Linker Lib Path:  %s\n\n", envVar );
		
		_endif
		fprintf( MsgOut, "Files:\n" );
		_for( int i=0, i < FileCnt, ++i )

			assert( FileList[i] != NULL && sfxStrs[ Suffixes[i]] != NULL );
			fprintf
			(
				MsgOut,
				"%d: %s%s\n",
				i + 1,
				FileList[ i ],
				sfxStrs[ Suffixes[i] ]
			);

		_endfor
		fprintf( MsgOut, "\n" );

	_endif

	
	// If the user didn't specify any filenames, quit at this point.
	

	_if( FileCnt <= 0 )

		fprintf
		(
			MsgOut,
			"Nothing more to do!\n"
		);
		Usage();
		_return 1;

	_endif
	
	
	
	// If there was no executable name specified, create one by using
	// the first filename specified on the command line.
	

	_if( ExeName == NULL )

		assert( FileList[0] != NULL );
		ExeName = malloc( strlen( FileList[0] ) + 5 );
		assert( ExeName != NULL );
		strcpy( ExeName, FileList[ 0 ] );
		
		_if( targetOS == windows_os )
		
			// Windows executable files end with ".exe":
			
			strcat( ExeName, ".exe" );
						
		_endif

	_endif


	



	
	// Okay, run the HLA compiler on each of the ".HLA" files.
	

	_for( int HlaFile=0, HlaFile < FileCnt, ++HlaFile )

		// Okay, start the compiler up here.

		Suffix =   Suffixes[ HlaFile ];
		_if( Suffix == hla_c || Suffix == null_c )

			char *asmBaseName;
			
			assert( FileList[ HlaFile ] != NULL );
			strcpy( HlaName, FileList[ HlaFile ] );
			strcat( HlaName, ".hla" );
			
			// If the -P:tempPath option was used to specify a temporary
			// output path for ASM files, then strip the base filename
			// and concatenate it with the temporary path, otherwise
			// use the full path specified by the current command-line file
			// argument.
			//
			// Note that this only applies to compilations that use an
			// external assembler (i.e., it does not apply when using
			// the internal version of FASM).
			
			_if( !Internal )
			
				_if( tempPath != NULL && *tempPath != '\0' )
				
					asmBaseName = getBaseName( FileList[ HlaFile ]  );
					assert( asmBaseName != NULL );
					strcpy( AsmName, asmBaseName );
					free( asmBaseName );

				_else
				
					strcpy( AsmName, FileList[ HlaFile ] );			
				
				_endif
				strcat( AsmName, ".asm" );
				
			_else
			
				AsmName[0] = '\0';
				_if( objPath != NULL && strlen( objPath ) > 0 )
				
					strcpy( AsmName, objPath );
					strcat( AsmName, DIR_SEP_STR );
					
				_endif
				asmBaseName = getBaseName( FileList[ HlaFile ]  );
				assert( asmBaseName != NULL );
				strcat( AsmName, asmBaseName );
				free( asmBaseName );
				strcat( AsmName, _ifx( targetOS == windows_os, ".obj", ".o" ));
			
			_endif
			
			// Okay, process the source file
			// Start by building a command line for HLAPARSE
			// (the actual HLA compiler) and submitting that
			// command line.
			
			sprintf
			(
				hlaCmdLn,
				"hlaparse -%s %s %s %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\"%s\"",
				_ifx( targetOS == windows_os, "WIN32",
					_ifx( targetOS == linux_os, "LINUX",
						_ifx( targetOS == freeBSD_os, "FREEBSD",
							_ifx( targetOS == macOS_os, "MACOS", "WIN32" )
						)
					)
				),
				levelStrs[level],
				Defines,
				_ifx( tempPath != NULL && *tempPath != '\0', "-p\"", ""),
				_ifx( tempPath != NULL && *tempPath != '\0', tempPath, ""),
				_ifx( tempPath != NULL && *tempPath != '\0', "\" ", ""),
				_ifx( Verbose, "-v ", "" ),
				_ifx( threadSafe, "-thread ", "" ),
				_ifx( DumpSymbols, "-sym ", "" ),
				_ifx
				( 
					ResponseFile==0, 
					"-@ ",
					_ifx( ResponseFile == 2, "-@@ ", "" ) 
				),
				_ifx( sourceOutput, "-source ", "" ),
				_ifx
				( 
					SourceFmt == masm, 
					"-sm ",
					_ifx
					(
						SourceFmt == tasm,
						"-st ", 
						_ifx
						( 
							SourceFmt == gas, 
							_ifx( gasSyntax == macGas, "-sx ", "-sg "), 
							_ifx
							(
								SourceFmt == fasm,
								"-sf ",
								_ifx
								(
									SourceFmt == nasm,
									"-sn ",
									_ifx
									(
										SourceFmt == hla,
										"-sh ",
										""
									)
								)
							)
						)
					)
				),
				_ifx( codeFirst, "-code1st ", "" ),
				_ifx( mainName != NULL, "-main:", "" ),
				_ifx( mainName != NULL, mainName, "" ),
				_ifx( mainName != NULL, " ", "" ),
				_ifx( Internal, "-c", "" ),
				_ifx( Internal, objStrs[ ObjFmt ], "" ),
				_ifx( Internal, " ", "" ),
				_ifx( objPath != NULL && strlen( objPath ) > 0, "-obj:\"", "" ),
				_ifx( objPath != NULL && strlen( objPath ) > 0, objPath, "" ),
				_ifx( objPath != NULL && strlen( objPath ) > 0, "\" ", "" ),
				_ifx( MsgOut == stdout, "-test ", "" ),
				HlaName
			);

			_if( Verbose )

				fprintf
				(
					MsgOut,
					"Compiling '%s' to '%s'\n"
					"using command line:\n"
					"[%s]\n\n"
					"----------------------\n",
					HlaName,
					AsmName,
					hlaCmdLn
				);

			_endif

			hlaErr = system( hlaCmdLn );
			_returnif( hlaErr != 0 ) hlaErr;
			
			_if( Verbose )

				fprintf
				(
					MsgOut,
					"----------------------\n"
				);

			_endif


			
			// The compliation may have produced a ".link" file, save
			// its name for later use, but only for the first filename
			// on the command line:
			
			_if( LinkName[0] == '\0' )
			
				_if( tempPath != NULL && *tempPath != '\0' )
				
					baseName = getBaseName( FileList[ HlaFile ]  );
					strcpy( LinkName, tempPath );
					strcat( LinkName, DIR_SEP_STR );
					strcat( LinkName, baseName );
					free( baseName );

				_else
				
					strcpy( LinkName, FileList[ HlaFile ] );			
				
				_endif
				strcat( LinkName, ".link" );

			_endif

			
			
			// Finally, since we just converted the current
			// ".hla" file to an assembly language file, change
			// the suffix in the FileList array.
			

			_if( hlaErr == 0 )

				_if( !Internal )
				
					Suffixes[ HlaFile ] = asm_c;
					
				_else
				
					Suffixes[ HlaFile ] = fobj_c;
					
				_endif

			_else

				++TotalErrors;

			_endif

		_endif

	_endfor



	
	// At this point, we've finished compiling all the ".hla" files.
	// Quit if there were any errors.
	// Quit if the user specified one of the "-sXX" flags.
	// Otherwise, assemble the ".asm"/".s" files using the 
	// appropriate assembler.
	

	_returnif( TotalErrors != 0 ) !IgnoreErrors;
	_returnif( SourceOnly ) 0;
	
	// If the targetOS is not equal to the host OS, then stop
	// at this point because it doesn't make sense to try and
	// compile the .asm files on the host OS.
	
	_returnif( hostOS != targetOS ) 0;


	// For each of the ".asm" files, produce an object file.
		
	_if( !Internal )
	
		MLResult = 0;
		_for( HlaFile=0, HlaFile < FileCnt, ++HlaFile )

			// If the -P:tempPath option was used to
			// specify a temporary output path, then
			// strip the base filename off and create
			// a path to the file in the temporary directory:
			
			baseName = getBaseName( FileList[ HlaFile ]  );
			assert( baseName != NULL );
			_if( tempPath != NULL && *tempPath != '\0' )
			
				strcpy( AsmName, tempPath );
				strcat( AsmName, DIR_SEP_STR );
				strcat( AsmName, baseName );

			_else
			
				strcpy( AsmName, FileList[ HlaFile ] );			
			
			_endif
			strcat( AsmName, ".asm" );		
			_if( Suffixes[ HlaFile ] == asm_c )

				_if( objPath != NULL && *objPath != '\0' )
				
					strcpy( ObjName, objPath );
					strcat( ObjName, DIR_SEP_STR );
					strcat( ObjName, baseName );
					
					// Shove this name back into FileList because
					// we can't differentiate between .OBJ files we
					// produce and those that were produced by another
					// tool (and may not be in the objpath directory)
					// later on:
					
					free( FileList[ HlaFile ] );
					FileList[ HlaFile ] = strdup( ObjName );
					assert( FileList[ HlaFile ] != NULL );

				_else
				
					strcpy( ObjName, FileList[ HlaFile ] );			
				
				_endif
				_switch( targetOS )
				
					_case( windows_os )
				
						strcat( ObjName, ".obj" );
						
					_endcase
					
					_case( linux_os )
					_case( freeBSD_os )
					_case( macOS_os )

						strcat( ObjName, ".o" );
						
					_endcase
					
					_default
					
						// Probably ought to issue a warning here...
						
						strcat( ObjName, ".o" );
						
				_endswitch
				

				_if( SourceFmt == masm )

					sprintf
					(
						CmdLine, 
						"ml /c %s /Cp /Fo\"%s\" %s %s %s \"%s\"",
						_ifx( ObjFmt == coff, "/coff", ""),
						ObjName,
						_ifx( !Verbose, "/nologo", "" ),
						AsmOpts,
						backEndAsmOptions,
						AsmName
					);

				_elseif( SourceFmt == tasm )

					sprintf
					(
						CmdLine, 
						"tasm32 /mx /m9 %s %s %s \"%s\", \"%s\"",
						_ifx( !Verbose, "/t", "" ),
						AsmOpts,
						backEndAsmOptions,
						AsmName,
						ObjName
					);

				_elseif( SourceFmt == fasm )

					sprintf
					(
						CmdLine, 
						"fasm \"%s\" \"%s\"",
						AsmName,
						ObjName
					);
						

				_elseif( SourceFmt == nasm )

					sprintf
					(
						CmdLine, 
						"nasm -fwin32 -Ox -o \"%s\" \"%s\"",
						ObjName,
						AsmName
					);
						

				_elseif( SourceFmt == gas )

					_if( gasSyntax == macGas )
					
						// On the mac, we need to run CPP first
						// to handle any back-patches that
						// generated #define statements.
						
						sprintf
						(
							CmdLine,
							"cpp --traditional-cpp \"%s\" \"%s.s\"; " 
							"as -arch i386 -o %s %s %s \"%s.s\"",
							AsmName,
							AsmName,
							ObjName,
							AsmOpts,
							backEndAsmOptions,
							AsmName
						);
					
					_else
					
						sprintf
						(
							CmdLine, 
							"as --32 -o %s %s %s \"%s\"",
							ObjName,
							AsmOpts,
							backEndAsmOptions,
							AsmName
						);
						
					_endif

				_endif

				_if( Verbose )

					fprintf
					(
						MsgOut,
						"\n"
						"Assembling \"%s\" to \"%s\" via [%s]\n",
						AsmName,
						ObjName,
						CmdLine
					);
				
				_endif

				
				// Note if there were any errors reported by the Assembler.

				CurMLResult = system( CmdLine );
				MLResult += CurMLResult;
					
				// If the assembly was successful, change the name
				// of the file so that it is now an ".obj" file.
				

				_if( CurMLResult == 0 )

					Suffixes[ HlaFile ] = obj_c;
					
					// If we don't have a .LINK file name yet,
					// create one from the assembly name.
					
					_if( LinkName[0] == '\0' )
					
						_if( tempPath != NULL && *tempPath != '\0' )
						
							strcpy( LinkName, tempPath );
							strcat( LinkName, DIR_SEP_STR );
							strcat( LinkName, baseName );

						_else
						
							strcpy( LinkName, FileList[ HlaFile ] );			
						
						_endif
						strcat( LinkName, ".link" );

					_endif

				_endif

			_endif
			free( baseName );

		_endfor

		// If an error occurred during assembly, it's time to quit.
		

		_if( MLResult != 0 ) 

			fprintf
			(
				MsgOut,
				"Error returned by Assembler = %d\n",
				MLResult
			);
			_return MLResult;

		_endif
		
	_else	// We used the internal version of FASM to create an OBJ file.
	
		_for( HlaFile=0, HlaFile < FileCnt, ++HlaFile )

			baseName = getBaseName( FileList[ HlaFile ]  );
			assert( baseName != NULL );
			_if( Suffixes[ HlaFile ] == fobj_c )

				_if( objPath != NULL && *objPath != '\0' )
				
					strcpy( ObjName, objPath );
					strcat( ObjName, DIR_SEP_STR );
					strcat( ObjName, baseName );
					
					// Shove this name back into FileList because
					// we can't differentiate between .OBJ files we
					// produce and those that were produced by another
					// tool (and may not be in the objpath directory)
					// later on:
					
					free( FileList[ HlaFile ] );
					FileList[ HlaFile ] = strdup( ObjName );
					assert( FileList[ HlaFile ] != NULL );

				_else
				
					strcpy( ObjName, FileList[ HlaFile ] );			
				
				_endif
				strcat( ObjName, sfxStrs[ fobj_c ] );
				
				// If we don't have a .LINK file name yet,
				// create one from the assembly name.
				
				_if( LinkName[0] == '\0' )
				
					_if( tempPath != NULL && *tempPath != '\0' )
					
						strcpy( LinkName, tempPath );
						strcat( LinkName, DIR_SEP_STR );
						strcat( LinkName, baseName );

					_else
					
						strcpy( LinkName, FileList[ HlaFile ] );			
					
					_endif
					strcat( LinkName, ".link" );

				_endif

			_endif
			free( baseName );

		_endfor

	_endif
		

	


	
	// At this point, we've finished assembling all the ".asm" files.
	// If there are any resource files, compile them with RC.EXE.
	

	#ifdef windows_c
	
		MLResult = 0;
		_for( int HlaFile=0, HlaFile < FileCnt, ++HlaFile )

			_if( Suffixes[ HlaFile ] == rc_c )
			
				_if( linker == mslink )
				
					sprintf
					(
						CmdLine,
						"rc \"%s.rc\"",
						FileList[ HlaFile ]
					);
					
				_else
				
					sprintf
					(
						CmdLine,
						"porc \"%s.rc\"",
						FileList[ HlaFile ]
					);
				
				_endif
				_if( Verbose )

					fprintf
					(
						MsgOut,
						"\n"
						"Compiling resource %s.rc via [%s]\n",
						FileList[ HlaFile ],
						CmdLine
					);
				
				_endif

				
				// Note if there were any errors reported by RC.EXE.
				

				CurMLResult = system( CmdLine );
				MLResult += CurMLResult;

				
				// If the compilation was successful, change the name
				// of the file so that it is now an ".res" file.
				

				_if( CurMLResult == 0 )

					Suffixes[ HlaFile ] = res_c;

				_endif

			_endif

		_endfor

		
		// If an error occurred during resource compilation, it's time to quit.

		_if( MLResult != 0 ) 

			_if( linker == polink )

				fprintf
				(
					MsgOut,
					"Error returned by "
					"PORC.EXE = %d\n",
					MLResult
				);
				
			_else
			
				fprintf
				(
					MsgOut,
					"Error returned by "
					"RC.EXE = %d\n",
					MLResult
				);
				
			_endif
			_return MLResult;

		_endif
		
	#endif


	
	// Okay, assuming the "-c" flag wasn't specified,
	// link all the modules together.  Note: only run
	// the linker with the standard assembly output
	// (Currently, the standard assembler is MASM, so
	// only run MS' LINK.EXE if we used the MASM assembler).
	

	_if( CompileOnly ) 
	
		// At some point, consider adding the code to delete
		// the leftover .asm and .inc files here.  I'm too
		// chicken to do this just yet because I've not thought
		// through the ramifications.
	
		_return 0;
		
	_endif


	
	#ifdef unixOS
	
		includeLib[0] = '\0';
		
		// See if the link file exists:
		
		_if( LinkName[0] != '\0' )
		
			FILE *linkFile;
			
			// Read each line and create a command-line
			// string from them.
			
			linkFile = fopen( LinkName, "r" );
			_if( linkFile != NULL )
			
				int len;
				int lfLen;
			
				lfLen = 0; 
				_while( !feof( linkFile ))
				
					fgets( ilInput, 1024, linkFile );
					len = strlen( ilInput );
					_if( lfLen + len < 4090 )
					
						strcat( includeLib, "\"" );
						strcat( includeLib, ilInput );
						strcat( includeLib, "\" " );
						lfLen += len + 3;
						
					_endif
				
				_endwhile
			
			_endif
			
		_endif
	
		_if( linker != ld )
		
			fprintf
			( 
				MsgOut, 
				"Attempted to specify linker %s under %s, must use ld\n",
				linkStrs[ linker ],
				OSName
			);
			
		_endif
		sprintf
		( 
			CmdLine, 
			"ld %s %s %s  -o \"%s\" %s \0",
			_ifx( gasSyntax == macGas, "-arch i386", "" ),
			linkerOptions,
			LinkOpts,
			ExeName,
			includeLib
		);
			
		
		
		// Okay, append all the ".o" and ".a" names to the end
		// of the command line we're building. (Put the .o files
		// first and the .a files last.)
		

		_for( int i=0, i < FileCnt, ++i )

			_if
			( 
					Suffixes[ i ] == obj_c 
				||	Suffixes[ i ] == o_c
				||	Suffixes[ i ] == fobj_c 
			)
			
				strcat( CmdLine, " \"" );
				strcat( CmdLine, FileList[ i ] );			
				strcat( CmdLine, ".o\"" );
				
			_endif

		_endfor
		
		_for( int i=0, i < FileCnt, ++i )

			_if( Suffixes[ i ] == lib_c || Suffixes[ i ] == a_c  )
			
				strcat( CmdLine, " \"" );
				strcat( CmdLine, FileList[ i ] );
				strcat( CmdLine, ".a\"" );
				
			_endif

		_endfor
		
		
		// If we've got an "hlalib" environment variable, add it to the
		// end of the string:
		
		
		_if( hlalibPath[0] != '\0' )
		
			sprintf( CmdLine + strlen( CmdLine ), " \"%s\"", hlalibPath );

		_endif
		
		// Execute the command.
	
		_if( Verbose )

			fprintf( MsgOut, "Linking via [%s]\n", CmdLine );

		_endif
		MLResult = system( CmdLine );
		_if( MLResult != 0 ) 
		
			fprintf
			(
				MsgOut,
				"Error returned by ld = %d\n",
				MLResult
			);
			_return MLResult;

		_endif
	
	#else // Running under Windows: 
	{
		FILE	*linkFile;
		FILE	*newLinkFile;
		
		char	line[ 256 ];
		
		char	*lo = LinkOpts;
		char	newLinkName[256];
		char	*baseName;
		
		_if( LinkName[0] == '\0' )
		
			_if( tempPath != NULL && *tempPath != '\0' )
			
				baseName = getBaseName( FileList[ 0 ] );
				strcpy( LinkName, tempPath );
				strcat( LinkName, DIR_SEP_STR );
				strcat( LinkName, baseName );
				free( baseName );

			_else
			
				strcpy( LinkName, FileList[ 0 ] );			
			
			_endif
			strcat( LinkName, ".link" );

		_endif		
		strcpy( newLinkName, LinkName );
		strcat( newLinkName, "._.link" );
		newLinkFile = fopen( newLinkName, "w" );
		_if( newLinkName == NULL )
		
			printf( "Could not create file '%s' for linking\n", newLinkName );
			_return 1;
			
		_endif
		
		linkFile = fopen( LinkName, "r" );
		_if( linkFile != NULL )
		
			_while( fgets( line, 255, linkFile ) != 0 )
				
				fprintf( newLinkFile, "%s", line );
				
			_endwhile;
			fclose( linkFile );
															  
		_else
			
			printf( "Could not open file '%s' for linking\n", LinkName );
			_return 1;
			
		_endif 
		
		
		fprintf
		( 
			newLinkFile, 
			"%s\n", 
			_ifx( WindowsApp, "-subsystem:windows", "-subsystem:console" )
		);
		
		_if( linker == mslink )
		
			_if( !Verbose )
			
				fprintf( newLinkFile, "-nologo\n");
				
			_endif
			
		_endif
		
		_if( MapFile )
		
			fprintf( newLinkFile, "-map\n");
		
		_endif
		
		// Copy the link options specified on the command line
		// to the .link file:
		
		_while( *lo != '\0' );
		
			_while( *lo != ' ' && *lo != '\0' )
			
				fprintf( newLinkFile, "%c", *lo );
				++lo;
			
			_endwhile;
			fprintf( newLinkFile, "\n" );
			_while( *lo == ' ' )
			
				++lo;
			
			_endwhile
			
		_endwhile;
		
		lo = linkerOptions;
		_while( *lo != '\0' );
		
			_while( *lo != ' ' && *lo != '\0' )
			
				fprintf( newLinkFile, "%c", *lo );
				++lo;
			
			_endwhile;
			fprintf( newLinkFile, "\n" );
			_while( *lo == ' ' )
			
				++lo;
			
			_endwhile
			
		_endwhile;
		
		fprintf( newLinkFile, "-out:%s\n", ExeName );
		fprintf
		(
			newLinkFile,
			"%s\n", 
			hlalibPath
		);		

		
		// Okay, append all the ".obj", ".res", and ".lib" names to the end
		// of the response we're building.
		
		_for( int i=0, i < FileCnt, ++i )
		
			strcpy( line, FileList[i] );
			_if( Suffixes[ i ] == obj_c || Suffixes[ i ] == fobj_c )
			
				strcat( line, ".obj" );
				
			_elseif( Suffixes[i] == res_c )
			
				strcat( line, ".res" );
				
			_elseif( Suffixes[i] == lib_c )
			
				strcat( line, ".lib" );
				
			_endif
			fprintf( newLinkFile, "%s\n", line );

		_endfor
		fclose( newLinkFile );
		
		// Execute the command.
		
		_if( linker == polink )
		
			sprintf( line, polinker " @\"%s\"", newLinkName );
			
		_else
		
			sprintf( line, mslinker " @\"%s\"", newLinkName );
			
		_endif
		
		_if( Verbose )
		
			printf( "Linking via [%s]\n", line );
			
		_endif
		
		MLResult = system( line );
		
		sprintf( line, "del \"%s\"", newLinkName );
		system( line );
			
		_if( MLResult != 0 ) 
		
			fprintf
			(
				MsgOut,
				"Error returned by %s = %d\n",
				linkStrs[ linker ],
				MLResult
			);
			_return MLResult;

		_endif
	}		
	#endif
	_return 0;

_end( main )
