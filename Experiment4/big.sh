#!/usr/bin/env sh

echo -n "Give value for A, B, C: "
read a b c

if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "A is the biggest number"
elif [ $b -gt $a ] && [ $b -gt $c ]
then
    echo "B is the biggest number"
else
    echo "C is the biggest number"
fi
