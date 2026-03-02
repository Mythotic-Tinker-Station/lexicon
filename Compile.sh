#!/bin/bash
# bash turns my brains into mush x_x

# names used when creating the output pk3 files.
CoreFileName="lexicon"
BaseFileName="lexicon-base"
SlaughtFileName="lexicon-slaughter"
UltDoomFileName="lexicon-ultdoom"
DmFileName="lexicon-dm"
CTFFileName="lexicon-ctf"

# ANSI color codes via tput
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

# summary text that will be shown each time the menu redraws
last_summary=""

# helper to render a duration (seconds) in a human-friendly
# HhMmSs format.  Used by the compile_* functions when writing the
# summary string so the output is easier to read than raw seconds.
format_duration() {
    local sec=$1
    if [ $sec -lt 60 ]; then
        echo "${sec}s"
    else
        local m=$((sec/60))
        local s=$((sec%60))
        if [ $m -lt 60 ]; then
            printf "%dm%02ds" $m $s
        else
            local h=$((m/60))
            m=$((m%60))
            printf "%dh%02dm%02ds" $h $m $s
        fi
    fi
}

# function to install 7zip based on the distribution
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

# simple wrapper that verifies 7za is present and installs it if not
ensure_7zip() {
    echo "Checking for 7zip installation..."
    if ! command -v 7za &> /dev/null; then
        echo "${YELLOW}7zip is not installed. Attempting to install..."
        sleep 120 # give user a moment to cancel or read
        install_7zip
        if ! command -v 7za &> /dev/null; then
            echo "${RED}7zip installation failed. Please install it manually." >&2
            exit 1
        fi
    fi
}

# function to compile the Lexicon Core File
compile_core() {
    # record the start time and assume success (status=0)
    local start=$(date +%s)
    local status=0

    # step 1: compile the ACS source using the custom bcc compiler
    echo "Step 1: [Lexicon Core] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs core/pk3/acs/Lexicon.acs core/pk3/ACS/Lexicon.o # Note: There's two acs folders here but for some reason its required...
    # check return code; if nonzero we mark failure but continue to allow cleanup
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon Core ACS compilation failed.${RESET}"
        status=1
    fi
    # remove the temporary error file if created
    if [ -f core/pk3/acs/acs.err ]; then
        rm core/pk3/acs/acs.err
    fi

    # step 2: create zip archive of the compiled files
    echo "Step 2: [Lexicon Core] Zip into PK3"
    cd core/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${CoreFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon Core.${RESET}"
        status=1
    fi

    # step 3: move the new archive into place
    echo "Step 3: [Lexicon Core] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${CoreFileName}.pk3
    mv ${CoreFileName}-New.pk3 ${CoreFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Core file has been complete...${RESET}"

    # record duration and add an entry to the summary string
    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[Core] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[Core] FAILURE (${durfmt})${RESET}\n"
    fi
}

# function to compile the main mapset collection
compile_basepak() {
    # these are all basically the same steps as compile_core 
    local start=$(date +%s)
    local status=0

    echo "Step 1: [Lexicon Base] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-base/pk3/acs/LEXBASE.acs lexicon-base/pk3/acs/LEXBASE.o # Note: Only the one acs folder now
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon Base ACS compilation failed.${RESET}"
        status=1
    fi
    if [ -f lexicon-base/pk3/acs/acs.err ]; then
        rm lexicon-base/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Base] Zip into PK3"
    cd lexicon-base/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${BaseFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon Base.${RESET}"
        status=1
    fi

    echo "Step 3: [Lexicon Base] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${BaseFileName}.pk3
    mv ${BaseFileName}-New.pk3 ${BaseFileName}.pk3

    echo "${GREEN}The Compile process for the Lexicon Base Pak has been complete...${RESET}"

    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[Base] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[Base] FAILURE (${durfmt})${RESET}\n"
    fi
}

# function to compile The slaughter mapset collection
compile_slaughterpak() {
    local start=$(date +%s)
    local status=0

    echo "Step 1: [Lexicon Slaughter] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-slaughter/pk3/acs/LEXSLGT.acs lexicon-slaughter/pk3/acs/LEXSLGT.o # Note: Only the one acs folder now
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon Slaughter ACS compilation failed.${RESET}"
        status=1
    fi
    if [ -f lexicon-slaughter/pk3/acs/acs.err ]; then
        rm lexicon-slaughter/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Slaughter] Zip into PK3"
    cd lexicon-slaughter/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${SlaughtFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon Slaughter.${RESET}"
        status=1
    fi

    echo "Step 3: [Lexicon Slaughter] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${SlaughtFileName}.pk3
    mv ${SlaughtFileName}-New.pk3 ${SlaughtFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Slaughter Pak has been complete...${RESET}"

    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[Slaughter] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[Slaughter] FAILURE (${durfmt})${RESET}\n"
    fi
}

# function to compile The Ultimate Doom mapset collection
compile_ultdoompak() {
    local start=$(date +%s)
    local status=0

    echo "Step 1: [Lexicon Ultimate Doom] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-ultdoom/pk3/acs/LEXULT.acs lexicon-ultdoom/pk3/acs/lexult.o # Note: Only the one acs folder now
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon Ultimate Doom ACS compilation failed.${RESET}"
        status=1
    fi
    if [ -f lexicon-ultdoom/pk3/acs/acs.err ]; then
        rm lexicon-ultdoom/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Ultimate Doom] Zip into PK3"
    cd lexicon-ultdoom/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${UltDoomFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon Ultimate Doom.${RESET}"
        status=1
    fi

    echo "Step 3: [Lexicon Ultimate Doom] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${UltDoomFileName}.pk3
    mv ${UltDoomFileName}-New.pk3 ${UltDoomFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Ultimate Doom Pak has been complete...${RESET}"

    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[UltDoom] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[UltDoom] FAILURE (${durfmt})${RESET}\n"
    fi
}

# function to compile The deathmatch mapset collection
compile_dmpack() {
    local start=$(date +%s)
    local status=0

    echo "Step 1: [Lexicon Deathmatch] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-dm/pk3/acs/LEXDTHM.acs lexicon-dm/pk3/acs/LEXDTHM.o # Note: Only the one acs folder now
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon Deathmatch ACS compilation failed.${RESET}"
        status=1
    fi
    if [ -f lexicon-dm/pk3/acs/acs.err ]; then
        rm lexicon-dm/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon Deathmatch] Zip into PK3"
    cd lexicon-dm/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${DmFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon Deathmatch.${RESET}"
        status=1
    fi

    echo "Step 3: [Lexicon Deathmatch] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${DmFileName}.pk3
    mv ${DmFileName}-New.pk3 ${DmFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon Deathmatch Pak has been complete...${RESET}"

    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[DM] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[DM] FAILURE (${durfmt})${RESET}\n"
    fi
}

# function to compile The CTF mapset collection
compile_ctfpack() {
    local start=$(date +%s)
    local status=0

    echo "Step 1: [Lexicon CTF] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs lexicon-ctf/pk3/acs/LEXCTF.acs lexicon-ctf/pk3/acs/LEXCTF.o # Note: Only the one acs folder now
    if [ $? -ne 0 ]; then
        echo "${RED}Lexicon CTF ACS compilation failed.${RESET}"
        status=1
    fi
    if [ -f lexicon-ctf/pk3/acs/acs.err ]; then
        rm lexicon-ctf/pk3/acs/acs.err
    fi

    echo "Step 2: [Lexicon CTF] Zip into PK3"
    cd lexicon-ctf/pk3 || { echo "${RED}Failed to change directory to pk3${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "../../${CTFFileName}-New.pk3" .
    if [ $? -ne 0 ]; then
        echo "${RED}7zip failed for Lexicon CTF.${RESET}"
        status=1
    fi

    echo "Step 3: [Lexicon CTF] Rename Created PK3"
    cd ../.. || { echo "${RED}Failed to change directory to parent${RESET}" >&2; status=1; }
    rm -f ${CTFFileName}.pk3
    mv ${CTFFileName}-New.pk3 ${CTFFileName}.pk3
    echo "${GREEN}The Compile process for the Lexicon CTF Pak has been complete...${RESET}"

    local end=$(date +%s)
    local duration=$((end - start))
    local durfmt=$(format_duration $duration)
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[CTF] success (${durfmt})${RESET}\n"
    else
        last_summary+="${RED}[CTF] FAILURE (${durfmt})${RESET}\n"
    fi
}

# command-line arguments handler helper
usage() {
    cat <<'EOF'
Usage: ./Compile.sh [options]

Options:
  --1, --core                   compile core pak
  --2, --base                   compile base pak
  --3, --slaughter              compile slaughter pak
  --4, --ultimate               compile ultimate doom pak
  --5, --dm                     compile deathmatch pak
  --6, --ctf                    compile ctf pak
  --7, --all                    compile all packs in order
  --h, --help,                  display this help and exit

You may combine flags in any order; duplicate entries are ignored.
Examples:
  ./Compile.sh --core --base       # builds core then base
  ./Compile.sh --1 --5 --ctf       # builds core, deathmatch and ctf

EOF
}

if [ $# -gt 0 ]; then
    declare -a task_list=()
    for arg in "$@"; do
        case "$arg" in
            --h|--help)
                usage
                exit 0
                ;;
            --1|--core)
                task_list+=(core)
                ;;
            --2|--base)
                task_list+=(base)
                ;;
            --3|--slaughter)
                task_list+=(slaughter)
                ;;
            --4|--ultimate)
                task_list+=(ultdoompak)
                ;;
            --5|--dm)
                task_list+=(dm)
                ;;
            --6|--ctf)
                task_list+=(ctf)
                ;;
            --7|--all)
                task_list=(core base slaughter ultdoompak dm ctf)
                break
                ;;
            *)
                echo "${RED}Unknown option: $arg${RESET}"
                usage
                exit 1
                ;;
        esac
    done

    declare -A seen=()
    filtered=()
    for t in "${task_list[@]}"; do
        if [ -z "${seen[$t]}" ]; then
            seen[$t]=1
            filtered+=("$t")
        fi
    done
    task_list=("${filtered[@]}")

    if [ ${#task_list[@]} -eq 0 ]; then
        usage
        exit 1
    fi

    # ensure required tools are present for batch mode
    ensure_7zip

    last_summary=""
    for t in "${task_list[@]}"; do
        case "$t" in
            core) compile_core ;; 
            base) compile_basepak ;; 
            slaughter) compile_slaughterpak ;; 
            ultdoompak) compile_ultdoompak ;; 
            dm) compile_dmpack ;; 
            ctf) compile_ctfpack ;; 
        esac
    done

    echo -e "\n${BOLD}Batch summary:${RESET}"
    echo -e "$last_summary"
    exit 0
fi

# we rely on the command-line "7za" utility to create pk3 (zip) files.
# if it is missing we try to install it via the local package manager
# (supports Debian, RedHat/CentOS, Fedora, Arch).  The user has 2 minutes
# to cancel before the installer runs.
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

# main menu
while true; do
    clear
    if [ -n "$last_summary" ]; then
        echo -e "${BOLD}${UNDERLINE}Previous build:${RESET}"
        echo -e "$last_summary"
        echo
    fi

    cat <<EOF
${BLUE}    -----------------------------------------------------------------
    |   ${MAGENTA}${BOLD}The Mythotic TinkerStation presents...${RESET}${BLUE}

    |   ${MAGENTA}${BOLD}The Lexicon${RESET}${BLUE}

    |   ${MAGENTA}${BOLD}Compile Script - Linux${RESET}${BLUE}
    -----------------------------------------------------------------
    |         ${YELLOW}This is where the magic happens baby!${RESET}${BLUE}
    -----------------------------------------------------------------${RESET}
EOF

    echo ""
    echo "Please select an option to compile:"
    echo ""
    echo -e "${CYAN}1)${RESET} Compile Lexicon Core Pak"
    echo -e "${CYAN}2)${RESET} Compile Lexicon Base Pak"
    echo -e "${CYAN}3)${RESET} Compile Lexicon Slaughter Pak"
    echo -e "${CYAN}4)${RESET} Compile Lexicon Ultimate Doom Pak"
    echo -e "${CYAN}5)${RESET} Compile Lexicon Deathmatch Pak"
    echo -e "${CYAN}6)${RESET} Compile Lexicon CTF Pak"
    echo -e "${CYAN}7)${RESET} Compile it all baby! (Warning: This will take a while... get a beer or 100 ready...)"
    echo -e "${CYAN}8)${RESET} Exit"
    echo ""
    read -rp "Enter your choice (1-8): " choice

    case $choice in
        1)
            # single target: core only
            last_summary=""
            compile_core
            ;;
        2)
            last_summary=""
            compile_basepak
            ;;
        3)
            last_summary=""
            compile_slaughterpak
            ;;
        4)
            last_summary=""
            compile_ultdoompak
            ;;
        5)
            last_summary=""
            compile_dmpack
            ;;
        6)
            last_summary=""
            compile_ctfpack
            ;;
        7)
            # build everything in sequence; summary accumulates each step
            last_summary=""
            echo "${CYAN}Alright boss. Dont say I didnt warn you... Starting the compilation of everything. Sit back, relax and enjoy the show. This is gonna take a while...${RESET}"
            compile_core
            compile_basepak
            compile_slaughterpak
            compile_ultdoompak
            compile_dmpack
            compile_ctfpack
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