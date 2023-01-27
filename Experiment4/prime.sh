echo -n "Enter a number: "
read num

i=2
m=`expr $num / 2`

while [ $i -lt $m ]
do
    q=`expr $num % $i`
    if [ $q -eq 0 ]
    then
        echo "Not a prime number"
        exit
    fi
    i=`expr $i + 1`
done
echo "Prime number"
