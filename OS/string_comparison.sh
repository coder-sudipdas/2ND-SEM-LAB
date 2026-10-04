#!/bin/bash

echo "Enter two strings:"
read s1 s2

if [ "$s1" = "$s2" ]
then
    echo "Strings are same"
else
    echo "Strings are different"
fi
