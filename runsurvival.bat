:10
echo Step 1: ACS
	compiler\bcc.exe -acc-stats -acc-err-file -x bcs pk3\acs\lexicon.c pk3\acs\lexicon.o
	if not exist pk3\acs\acs.err goto 20
	del pk3\acs\acs.err
	pause
    goto 10
:20
E:\Games\Doom\Engines\Zandronum\Zandronum.exe -file "E:\GitHub\lexicon\pk3" -file "E:\GitHub\lexicon-base\pk3" +map epic01 +survival true