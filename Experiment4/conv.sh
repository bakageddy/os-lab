#!/usr/bin/env sh

echo -n "Enter fahrenheit: "
read f
# c=$(expr ($f - 32) * (5 / 9))
min32=$(expr $f - 32)
times5=$(expr $min32 \* 5)
divide9=$(expr $times5 / 9)
echo "Centigrade is: $divide9"
