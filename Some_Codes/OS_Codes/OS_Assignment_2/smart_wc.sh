#!/bin/bash

file=$1

if [ ! -f "$file" ]; then
    echo "File does not exist"
    exit 1
fi

lines=$(wc -l < "$file")
words=$(wc -w < "$file")
chars=$(wc -m < "$file")

longest=$(awk '{ if (length > max) { max=length; line=NR; text=$0 } } END { print line "|" text }' "$file")

line_no=$(echo "$longest" | cut -d'|' -f1)
line_text=$(echo "$longest" | cut -d'|' -f2-)

word=$(tr ' ' '\n' < "$file" | tr -cd '[:alnum:]\n' | tr '[:upper:]' '[:lower:]' |
sort | uniq -c | sort -nr | head -1)

count=$(echo "$word" | awk '{print $1}')
most_word=$(echo "$word" | awk '{print $2}')

echo "File : $file"
echo "Lines : $lines"
echo "Words : $words"
echo "Characters : $chars"
echo "Longest Line : Line $line_no -> \"$line_text\""
echo "Most Frequent : \"$most_word\" (appears $count times)"
