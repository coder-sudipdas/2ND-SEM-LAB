#!/bin/bash

echo "Enter a number:"
read n

rem=`expr $n % 2`

if [ $rem -eq 0 ]
then
    echo "Even Number"
else
    echo "Odd Number"
fi

