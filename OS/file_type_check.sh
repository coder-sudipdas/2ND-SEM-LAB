#!/bin/bash

echo "Enter a file name:"
read x

if [ -f "$x" ]
then
    echo "This is an ordinary file"

elif [ -d "$x" ]
then
    echo "This is a directory"

elif [ -s "$x" ]
then
    echo "This is a non-empty file"

elif [ -r "$x" ]
then
    echo "This is a readable file"

elif [ -x "$x" ]
then
    echo "This is an executable file"

elif [ -w "$x" ]
then
    echo "This is a writable file"

else
    echo "File does not exist or no matching file type found"
fi
