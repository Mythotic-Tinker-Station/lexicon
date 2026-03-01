#!/bin/bash

# Lexicon Compile Script - for Linux
# Environment Variables

# File names for output
CoreFileName="lexicon"
BaseFileName="lexicon-base"
SlaughtFileName="lexicon-slaughter"
UltDoomFileName="lexicon-ultdoom"
DmFileName="lexicon-dm"
CTFFileName="lexicon-ctf"

# tput color codes for aesthetics and readability of the script output. These are purely for aesthetics and have no impact on the functionality of the script. Also for the memes!
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
WHITE=$(tput setaf 7)
BOLD=$(tput bold)
UNDERLINE=$(tput smul)
RESET=$(tput sgr0)

# Functions

## Function to install 7zip based on the distribution
install_7zip() {
    if [ -f /etc/debian_version ]; then
        sudo apt-get update && sudo apt-get install -y p7zip-full
    elif [ -f /etc/redhat-release ]; then
        if grep -q "CentOS" /etc/redhat-release; then
            sudo yum install -y epel-release
            sudo yum install -y p7zip
        elif grep -q "Fedora" /etc/redhat-release; then
            sudo dnf install -y p7zip
        fi
    elif [ -f /etc/arch-release ]; then
        sudo pacman -Sy --noconfirm p7zip
    else
        echo "${RED}Unsupported Linux distribution. Please install 7zip manually.${RESET}" >&2
        exit 1
    fi
}

## Function to compile the Lexicon Core File
compile_core() {
    echo "Step 1: [Lexicon Core] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs core/pk3/acs/Lexicon.acs core/pk3/ACS/Lexicon.o # Note: There's two acs folders here but for some reason its required...
    if [ -f core/pk3/acs/acs.err ]; then
        rm core/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Core] Zip into PK3"
    cd core/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${CoreFileName}-New.pk3" .

    echo "Step 3: [Lexicon Core] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${CoreFileName}.pk3
    mv ${CoreFileName}-New.pk3 ${CoreFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Core file has been complete...${RESET}"
}

## Function to compile the Lexicon Base Pak - The main mapset collection
compile_basepak() {
    echo "Step 1: [Lexicon Base] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-base/pk3/acs/LEXBASE.acs lexicon-base/pk3/acs/LEXBASE.o # Note: Only the one acs folder now
    if [ -f lexicon-base/pk3/acs/acs.err ]; then
        rm lexicon-base/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Base] Zip into PK3"
    cd lexicon-base/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${BaseFileName}-New.pk3" .

    echo "Step 3: [Lexicon Base] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${BaseFileName}.pk3
    mv ${BaseFileName}-New.pk3 ${BaseFileName}.pk3

    echo "${GREEN}The Compile process for the Lexicon Base Pak has been complete...${RESET}"
}

## Function to compile the Lexicon Slaughter Pak - The slaughter mapset collection
compile_slaughterpak() {
    echo "Step 1: [Lexicon Slaughter] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-slaughter/pk3/acs/LEXSLGT.acs lexicon-slaughter/pk3/acs/LEXSLGT.o # Note: Only the one acs folder now
    if [ -f lexicon-slaughter/pk3/acs/acs.err ]; then
        rm lexicon-slaughter/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Slaughter] Zip into PK3"
    cd lexicon-slaughter/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${SlaughtFileName}-New.pk3" .

    echo "Step 3: [Lexicon Slaughter] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${SlaughtFileName}.pk3
    mv ${SlaughtFileName}-New.pk3 ${SlaughtFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Slaughter Pak has been complete...${RESET}"
}

## Function to compile the Lexicon Ultimate Doom Pak - The Ultimate Doom mapset collection
compile_ultdoompak() {
    echo "Step 1: [Lexicon Ultimate Doom] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-ultdoom/pk3/acs/LEXULT.acs lexicon-ultdoom/pk3/acs/lexult.o # Note: Only the one acs folder now
    if [ -f lexicon-ultdoom/pk3/acs/acs.err ]; then
        rm lexicon-ultdoom/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Ultimate Doom] Zip into PK3"
    cd lexicon-ultdoom/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${UltDoomFileName}-New.pk3" .

    echo "Step 3: [Lexicon Ultimate Doom] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${UltDoomFileName}.pk3
    mv ${UltDoomFileName}-New.pk3 ${UltDoomFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Ultimate Doom Pak has been complete...${RESET}"
}

## Function to compile the Lexicon Deathmatch Pak - The deathmatch mapset collection
compile_dmpack() {
    echo "Step 1: [Lexicon Deathmatch] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-dm/pk3/acs/LEXDTHM.acs lexicon-dm/pk3/acs/LEXDTHM.o # Note: Only the one acs folder now
    if [ -f lexicon-dm/pk3/acs/acs.err ]; then
        rm lexicon-dm/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Deathmatch] Zip into PK3"
    cd lexicon-dm/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${DmFileName}-New.pk3" .

    echo "Step 3: [Lexicon Deathmatch] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${DmFileName}.pk3
    mv ${DmFileName}-New.pk3 ${DmFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Deathmatch Pak has been complete...${RESET}"
}

## Function to compile the Lexicon CTF Pak - The CTF mapset collection
compile_ctfpack() {
    echo "Step 1: [Lexicon CTF] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-ctf/pk3/acs/LEXCTF.acs lexicon-ctf/pk3/acs/LEXCTF.o # Note: Only the one acs folder now
    if [ -f lexicon-ctf/pk3/acs/acs.err ]; then
        rm lexicon-ctf/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon CTF] Zip into PK3"
    cd lexicon-ctf/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; exit 1; }
    7za a -tzip -r -ssw -mx=9 "../../${CTFFileName}-New.pk3" .

    echo "Step 3: [Lexicon CTF] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; exit 1; }
    rm -f ${CTFFileName}.pk3
    mv ${CTFFileName}-New.pk3 ${CTFFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon CTF Pak has been complete...${RESET}"
}

# Main Routine

# Check if 7zip is installed and attempt to install it if not. If installation fails, exit with an error message.
echo "Checking for 7zip installation..."
if ! command -v 7za &> /dev/null; then
    echo "${YELLOW}7zip is not installed. Attempting to install..."
    sleep 120 # Sleep for 30 seconds to give the user time to read the message before attempting installation
    install_7zip
    if ! command -v 7za &> /dev/null; then
        echo "${RED}7zip installation failed. Please install it manually." >&2
        exit 1
    fi
fi

# Now display the menu system

# clear the terminal first for better aesthetics obviously!
clear

# Display the menu options.

while true; do

    cat <<EOF
    -----------------------------------------------------------
    |                                                         |
    |            The Mythotic TinkerStation presents...       |
    |                                                         |
    |                   The Lexicon                           |
    |                                                         |
    |             Compile Script - Linux                      |
    -----------------------------------------------------------
    |         This is where the magic happens baby!           |
    -----------------------------------------------------------


EOF

    echo ""
    echo "Please select an option to compile:"
    echo ""
    echo "1) Compile Lexicon Core Pak"
    echo "2) Compile Lexicon Base Pak"
    echo "3) Compile Lexicon Slaughter Pak"
    echo "4) Compile Lexicon Ultimate Doom Pak"
    echo "5) Compile Lexicon Deathmatch Pak"
    echo "6) Compile Lexicon CTF Pak"
    echo "7) Compile it all baby! (Warning: This will take a while... get a beer or 100 ready...)"
    echo "8) Exit"
    echo ""
    read -rp "Enter your choice (1-8): " choice

    case $choice in
        1)
            compile_core
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        2)
            compile_basepak
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        3)
            compile_slaughterpak
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        4)
            compile_ultdoompak
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        5)
            compile_dmpack
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        6)
            compile_ctfpack
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        7)
            echo "${CYAN}Alright boss. Dont say I didnt warn you... Starting the compilation of everything. Sit back, relax and enjoy the show. This is gonna take a while...${RESET}"
            compile_core
            compile_basepak
            compile_slaughterpak
            compile_ultdoompak
            compile_dmpack
            compile_ctfpack
            sleep 10 # Sleep for 10 seconds to give the user time to read the completion message before showing the menu again
            clear # Clear the terminal for better aesthetics before showing the menu again
            ;;
        8)
            echo "Exiting the script. Goodbye!"
            exit 0
            ;;
        *)
            echo "${RED}Invalid option. Please enter a number between 1 and 8.${RESET}"
            ;;
    esac
done