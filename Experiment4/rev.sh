#!/usr/bin/env sh

echo -n "Enter a number: "
read num
rd=0
while [ $num -gt 0 ]; do
    rem=`expr $num % 10`
    rd=`expr $rd \* 10 + $rem`
    num=`expr $num / 10`
done
echo "Reversed number: $rd"
