#!/bin/bash

echo "Enter a number:"
read n

k=$n
s=0

while [ $k -ne 0 ]
do
    r=`expr $k % 10`
    s=`expr $s \* 10 + $r`
    k=`expr $k / 10`
done

if [ $s -eq $n ]
then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi

