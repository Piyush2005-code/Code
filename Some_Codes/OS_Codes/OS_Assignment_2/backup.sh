#!/bin/bash

mkdir -p backup

version=1

while [ -d "backup/v$version" ]
do
    version=$((version + 1))
done

mkdir "backup/v$version"

count=0

for file in *.c
do
    if [ -f "$file" ]; then
        cp "$file" "backup/v$version/"
        echo "Copied $file"
        count=$((count + 1))
    fi
done

echo "Backup created: v$version"

versions=$(find backup -maxdepth 1 -type d -name "v*" | wc -l)
size=$(du -sh backup | cut -f1)

echo "Total backup versions: $versions"
echo "Total backup size: $size"
