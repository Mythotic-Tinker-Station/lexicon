#!/bin/bash
# Lexicon Combined Automata

# Lexicon
if [ -e "pk3/Acs/lexicon.c" ]; then
	CODEBASE="Lexicon"
	DISPLAY_NAME="       Lexicon Automata      "
	OUTPUT_FILE_NAME="Lexicon"
	SOURCE_FILE_NAME="lexicon" # Without extension ;)
	ACS_PATH="Acs"
# Lexicon Base
elif [ -e "pk3/ACS/main.c" ]; then
	CODEBASE="Basepack"
	DISPLAY_NAME=" Lexicon Base File Automata  "
	OUTPUT_FILE_NAME="Lexicon_basepack"
	SOURCE_FILE_NAME="main" # Without extension ;)
	ACS_PATH="ACS"
else
	echo "Unrecognised codebase"
	exit
fi

# Header
echo "
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
----------------------------------$DISPLAY_NAME-----------------------------------------
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
"

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

COMPILE_PATH='./compiler'
GAME_PATH='./pk3'

if [ -e "$OUTPUT_FILE_NAME.pk3" ]; then
	rm "$OUTPUT_FILE_NAME.pk3"
fi

# Compile BCS Code
chmod +x $COMPILE_PATH/$BCC_COMPILER
$COMPILE_PATH/$BCC_COMPILER -acc-err-file -x bcs $GAME_PATH/$ACS_PATH/$SOURCE_FILE_NAME.c $GAME_PATH/$ACS_PATH/$SOURCE_FILE_NAME.o  || exit 1

# Pack game files
cd $GAME_PATH
7za a -r -ssw -mx9 -tzip  ../${OUTPUT_FILE_NAME}.pk3 ./* || exit 1

echo "${OUTPUT_FILE_NAME}.pk3"