!#/bin/bash

## The command to display all the binaries that will be cleaned up
find . -type f ! -name "*.*" -exec sh -c 'for f; do file "$f" | grep -qE "ELF|executable|Mach-O" && echo "To be deleted: $f"; done' _ {} +

## The command to clean the binaries
find . -type f ! -name "*.*" -exec sh -c 'for f; do file "$f" | grep -qE "ELF|executable|Mach-O" && rm "$f"; done' _ {} +

