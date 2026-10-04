#!/bin/bash

echo "Enter a string:"
read n

l=`expr length "$n"`
k=""

while [ $l -ge 1 ]
do
    m=`expr substr "$n" $l 1`
    k=$k$m
    l=`expr $l - 1`
done

if [ "$k" = "$n" ]
then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
