@echo off

if "%PROCESSOR_ARCHITECTURE%" == "x86" (

	goto x86_compiler
	
) else if "%PROCESSOR_ARCHITECTURE%" == "AMD64" (

	goto amd64_compiler

)

goto 20

:x86_compiler
echo Your CPU x86
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\Lexicon.c ..\pk3\acs\Lexicon.o
	cd ..\
	goto 20

:amd64_compiler
echo Your CPU AMD64
	cd Compiler\x64
	bcc -acc-err-file -x bcs ..\..\pk3\acs\Lexicon.c ..\..\pk3\acs\Lexicon.o
	cd ..\..\
	goto 20

:20
pause

