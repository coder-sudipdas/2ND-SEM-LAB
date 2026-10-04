#!/bin/bash

echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

echo "Enter your choice:"
read i

echo "Enter two numbers:"
read x y

case $i in
1)
    z=`expr $x + $y`
    echo "Sum = $z"
    ;;
2)
    z=`expr $x - $y`
    echo "Difference = $z"
    ;;
3)
    z=`expr $x \* $y`
    echo "Product = $z"
    ;;
4)
    z=`expr $x / $y`
    echo "Division = $z"
    ;;
*)
    echo "Invalid Choice"
    ;;
esac
