#!/usr/bin/env sh

echo -n "Enter the mark: "
read mark
if [ $mark -gt 90 ] && [ $mark -lt 100 ]
then
    echo "S grade"
elif [ $mark -gt 80 ]
then
    echo "A grade"
elif [ $mark -gt 70 ]
then
    echo "B grade"
elif [ $mark -gt 60 ]
then
    echo "C grade"
elif [ $mark -gt 55 ]
then
    echo "D grade"
elif [ $mark -gt 50 ]
then
    echo "E grade"
else
    echo "U grade"
fi
