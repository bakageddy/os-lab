#!/usr/bin/env sh

clear
echo -n "Which multiplication table"
read n
clear

for x in `seq 10`;
do
    p=`expr $x \* $n`
    echo "$n x $x = $p"
    sleep 1
done
