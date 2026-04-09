#!/bin/bash
# lowercases subfolder names within core/ and lexicon-* folders.
# filenames themselves are left unchanged.
# renames directories directly (one mv per dir) then updates git index in bulk.
# default mode is a dry run. pass --apply to make changes.

DRY_RUN=1
if [ "${1:-}" = "--apply" ]; then
    DRY_RUN=0
fi

REPO_ROOT=$(git rev-parse --show-toplevel)
cd "$REPO_ROOT"

count_renamed=0
count_skipped=0

# collect unique directory paths under target folders that have uppercase chars,
# sorted deepest-first so children are renamed before their parents
mapfile -t dirs < <(
    git ls-files -- core/ lexicon-base/ lexicon-ctf/ lexicon-dm/ lexicon-slaughter/ lexicon-ultdoom/ \
        | xargs -I{} dirname {} \
        | sort -u \
        | grep -E '[A-Z]' \
        | awk '{ print gsub("/", "/") " " $0 }' \
        | sort -rn \
        | cut -d' ' -f2-
)

for dir in "${dirs[@]}"; do
    lower_dir=$(echo "$dir" | tr '[:upper:]' '[:lower:]')

    if [ "$dir" = "$lower_dir" ]; then
        continue
    fi

    if [ ! -d "$dir" ]; then
        # already moved as part of a parent rename
        continue
    fi

    if [ -e "$lower_dir" ]; then
        echo "SKIP (collision): $dir  ->  $lower_dir"
        count_skipped=$((count_skipped + 1))
        continue
    fi

    if [ "$DRY_RUN" = "1" ]; then
        echo "WOULD RENAME: $dir  ->  $lower_dir"
        count_renamed=$((count_renamed + 1))
    else
        mv "$dir" "$lower_dir"
        echo "RENAMED: $dir  ->  $lower_dir"
        count_renamed=$((count_renamed + 1))
    fi
done

if [ "$DRY_RUN" = "0" ] && [ "$count_renamed" -gt 0 ]; then
    echo ""
    echo "updating git index..."
    git add -A
fi

echo ""
if [ "$DRY_RUN" = "1" ]; then
    echo "dry run: $count_renamed directories would be renamed, $count_skipped skipped."
    echo "run with --apply to make changes."
else
    echo "done: $count_renamed directories renamed, $count_skipped skipped."
fi
