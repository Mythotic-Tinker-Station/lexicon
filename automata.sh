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

echo "Environment Settings:
Branch: ${GIT_BRANCH}
Build Number: ${BUILD_NUMBER}
Workspace Location: ${WORKSPACE}

Build URL: ${BUILD_URL}
"

# Processing

# Setting Varibles
FILE_NAME="Lexicon"
COMPILE_PATH='./compiler'
GAME_PATH='./pk3'

# Compile BCS Code
chmod +x $COMPILE_PATH/bcc
$COMPILE_PATH/bcc -acc-err-file -x bcs $GAME_PATH/ACS/main.c $GAME_PATH/ACS/main.o

# Pack game files
cd $GAME_PATH
7za a -r -ssw -mx9 -tzip  ../${FILE_NAME}.pk3 ./*

echo "${FILE_NAME}.pk3"