@echo off

echo 1. core
echo 2. lexicon-base
echo 3. lexicon-slaughter
echo 4. lexicon-ultdoom
echo 5. lexicon-dm
echo 6. lexicon-ctf

set /p firstChoice=Enter your choice (1-6): 

echo 1. Compile ACS
echo 2. Pack
echo 3. Both
echo 4. Compile and pack everything (Very slow!)

set /p secondChoice=Enter your choice (1-3): 

if %secondChoice%==1 (
	if %firstChoice%==1 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs core\pk3\acs\Lexicon.acs core\pk3\acs\Lexicon.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err
		compiler\acc\acc.exe core\pk3\acs\LexGUI.acs core\pk3\acs\LexGUI.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err
		pause
	)

	if %firstChoice%==2 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-base\pk3\acs\LEXBASE.acs lexicon-base\pk3\acs\LEXBASE.o
		if not exist lexicon-base\pk3\acs\acs.err goto 20
		del lexicon-base\pk3\acs\acs.err
		pause
	)

	if %firstChoice%==3 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-slaughter\pk3\acs\LEXSLGT.acs lexicon-slaughter\pk3\acs\LEXSLGT.o
		if not exist lexicon-slaughter\pk3\acs\acs.err goto 20
		del lexicon-slaughter\pk3\acs\acs.err
		pause
	)

	if %firstChoice%==4 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ultdoom\pk3\acs\LEXULT.acs lexicon-ultdoom\pk3\acs\LEXULT.o
		if not exist lexicon-ultdoom\pk3\acs\acs.err goto 20
		del lexicon-ultdoom\pk3\acs\acs.err
		pause
	)

	if %firstChoice%==5 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-dm\pk3\acs\LEXDTHM.acs lexicon-dm\pk3\acs\LEXDTHM.o
		if not exist lexicon-dm\pk3\acs\acs.err goto 20
		del lexicon-dm\pk3\acs\acs.err
		pause
	)

	if %firstChoice%==6 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ctf\pk3\acs\LEXCTF.acs lexicon-ctf\pk3\acs\LEXCTF.o
		if not exist lexicon-ctf\pk3\acs\acs.err goto 20
		del lexicon-ctf\pk3\acs\acs.err
		pause
	)
)

if %secondChoice%==2 (
	if %firstChoice%==1 (
		echo Step 2: PACK
		cd core\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon.pk3
		ren Lexicon-New.pk3 Lexicon.pk3
		pause
	)

	if %firstChoice%==2 (
		echo Step 2: PACK
		cd lexicon-base\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Base-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-Base.pk3
		ren Lexicon-Base-New.pk3 Lexicon-Base.pk3
		pause
	)

	if %firstChoice%==3 (
		echo Step 2: PACK
		cd lexicon-slaughter\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Slaughter-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-Slaughter.pk3
		ren Lexicon-Slaughter-New.pk3 Lexicon-Slaughter.pk3
		pause
	)

	if %firstChoice%==4 (
		echo Step 2: PACK
		cd lexicon-ultdoom\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-UltDoom-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-UltDoom.pk3
		ren Lexicon-UltDoom-New.pk3 Lexicon-UltDoom.pk3
		pause
	)

	if %firstChoice%==5 (
		echo Step 2: PACK
		cd lexicon-dm\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-DM-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-DM.pk3
		ren Lexicon-DM-New.pk3 Lexicon-DM.pk3
		pause
	)

	if %firstChoice%==6 (
		echo Step 2: PACK
		cd lexicon-ctf\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-CTF-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
		
		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-CTF.pk3
		ren Lexicon-CTF-New.pk3 Lexicon-CTF.pk3
		pause
	)
)

if %secondChoice%==3 (
	if %firstChoice%==1 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs core\pk3\acs\Lexicon.acs core\pk3\acs\Lexicon.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err
		compiler\acc\acc.exe core\pk3\acs\LexGUI.acs core\pk3\acs\LexGUI.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err

		echo Step 2: PACK
		cd core\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon.pk3
		ren Lexicon-New.pk3 Lexicon.pk3
		pause
	)

	if %firstChoice%==2 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-base\pk3\acs\LEXBASE.acs lexicon-base\pk3\acs\LEXBASE.o
		if not exist lexicon-base\pk3\acs\acs.err goto 20
		del lexicon-base\pk3\acs\acs.err

		echo Step 2: PACK
		cd lexicon-base\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Base-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-Base.pk3
		ren Lexicon-Base-New.pk3 Lexicon-Base.pk3
		pause
	)

	if %firstChoice%==3 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-slaughter\pk3\acs\LEXSLGT.acs lexicon-slaughter\pk3\acs\LEXSLGT.o
		if not exist lexicon-slaughter\pk3\acs\acs.err goto 20
		del lexicon-slaughter\pk3\acs\acs.err

		echo Step 2: PACK
		cd lexicon-slaughter\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Slaughter-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-Slaughter.pk3
		ren Lexicon-Slaughter-New.pk3 Lexicon-Slaughter.pk3
		pause
	)

	if %firstChoice%==4 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ultdoom\pk3\acs\LEXULT.acs lexicon-ultdoom\pk3\acs\LEXULT.o
		if not exist lexicon-ultdoom\pk3\acs\acs.err goto 20
		del lexicon-ultdoom\pk3\acs\acs.err

		echo Step 2: PACK
		cd lexicon-ultdoom\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-UltDoom-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-UltDoom.pk3
		ren Lexicon-UltDoom-New.pk3 Lexicon-UltDoom.pk3
		pause
	)

	if %firstChoice%==5 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-dm\pk3\acs\LEXDTHM.acs lexicon-dm\pk3\acs\LEXDTHM.o
		if not exist lexicon-dm\pk3\acs\acs.err goto 20
		del lexicon-dm\pk3\acs\acs.err

		echo Step 2: PACK
		cd lexicon-dm\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-DM-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-DM.pk3
		ren Lexicon-DM-New.pk3 Lexicon-DM.pk3
		pause
	)

	if %firstChoice%==6 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ctf\pk3\acs\LEXCTF.acs lexicon-ctf\pk3\acs\LEXCTF.o
		if not exist lexicon-ctf\pk3\acs\acs.err goto 20
		del lexicon-ctf\pk3\acs\acs.err

		echo Step 2: PACK
		cd lexicon-ctf\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-CTF-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon-CTF.pk3
		ren Lexicon-CTF-New.pk3 Lexicon-CTF.pk3
		pause
	)
)

if %secondChoice%==4 (
		echo Step 1: ACS
		compiler\bcc.exe -acc-stats -acc-err-file -x bcs core\pk3\acs\Lexicon.acs core\pk3\acs\Lexicon.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err
		compiler\acc\acc.exe core\pk3\acs\LexGUI.acs core\pk3\acs\LexGUI.o
		if not exist core\pk3\acs\acs.err goto 20
		del core\pk3\acs\acs.err

		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-base\pk3\acs\LEXBASE.acs lexicon-base\pk3\acs\LEXBASE.o
		if not exist lexicon-base\pk3\acs\acs.err goto 20
		del lexicon-base\pk3\acs\acs.err

		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-slaughter\pk3\acs\LEXSLGT.acs lexicon-slaughter\pk3\acs\LEXSLGT.o
		if not exist lexicon-slaughter\pk3\acs\acs.err goto 20
		del lexicon-slaughter\pk3\acs\acs.err

		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ultdoom\pk3\acs\LEXULT.acs lexicon-ultdoom\pk3\acs\LEXULT.o
		if not exist lexicon-ultdoom\pk3\acs\acs.err goto 20
		del lexicon-ultdoom\pk3\acs\acs.err

		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-dm\pk3\acs\LEXDTHM.acs lexicon-dm\pk3\acs\LEXDTHM.o
		if not exist lexicon-dm\pk3\acs\acs.err goto 20
		del lexicon-dm\pk3\acs\acs.err

		compiler\bcc.exe -acc-stats -acc-err-file -x bcs lexicon-ctf\pk3\acs\LEXCTF.acs lexicon-ctf\pk3\acs\LEXCTF.o
		if not exist lexicon-ctf\pk3\acs\acs.err goto 20
		del lexicon-ctf\pk3\acs\acs.err

		echo Step 2: PACK
		cd core\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		cd ..\..\lexicon-base\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Base-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		cd ..\..\lexicon-slaughter\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-Slaughter-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		cd ..\..\lexicon-ultdoom\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-UltDoom-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		cd ..\..\lexicon-dm\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-DM-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		cd ..\..\lexicon-ctf\pk3
		..\..\compiler\7za a -r -ssw -mx9 -tzip  ..\..\Lexicon-CTF-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

		echo Step 3: REPLACE
		cd ..\..
		del Lexicon.pk3
		ren Lexicon-New.pk3 Lexicon.pk3

		del Lexicon-Base.pk3
		ren Lexicon-Base-New.pk3 Lexicon-Base.pk3

		del Lexicon-Slaughter.pk3
		ren Lexicon-Slaughter-New.pk3 Lexicon-Slaughter.pk3

		del Lexicon-UltDoom.pk3
		ren Lexicon-UltDoom-New.pk3 Lexicon-UltDoom.pk3

		del Lexicon-DM.pk3
		ren Lexicon-DM-New.pk3 Lexicon-DM.pk3

		del Lexicon-CTF.pk3
		ren Lexicon-CTF-New.pk3 Lexicon-CTF.pk3
		pause
)