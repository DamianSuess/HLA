
all: hlaasm.masm hlaasm.gas hfasm.masm hfasm.gas

hlaasm.masm:	
	hla -sourcemode -sm hlaasm.hla
	copy hlaasm.asm ..\hlaasm.masm
	ml -c -Cp hlaasm.asm
	copy hlaasm.obj ..\hlaasm.obj
	
	
hfasm.masm:
	hla -AZi -AZd -AZf -sourcemode -sm -dcfunc hfasm.hla
	copy hfasm.asm ..\hfasm.masm
	ml -c -Cp hfasm.asm
	copy hfasm.obj ..\hfasm.obj	
	
hlaasm.gas:
	hla -sourcemode -sg -dunix hlaasm.hla
	copy hlaasm.asm ..\hlaasm.gas
	
hlaasm.gasx:
	hla -sourcemode -sx -dmacosx hlaasm.hla
	copy hlaasm.asm ..\hlaasm.gasx
	
hfasm.gas:
	hla -sourcemode -sg -dcfunc -dunix hfasm.hla
	copy hfasm.asm ..\hfasm.gas
	

clean:
	delete *.obj
	delete *.asm
	delete *.bak
	delete *.link
	delete *.inc

