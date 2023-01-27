#!/usr/bin/env sh

echo -n "Key in a lower case character: "
read c

case $c in
    a|e|i|o|u)
        echo "It's a vowel";;
    *)
        echo "It's a consonant";;
esac
