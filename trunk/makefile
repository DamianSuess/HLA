# make				-- generates HLA compiler
# make version		-- updates HLA version number
# make lib			-- Builds the HLA Standard Library
# make clean		-- deletes unnecessary OBJ and EXE files.
# make cln			-- Cleans up the compiler only.

INC=-Ic:\bc5\include
LIBR=-Lc:\bc5\lib
RATC=ratc.h
DBG=debug.h
ENM=enums.h
CMN=common.h
AH=asm.h
OUT=output.h
SYM=symbol.h

#DB=-v -y -M
DB=

hla:  hlaparse.exe hla.exe 
	build

hla.exe: hla.obj 
	bcc32 $(DB) -N -K -5 -O2 $(INC) $(LIBR) hla.obj
	copy hla.exe ..\..\executables 
	copy hla.exe ..\.. 

hla.obj: hla.c $(RATC) $(DBG)
	bcc32 $(DB) -d -N -K -w-rch- -5 -O2 $(INC) $(LIBR) -c hla.c

hlaparse.exe: hlaparse.obj lex.yy.obj symbol.obj hlautils.obj \
				output.obj oututils.obj coerce.obj funcs.obj  \
				cfasm.obj hlaasm.obj hfasm.obj
	bcc32 -lS:0x10000000 -lSc:0x400000  $(DB) @hla.bcc
	build
	copy hlaparse.exe ..\..\executables
	copy hlaparse.exe ..\..

hlaparse.obj: hlaparse.c $(SYM) $(RATC) $(CMN) $(ENM) $(DBG) $(OUT)
	 bcc32 $(DB) -d -N -K -w-rch- -5 -O2 $(INC) $(LIBR) -c hlaparse.c


hlaasm.obj: hladev\hlaasm.hla
	cd hladev
	make hlaasm.masm
	make hlaasm.gas
	make hlaasm.gasx
	cd ..

hfasm.obj: hladev\hfasm.hla
	cd hladev
	make hfasm.masm
	make hfasm.gas
	cd ..
	____



hlaparse.c: hlaparse.bsn
	c:\cygwin\bin\bison -d -o hlaparse.c hlaparse.bsn
	____
	
lex.yy.obj: hla.flx hlaparse.c $(DBG) $(AH)
	flex -8 -i hla.flx
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c lex.yy.c

symbol.obj: symbol.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c symbol.c

hlautils.obj: hlautils.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c hlautils.c

output.obj: output.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c output.c

oututils.obj: oututils.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c oututils.c

coerce.obj: coerce.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c coerce.c

funcs.obj: funcs.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c funcs.c

cfasm.obj: cfasm.c $(SYM) $(CMN) $(RATC) $(DBG) $(ENM) $(AH)
	bcc32 $(DB) -d -N -K -5 -w-rch- -O2 $(INC) $(LIBR) -c cfasm.c



version:
	delete hla.exe
	delete mhla.exe
	delete fhla.exe
	delete thla.exe
	delete ohla.exe
	delete ghla.exe
	delete hlaparse.exe
	delete *.obj
	delete *.obj
	delete hla.exe
	delete hlaparse.exe
	version

clean:
	delete *.exe
	delete *.obj
	delete *.asm
	delete *.bak
	delete *.link
	delete *.inc
	delete *.map
	delete lex.yy.c
	delete hlaparse.c
	delete hlaparse.tab.c
	delete *.pdb
	delete *.ilk
	delete hlaparse.output
	delete tmp\*
	cd hladev
	make clean
	cd ..


