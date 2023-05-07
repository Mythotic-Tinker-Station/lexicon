@echo off

set FileName=Lexicon

echo Step 1: ACS
	compiler\bcc.exe -acc-stats -acc-err-file -x bcs pk3\acs\lexicon.c pk3\acs\lexicon.o
	if not exist pk3\acs\acs.err goto 20
	del pk3\acs\acs.err

:20
echo Step 2: PACK
	cd pk3
	..\compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%-New.pk3 *.kvx *.x* *.txt *.o *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.ogg *.vgz *.wav *.pk3 *.gl


echo Step 3: REPLACE
	cd ..
	del %FileName%.pk3
	ren %FileName%-New.pk3 %FileName%.pk3

pause