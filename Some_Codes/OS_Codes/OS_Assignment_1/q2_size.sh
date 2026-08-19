#!/bin/bash

size() {
    if [ "$#" -ne 1 ]; then
        echo "Usage: size <file>"
        return 1
    fi

    if [ ! -e "$1" ]; then
        echo "Error: '$1' does not exist."
        return 1
    fi

    wc -c < "$1"
}

# Uncomment the following line to test directly:
# size "$1"
