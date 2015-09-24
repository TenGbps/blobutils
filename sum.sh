sum=0
while read x
do
    sum1=`echo $sum+$x | bc -l`
    if [ -n "$sum1" ]; then
      sum=$sum1
    fi
done
echo $sum

exit 0

sum=0
while read x
do
    let sum=$sum+$x
done
echo $sum

