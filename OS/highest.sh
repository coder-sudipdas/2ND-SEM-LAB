#!/bin/bash
echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter third number:"
read c

if [ $a -ge $b ] && [ $a -ge $c ]
then
    echo "Highest number = $a"
elif [ $b -ge $a ] && [ $b -ge $c ]
then
    echo "Highest number = $b"
else
    echo "Highest number = $c"
fi

