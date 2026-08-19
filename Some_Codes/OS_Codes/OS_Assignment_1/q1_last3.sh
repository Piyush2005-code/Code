#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Error: '$1' is not a regular file."
    exit 1
fi

echo "File: $1"
tail -n 3 -- "$1"
