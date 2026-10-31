#!/bin/bash

find path -name "*.png" -type f -print0 | while IFS= read -rd '' file; do
  echo "Checking: $file"
  colorspace=$(identify -format "%[colorspace]" "$file")
  has_alpha=$(identify -format "%A" "$file")
  echo "  Colorspace: $colorspace, Alpha: $has_alpha"
    if [ "$colorspace" = "Gray" ] && [ "$has_alpha" != "false" ]; then
    echo "  Converting: $file"
    magick "$file" -colorspace sRGB -colors 256 png8:"$file"
    echo "  Done: $file"
    fi
done