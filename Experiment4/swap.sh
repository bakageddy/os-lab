#!/usr/bin/env sh

echo -n "Enter value for A: "
read a

echo -n "Enter value for B: "
read b

t=$a
a=$b
b=$t

echo "A value is $a and B value is $b"

