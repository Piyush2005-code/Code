#!/bin/bash

dir=$1

if [ ! -d "$dir" ]; then
    echo "Directory does not exist"
    exit 1
fi

total=0
count=0

echo "Filename Size Lines Last Modified"
echo "-----------------------------------------------"

for file in "$dir"/*.txt
do
    if [ ! -f "$file" ]; then
        continue
    fi

    name=$(basename "$file")
    size=$(du -h "$file" | cut -f1)
    lines=$(wc -l < "$file")
    date=$(date -r "$file" "+%Y-%m-%d")

    echo "$name $size $lines $date"

    bytes=$(wc -c < "$file")
    total=$((total + bytes))
    count=$((count + 1))
done

echo "-----------------------------------------------"

if [ $count -eq 0 ]; then
    echo "No .txt files found"
else
    total_size=$(numfmt --to=iec "$total")
    echo "Total Size: $total_size across $count file(s)"
fi
