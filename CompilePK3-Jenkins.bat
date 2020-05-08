@echo off

set FileName=Lexicon
set MusFileName=Lexicon-miscdata

if "%PROCESSOR_ARCHITECTURE%" == "x86" (

	goto x86_compiler
	
) else if "%PROCESSOR_ARCHITECTURE%" == "AMD64" (

	goto amd64_compiler

)

:x86_compiler
echo Your CPU x86
echo Step 1: ACS
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\Lexicon.c ..\pk3\acs\Lexicon.o
	
echo Step 2: PACK GAME FILES
	cd ..
	cd pk3
	..\Compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%n.pk3 *

echo Step 3: PACK MUSIC AND MISC. FILES
	cd ..
	cd music_pk3
	..\Compiler\7za a -r -ssw -mx9 -tzip  ..\%MusFileName%n.pk3 *

goto 20

:amd64_compiler
echo Your CPU AMD64
echo Step 1: ACS
	cd Compiler\x64
	bcc -acc-err-file -x bcs ..\..\pk3\acs\Lexicon.c ..\..\pk3\acs\Lexicon.o

echo Step 2: PACK GAME FILES
	cd ..\..\
	cd pk3
	..\Compiler\x64\7za a -r -ssw -mx9 -tzip  ..\%FileName%n.pk3 *

echo Step 3: PACK MUSIC AND MISC. FILES
	cd ..
	cd music_pk3
	..\Compiler\x64\7za a -r -ssw -mx9 -tzip  ..\%MusFileName%n.pk3 *

goto 20

:20
echo Step 4: REPLACE
	cd ..
	del %FileName%.pk3
	ren %FileName%n.pk3 %FileName%-beta-%GIT_TAG_NAME%.pk3
	del %MusFileName%.pk3
	ren %MusFileName%n.pk3 %MusFileName%-beta-%GIT_TAG_NAME%.pk3


