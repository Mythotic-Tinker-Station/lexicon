@echo off

set FileName=Lexicon

echo Step 1: ACS
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\%FileName%.c ..\pk3\acs\%FileName%.o
	if not exist ..\pk3\acs\acs.err goto 20
:20

echo Step 2: PACK
	cd ..
	cd pk3
	..\Compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%n.pk3 *

echo Step 3: PACK MUSIC AND MISC. FILES
	cd ..
	cd music_pk3
	..\Compiler\7za a -r -ssw -mx9 -tzip  ..\%MusFileName%n.pk3 *
	
echo Step 4: REPLACE
	cd ..
	del %FileName%.pk3
	ren %FileName%n.pk3 %FileName%-alpha-build-%BUILD_NUMBER%.pk3
	del %MusFileName%.pk3
	ren %MusFileName%n.pk3 %MusFileName%-alpha-build-%BUILD_NUMBER%.pk3