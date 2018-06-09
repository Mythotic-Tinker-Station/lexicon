@echo off
	cd Compiler
	bcc -acc-err-file -x bcs ..\pk3\acs\vote.c ..\pk3\acs\vote.o
	if not exist ..\pk3\acs\acs.err goto 20
	pause
:20
