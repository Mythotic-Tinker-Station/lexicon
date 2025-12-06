#!/bin/bash

FileName="Lexicon"

# Function to install 7zip based on the distribution
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
        echo "Unsupported Linux distribution. Please install 7zip manually." >&2
        exit 1
    fi
}

# Check if 7zip is installed
if ! command -v 7za &> /dev/null; then
    echo "7zip is not installed. Attempting to install..."
    install_7zip
    if ! command -v 7za &> /dev/null; then
        echo "7zip installation failed. Please install it manually." >&2
        exit 1
    fi
fi

echo "Step 1: ACS"
compiler/bcc -acc-stats -acc-err-file -x bcs pk3/acs/Lexicon.acs pk3/ACS/lexicon.o
if [ -f pk3/acs/acs.err ]; then
    rm pk3/acs/acs.err
fi

echo "Step 2: PACK"
cd pk3 || { echo "Failed to change directory to pk3" >&2; exit 1; }
7za a -tzip -r -ssw -mx=9 "../${FileName}-New.pk3" .

echo "Step 3: REPLACE"
cd .. || { echo "Failed to change directory to parent" >&2; exit 1; }
rm -f ${FileName}.pk3
mv ${FileName}-New.pk3 ${FileName}.pk3

echo "The Compile process has been complete..."