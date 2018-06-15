@echo off
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\Lexicon.c ..\pk3\acs\Lexicon.o
	if not exist ..\pk3\acs\acs.err goto 20
	pause
:20
