#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file> <word>"
    exit 1
fi

file="$1"
word="$2"

if [ ! -f "$file" ]; then
    echo "Error: '$file' is not a regular file."
    exit 1
fi

# Case-insensitive exact-word occurrence count.
grep -oiw -- "$word" "$file" | wc -l
