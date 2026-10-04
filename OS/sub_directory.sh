#!/bin/bash

echo "Sub-directories under current directory are:"

for i in *
do
    if [ -d "$i" ]
    then
        echo "$i"
    fi
done


