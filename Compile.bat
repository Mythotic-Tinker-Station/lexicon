@echo off

set FileName=Lexicon

echo 1. Compile ACS
echo 2. Pack
echo 3. Both

set /p choice=Enter your choice (1-3): 

if %choice%==1 (
    echo Step 1: ACS
    compiler\bcc.exe -acc-stats -acc-err-file -x bcs pk3\acs\lexicon.acs pk3\acs\lexicon.o
    if not exist pk3\acs\acs.err goto 20
    del pk3\acs\acs.err
    pause
)

if %choice%==2 (
    echo Step 2: PACK
    cd pk3
    ..\compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl
    
    echo Step 3: REPLACE
    cd ..
    del %FileName%.pk3
    ren %FileName%-New.pk3 %FileName%.pk3
    pause
)

if %choice%==3 (
    echo Step 1: ACS
    compiler\bcc.exe -acc-stats -acc-err-file -x bcs pk3\acs\lexicon.acs pk3\acs\lexicon.o
    if not exist pk3\acs\acs.err goto 20
    del pk3\acs\acs.err

    echo Step 2: PACK
    cd pk3
    ..\compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl

    echo Step 3: REPLACE
    cd ..
    del %FileName%.pk3
    ren %FileName%-New.pk3 %FileName%.pk3
    pause
)