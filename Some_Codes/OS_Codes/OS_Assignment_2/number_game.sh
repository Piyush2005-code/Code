#!/bin/bash

number=$((RANDOM % 50 + 1))
attempts=0

while true
do
    read -p "Guess the number: " guess
    attempts=$((attempts + 1))

    if [ $guess -gt $number ]; then
        echo "Too High"
    elif [ $guess -lt $number ]; then
        echo "Too Low"
    else
        echo "Correct!"

        if [ $attempts -le 3 ]; then
            echo "Expert"
        elif [ $attempts -le 6 ]; then
            echo "Good"
        else
            echo "Keep Practising"
        fi

        break
    fi
done
