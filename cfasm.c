// cFASM support code
//
// Module that allows FASM to be called as a C function.

#include "debug.h"

#ifdef DEBUGFUNCS
#define PathLogging
/*#define TestStmtCoverage*/
#define LogFuncCalls
#endif


#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <time.h>
#include <errno.h>


// #defines that control the type of FUNCS we produce:
//
// By default, we produce a version for Windows:

#define windows_c
#undef  unix
#if defined(linux_c) || defined( freeBSD_c ) || defined( macOS_c )

 #undef  windows_c
 #define unix
 
#endif


#ifdef windows_c

	#include <windows.h>
	#include <winbase.h>
	#include <io.h>
	
#else

	#define O_BINARY 0

#endif


#include "common.h"
#include "ratc.h"


// External names take different forms based on whether we're
// compiling under Windows (where most C compilers expect an
// "_" in front of external names) 

#ifdef noUnderscoresInExterns_c

	#define	fasmMain 						_fasmMain
	#define c_newln  						_c_newln
	#define c_putc							_c_putc				   
	#define c_puts							_c_puts
	#define c_putu32						_c_putu32
	#define c_puth32						_c_puth32
	#define c_putbuf						_c_putbuf
	#define c_malloc						_c_malloc
	#define fasm_exitProcess				_fasm_exitProcess		   
	#define fasm_curDateTime				_fasm_curDateTime
	#define fasm_readFileIntoMemory			_fasm_readFileIntoMemory
	#define fasm_getenv						_fasm_getenv
	#define	fasm_get_environment_variable	_fasm_get_environment_variable
	#define fasm_exists						_fasm_exists
	#define fasm_open						_fasm_open
	#define fasm_create						_fasm_create
	#define	fasm_write						_fasm_write
	#define	fasm_read						_fasm_read
	#define fasm_close						_fasm_close
	#define	fasm_seek						_fasm_seek
	#define fasm_mseek						_fasm_mseek
	#define fasm_rseek						_fasm_rseek
	
#endif


static char 	*g_fName;
static char 	*g_objName;
static void 	*g_fileBuf;
static int 	 	 g_fileSize;


// Extern linkage to the FASM object module:

extern void fasmMain
( 
	char	*fName,
	char	*outName,
	void	*memory,
	int		memsize,
	int		passes,
	int		verbose
);

// external linkage to HLAPARSE:

void cfasmMain
( 
	char *fName, 
	char *objName, 
	void *fileBuf, 
	int fileSize, 
	int verbose 
);




//////////////////////////////////////////////////////////////////////////
//
// The following are the support functions that the C program must provide
// for the fasmMain object module. The stand-alone version of hFASM uses
// the HLA standard library to achieve portability across OSes. However,
// as there is the possibility of inherent conflicts between the HLA
// stdlib and the C stdlib, for the object-module version of hFASM,
// absolutely no HLA stdlib calls are made. The following functions provide
// most of the functionality that hFASM needs from the HLA stdlib.

extern void c_newln( void ); 				   
extern void c_putc( char c );				   
extern void c_puts( char *s );				   
extern void c_putu32( long u );			   
extern void c_puth32( long d );  			   
extern void c_putbuf( void *buf, long size );
extern void *c_malloc( long size );
		   
extern void fasm_exitProcess( int rtnCode );


extern void fasm_curDateTime
	(
		unsigned	*month,
		unsigned	*day,
		unsigned	*year,
		unsigned	*hour,
		unsigned	*min,
		unsigned	*sec
	);
		
extern void *fasm_readFileIntoMemory( char *filename, size_t *size );

extern char *fasm_getenv( char *envname );
extern char *fasm_get_environment_variable( char *envVarName );

extern int  fasm_exists( char *filename );
extern int  fasm_open( char *filename );
extern int  fasm_create( char *filename );
extern int  fasm_write( int handle, void *buffer, unsigned len );
extern int  fasm_read( int handle, void *buffer, unsigned len );
extern int  fasm_close( int handle );

extern long fasm_seek( int handle, long posn );
extern long fasm_mseek( int handle, long posn );
extern long fasm_rseek( int handle, long posn );



// Write a newline sequence in whatever form the local OS expects:

void c_newln( void )
_begin( c_newln )

	putc( '\n', stdout );

_end( c_newln )



// Write a single character to the standard output device:
						
void c_putc( char c )
_begin( c_putc )

	putc( c, stdout );

_end( c_putc )



// Write a zstring to the stdout:
						
void c_puts( char *s )
_begin( c_puts )

	printf( s );

_end( c_puts )


// Write a 32-bit unsigned integer to the stdout:
					
void c_putu32( long u )
_begin( c_putu32 )

	printf( "%u", u );

_end( c_putu32 )


// Write a 32-bit unsigned integer as an 8-digit hexadecimal
// string to the stdout:
					
void c_puth32( long d )
_begin( c_puth32 )

	printf( "%08x", d );

_end( c_puth32 )

  					

// Write a buffer of the specified length to the stdout:

void c_putbuf( void *buf, long size )
_begin( c_putbuf )

	fwrite( buf, size, 1, stdout );

_end( c_putbuf )

		

// fasm_exists-
// Returns true/false if a file exists/does not exist

int fasm_exists( char *filename )
_begin( fasm_exists )

	int result;
	
	result = open( filename, O_RDONLY, 0);
	close( result );
	_return result != -1;

_end( fasm_exists )



// fasm_open-
//
//	Opens a file using the specified filename and returns
//  a file handle as the function result. File must exist
//  and is opened for reading, else an error gets returned (-1)

int fasm_open( char *filename )
_begin( fasm_open )

	_return open( filename, O_RDONLY | O_BINARY, S_IREAD );

_end( fasm_open )



// fasm_create-
//
//	Opens a new file (deleting any old file) for writing
//	and returns a file handle to that file (-1 if error).

int fasm_create( char *filename )
_begin( fasm_create )

	_return 
		open
		( 
			filename, 
			O_RDWR | O_BINARY | O_TRUNC | O_CREAT, 
			S_IREAD | S_IWRITE 
		);

_end( fasm_create )



// fasm_write-
//
//	Write a block of bytes to the specified file handle.

int  fasm_write( int handle, void *buffer, unsigned len )
_begin( fasm_write )

	_return write( handle, buffer, len );

_end( fasm_write )



// fasm_read-
//
//	Reads a block of bytes from the specified file handle.

int  fasm_read( int handle, void *buffer, unsigned len )
_begin( fasm_read )

	_return read( handle, buffer, len );

_end( fasm_read )




// fasm_close-
//
//	Closes the specified file handle.

int  fasm_close( int handle )
_begin( fasm_close )

	_return close( handle );

_end( fasm_close )



// fasm_seek,
// fasm_rseek,
// fasm_mseek-
//
//	Seeks to various points in a file.

long fasm_seek( int handle, long posn )
_begin( fasm_seek )

	int result= lseek( handle, posn, SEEK_SET );
	_if( result == -1 )

		int err=errno;
		printf( "errno=%d, badfh=%d, invalid=%d illseek=%d\n",
		err, EBADF, EINVAL, ESPIPE);
	
	_endif
	_return result;

_end( fasm_seek )




long fasm_mseek( int handle, long posn )
_begin( fasm_mseek )

	_return lseek( handle, posn, SEEK_CUR );

_end( fasm_mseek )


long fasm_rseek( int handle, long posn )
_begin( fasm_rseek )

	int result= lseek( handle, posn, SEEK_END );
	_if( result == -1 )

		int err=errno;
		printf( "errno=%d, badfh=%d, invalid=%d illseek=%d\n",
		err, EBADF, EINVAL, ESPIPE);
	
	_endif
	_return result;

_end( fasm_rseek )


// fasm_readFileIntoMemory-
//
//	Opens a file, determines its length, allocates sufficient storage
//	(plus a few extra bytes for extra info at the end of the file),
//	and then reads the entire file into memory. Returns a pointer to
//	the file, also stores the length of the file in the size parameter
//	(which is passed by reference).
//
//	Returns a NULL pointer if it could not open or read the file.
//
//  TODO: The memory is never freed. For a single call to fasmMain,
//	this is no big deal. But if the C code decides to make multiple
//	calls to fasmMain, it should keep a list of files read by this
//	routine and free up the storage between calls to fasmMain.

void *fasm_readFileIntoMemory( char *filename, size_t *size )
_begin( fasm_readFileIntoMemory )

	void *result;
	int handle;
	int errCode;
	struct stat statbuf;
	
	// If FASM is asking for the main file, just pass along the
	// buffer that HLAPARSE created:
	
	_if( _streq( filename, g_fName ))
	
		result = g_fileBuf;
		*size = g_fileSize;
			
	_else
	
		// Must be an include file. HLA doesn't actually
		// produce any includes, but stick this here just
		// in case.
	
		handle = stat( filename, &statbuf );
		_returnif( handle == -1 ) (void *) -1;	
		*size = statbuf.st_size;
		
		handle = open( filename, O_RDONLY | O_BINARY, S_IREAD );
		_returnif( handle < 0 ) (void *) -1;
		
		result = malloc2( statbuf.st_size + 16 );
		_if( result == NULL )

			close( handle );
			_return result;
		
		_endif
		
		errCode = read( handle, result, statbuf.st_size );
		close( handle );
		_returnif( errCode == -1 ) (void *)-1;
		
	_endif
	_return result;	

_end( fasm_readFileIntoMemory )




// fasm_exitProcess-
//
//	Gets called if the assembler has to abort processing.

void fasm_exitProcess( int rtnCode )
_begin( fasm_exitProcess )

	exit( rtnCode );

_end( fasm_exitProcess )




// fasm_getenv-
//
//	Reads an environment variable, allocates storage for that
//	variable's value, copies the value to the storage, and then
//	returns a pointer to the newly allocated storage.

char *fasm_getenv( char *envname )
_begin( fasm_getenv )

	char *envVal;
	char *rtnVal;
	
	envVal = getenv( envname );
	_if( envVal != NULL )

		rtnVal = malloc2( strlen( envVal ) + 2 );
		assert( rtnVal != NULL );
		strcpy( rtnVal, envVal );
		_return rtnVal;
	
	_endif
	
	rtnVal = malloc2( 2 );
	*rtnVal = '\0';
	_return rtnVal;

_end( fasm_getenv )

	


// fasm_curDateTime-
//
//	Gets a GMT date/time value from the system, converts
//	it to m/d/y h:m:s format, and returns those values
//	to the caller (used for setting time stamps in object
//  files).

void fasm_curDateTime
(
	unsigned	*month,
	unsigned	*day,
	unsigned	*year,
	unsigned	*hour,
	unsigned	*min,
	unsigned	*sec
)
_begin( fasm_curDateTime )

	time_t curTime;
	struct tm *dateTime;
	
	curTime = time( &curTime );
	dateTime = gmtime( &curTime );
	*month = dateTime->tm_mon;
	*day   = dateTime->tm_mday;
	*year  = dateTime->tm_year+1900;
	*hour  = dateTime->tm_hour;
	*min   = dateTime->tm_min;
	*sec   = dateTime->tm_sec;

_end( fasm_curDateTime )




void
cfasmMain
( 
	char *fName, 
	char *objName, 
	void *fileBuf, 
	int fileSize,
	int verbose 
)
_begin( cfasmMain )

	void *mem;
	
	g_fName = fName;
	g_objName = objName;
	g_fileBuf = fileBuf;
	g_fileSize = fileSize;
		
	mem = malloc2( 64*1024*1024 );
	fasmMain
	( 
		fName,			// char	*fName,
		objName,		// char	*outName,
		mem,			// void	*memory,
		64*1024*1024, 	// int	memsize,
		1000,			// passes
		verbose
	);
	free2( vss mem ); 

_end( cfasmMain )
