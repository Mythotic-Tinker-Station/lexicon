#!/bin/bash
# Lexicon compile script thingy - Linux version

# [Tri] bash turns my brains into mush x_x

# output pk3 filenames
CORE_PK3="lexicon"
BASE_PK3="lexicon-base"
SLAUGHTER_PK3="lexicon-slaughter"
ULTDOOM_PK3="lexicon-ultdoom"
DM_PK3="lexicon-dm"
CTF_PK3="lexicon-ctf"

# project root (the directory this script lives in)
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"

# ANSI colors
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
BOLD=$(tput bold)
UNDERLINE=$(tput smul)
RESET=$(tput sgr0)

# accumulated build results shown at the top of the menu after each run
last_summary=""

# format a duration in seconds as a readable HhMmSs string
format_duration() {
    local sec=$1
    if   [ $sec -lt 60 ];   then echo "${sec}s"
    elif [ $sec -lt 3600 ]; then printf "%dm%02ds" $((sec/60)) $((sec%60))
    else
        local h=$((sec/3600)) m=$(( (sec%3600)/60 )) s=$((sec%60))
        printf "%dh%02dm%02ds" $h $m $s
    fi
}

# install 7zip via the system package manager
install_7zip() {
    if   [ -f /etc/debian_version ];  then sudo apt-get update && sudo apt-get install -y p7zip-full
    elif [ -f /etc/arch-release ];    then sudo pacman -Sy --noconfirm p7zip
    elif [ -f /etc/redhat-release ];  then
        if   grep -q "Fedora" /etc/redhat-release; then sudo dnf install -y p7zip
        elif grep -q "CentOS" /etc/redhat-release; then sudo yum install -y epel-release && sudo yum install -y p7zip
        fi
    else
        echo "${RED}Unsupported distro. Please install 7zip manually.${RESET}" >&2
        exit 1
    fi
}

# verify 7za is available; if not, give the user 2 minutes to cancel then install
ensure_7zip() {
    if command -v 7za &>/dev/null; then return; fi
    echo "${YELLOW}7zip not found. Installing in 120s -- press Ctrl-C to cancel.${RESET}"
    sleep 120
    install_7zip
    if ! command -v 7za &>/dev/null; then
        echo "${RED}7zip install failed. Please install it manually.${RESET}" >&2
        exit 1
    fi
}

# compile a single pak.
#   $1 label     - display name used in log output   (e.g. "Core")
#   $2 pak_dir   - path to pk3 source tree           (e.g. "core/pk3")
#   $3 acs_src   - ACS source file, relative to ROOT_DIR
#   $4 acs_out   - compiled .o output, relative to ROOT_DIR
#   $5 out_name  - output pk3 base name              (e.g. "lexicon")
#
compile_pak() {
    local label="$1" pak_dir="$2" acs_src="$3" acs_out="$4" out_name="$5"
    local start status=0

    start=$(date +%s)
    cd "$ROOT_DIR" || exit 1

    # step 1: compile ACS
    echo "Step 1: [$label] Compile ACS"
    compiler/bcc -acc-stats -acc-err-file -x bcs "$acs_src" "$acs_out"
    [ $? -ne 0 ] && { echo "${RED}[$label] ACS compile failed.${RESET}"; status=1; }
    rm -f "$(dirname "$acs_src")/acs.err"

    # step 2: zip everything into a temporary pk3
    echo "Step 2: [$label] Zip into PK3"
    cd "$ROOT_DIR/$pak_dir" || { echo "${RED}Cannot cd to $pak_dir${RESET}" >&2; status=1; }
    7za a -tzip -r -ssw -mx=9 "$ROOT_DIR/${out_name}-New.pk3" .
    [ $? -ne 0 ] && { echo "${RED}[$label] 7zip failed.${RESET}"; status=1; }

    # step 3: replace the old pk3 with the new one
    echo "Step 3: [$label] Replace PK3"
    cd "$ROOT_DIR" || exit 1
    rm -f "${out_name}.pk3"
    mv "${out_name}-New.pk3" "${out_name}.pk3"
    echo "${GREEN}[$label] Done.${RESET}"

    local dur
    dur=$(format_duration $(( $(date +%s) - start )))
    if [ $status -eq 0 ]; then
        last_summary+="${GREEN}[$label] success (${dur})${RESET}\n"
    else
        last_summary+="${RED}[$label] FAILURE (${dur})${RESET}\n"
    fi
}

# per-pak wrappers
compile_core()      { compile_pak "Core"          "core/pk3"              "core/pk3/acs/Lexicon.acs"              "core/pk3/acs/Lexicon.o"               "$CORE_PK3";     }
compile_basepak()   { compile_pak "Base"           "lexicon-base/pk3"      "lexicon-base/pk3/acs/LEXBASE.acs"      "lexicon-base/pk3/acs/LEXBASE.o"        "$BASE_PK3";     }
compile_slaughter() { compile_pak "Slaughter"      "lexicon-slaughter/pk3" "lexicon-slaughter/pk3/acs/LEXSLGT.acs" "lexicon-slaughter/pk3/acs/LEXSLGT.o"   "$SLAUGHTER_PK3"; }
compile_ultdoom()   { compile_pak "Ultimate Doom"  "lexicon-ultdoom/pk3"   "lexicon-ultdoom/pk3/acs/LEXULT.acs"    "lexicon-ultdoom/pk3/acs/lexult.o"      "$ULTDOOM_PK3";  }
compile_dm()        { compile_pak "Deathmatch"     "lexicon-dm/pk3"        "lexicon-dm/pk3/acs/LEXDTHM.acs"        "lexicon-dm/pk3/acs/LEXDTHM.o"          "$DM_PK3";       }
compile_ctf()       { compile_pak "CTF"            "lexicon-ctf/pk3"       "lexicon-ctf/pk3/acs/LEXCTF.acs"        "lexicon-ctf/pk3/acs/LEXCTF.o"          "$CTF_PK3";      }

compile_all() {
    compile_core
    compile_basepak
    compile_slaughter
    compile_ultdoom
    compile_dm
    compile_ctf
}

usage() {
    cat <<'EOF'
Usage: ./Compile.sh [options]

Options:
  --1, --core          compile core pak
  --2, --base          compile base pak
  --3, --slaughter     compile slaughter pak
  --4, --ultimate      compile ultimate doom pak
  --5, --dm            compile deathmatch pak
  --6, --ctf           compile ctf pak
  --7, --all           compile all packs in order
  --h, --help          show this help

Flags can be combined in any order; duplicates are ignored.
  ./Compile.sh --core --base
  ./Compile.sh --1 --5 --ctf
EOF
}

# CLI mode
if [ $# -gt 0 ]; then

    declare -a tasks=()
    for arg in "$@"; do
        case "$arg" in
            --h|--help)      usage; exit 0 ;;
            --1|--core)      tasks+=(core) ;;
            --2|--base)      tasks+=(base) ;;
            --3|--slaughter) tasks+=(slaughter) ;;
            --4|--ultimate)  tasks+=(ultdoom) ;;
            --5|--dm)        tasks+=(dm) ;;
            --6|--ctf)       tasks+=(ctf) ;;
            --7|--all)       tasks=(core base slaughter ultdoom dm ctf); break ;;
            *) echo "${RED}Unknown option: $arg${RESET}"; usage; exit 1 ;;
        esac
    done

    declare -A seen=()
    declare -a unique=()
    for t in "${tasks[@]}"; do
        [ -z "${seen[$t]}" ] && { seen[$t]=1; unique+=("$t"); }
    done
    tasks=("${unique[@]}")

    [ ${#tasks[@]} -eq 0 ] && { usage; exit 1; }

    ensure_7zip

    for t in "${tasks[@]}"; do
        case "$t" in
            core)      compile_core ;;
            base)      compile_basepak ;;
            slaughter) compile_slaughter ;;
            ultdoom)   compile_ultdoom ;;
            dm)        compile_dm ;;
            ctf)       compile_ctf ;;
        esac
    done

    echo -e "\n${BOLD}Batch summary:${RESET}"
    echo -e "$last_summary"
    exit 0
fi

# menu
ensure_7zip

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
    echo -e "${CYAN}1)${RESET} Core"
    echo -e "${CYAN}2)${RESET} Base"
    echo -e "${CYAN}3)${RESET} Slaughter"
    echo -e "${CYAN}4)${RESET} Ultimate Doom"
    echo -e "${CYAN}5)${RESET} Deathmatch"
    echo -e "${CYAN}6)${RESET} CTF"
    echo -e "${CYAN}7)${RESET} Everything (grab a beer, this takes a while)"
    echo -e "${CYAN}8)${RESET} Exit"
    echo ""
    read -rp "Enter your choice (1-8): " choice

    last_summary=""
    case $choice in
        1) compile_core ;;
        2) compile_basepak ;;
        3) compile_slaughter ;;
        4) compile_ultdoom ;;
        5) compile_dm ;;
        6) compile_ctf ;;
        7) echo "${CYAN}Compiling everything... sit back and relax.${RESET}"; compile_all ;;
        8) echo "Goodbye!"; exit 0 ;;
        *) echo "${RED}Invalid choice. Enter 1-8.${RESET}" ;;
    esac
done