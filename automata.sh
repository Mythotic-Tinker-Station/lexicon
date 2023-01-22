#!/bin/bash

# Lexicon Base file automata script

# Header
echo "
------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------
----------------------------------       Lexicon Base File Automata      -----------------------------------------
------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------
"
echo ""

echo "Environment Settings:"
echo "Branch: $(git branch --show-current)"
echo "Build Number: ${BUILD_NUMBER}"
echo "Workspace Location: ${WORKSPACE}"
echo "Build URL: ${BUILD_URL}"

if ! command -v 7za &> /dev/null
then
    echo "7za not detected; please install 7za (for example, using brew install p7zip)"
    exit
fi

# $ARCH is x86_64* for x64, i*86 for x86, or arm* for arm
ARCH=$(uname -m)

#$OSTYPE is linux-gnu* for linux, freebsd* for bsd, or darwin* for mac
if [[ "$OSTYPE" == "darwin"* && $ARCH =~ ^arm ]]; then
	BCC_COMPILER="bcc-mac"
else
	BCC_COMPILER="bcc"
fi

# Processing

# Setting Varibles
FILE_NAME="Lexicon"
COMPILE_PATH='./compiler'
GAME_PATH='./pk3'

if [ -e "$FILE_NAME.pk3" ]; then
	rm "$FILE_NAME.pk3"
fi

# Compile BCS Code
chmod +x $COMPILE_PATH/$BCC_COMPILER
$COMPILE_PATH/$BCC_COMPILER -acc-err-file -x bcs $GAME_PATH/Acs/lexicon.c $GAME_PATH/Acs/lexicon.o
[ $? -eq 0 ]  || exit 1

# Pack game files
cd $GAME_PATH
7za a -r -ssw -mx9 -tzip  ../${FILE_NAME}.pk3 ./*
[ $? -eq 0 ]  || exit 1

echo "${FILE_NAME}.pk3"