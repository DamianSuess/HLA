
all: hlaasm.masm hlaasm.gas hlaasm.gasx 

hlaasm.masm:	
	hla -sourcemode -sm hlaasm.hla
	copy hlaasm.asm ..\hlaasm.masm
	ml -c -coff -Cp hlaasm.asm
	copy hlaasm.obj ..\hlaasm.obj
	
	
hlaasm.gas:
	hla -sourcemode -sg -dunix hlaasm.hla
	copy hlaasm.asm ..\hlaasm.gas
	
	
hlaasm.gasx:
	hla -sourcemode -sx -dmacosx hlaasm.hla
	copy hlaasm.asm ..\hlaasm.gasx
	
	
hlabe.masm: hlabe.hla hlabe.hhf
	hla -sourcemode -sm hlabe
	copy hlabe.asm ..\hlabe.masm
	ml -c -coff -Cp hlabe.asm
	copy hlabe.obj ..\hlabe.obj
	
	
hlabe.gas: hlabe.hla hlabe.hhf
	hla -sourcemode -sg hlabe
	copy hlabe.asm ..\hlabe.gas
	
	
hlabe.gasx: hlabe.hla hlabe.hhf
	hla -sourcemode -sx hlabe
	copy hlabe.asm ..\hlabe.gasx
	
	
clean:
	delete *.obj
	delete *.asm
	delete *.bak
	delete *.link
	delete *.inc
	delete *.masm
	delete *.gas
	delete *.gasx

