@echo off

set FileName=Lexicon
set MusFileName=Lexicon-miscdata

echo Step 2: ACS
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\%FileName%.c ..\pk3\acs\%FileName%.o
	if not exist ..\pk3\acs\acs.err goto 20
:20

echo Step 2: PACK GAME FILES
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
	ren %FileName%n.pk3 %FileName%.pk3
	del %MusFileName%.pk3
	ren %MusFileName%n.pk3 %MusFileName%.pk3