#!/bin/bash

# Lexicon Main file automata script

# Header
echo "
------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------
----------------------------------       Lexicon Main File Automata      -----------------------------------------
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
COMPILE_PATH='./Compiler'
GAME_PATH='./pk3'

# Compile BCS Code
chmod +x $COMPILE_PATH/bcc
$COMPILE_PATH/bcc -acc-err-file -x bcs $GAME_PATH/acs/Lexicon.c $GAME_PATH/acs/Lexicon.o

# Pack game files
cd $GAME_PATH
7za a -r -ssw -mx9 -tzip  ../${FILE_NAME}.pk3 ./*

# Create proper Jenkins filenames
cd ..
mv ./${FILE_NAME}.pk3 ./${FILE_NAME}_beta_build_${BUILD_NUMBER}.pk3