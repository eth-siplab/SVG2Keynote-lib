#!/usr/bin/env bash

# Set the folder path here
folder_path="."

# Loop through all files in the folder
for file in "$folder_path"/*; do
  # Check if the item is a file
  if [ -f "$file" ]; then
    # Get the filename
    filename=$(basename "$file")

    # Output the scheme
    echo "File \"$filename\" is:"
    echo ""
    echo "---- START $filename ----"
    cat "$file"
    echo "---- END $filename ----"
    echo ""
  fi
done
