#!/bin/bash

cat - | sed -re "s/([^ ]+) ([^ ]+)/\2 \1/g" > /tmp/plot.dat

awk '{printf("%d %s\n", NR, $0)}' /tmp/plot.dat | sponge /tmp/plot.dat

cnt=`wc -l /tmp/plot.dat | cut -d " " -f 1`

echo "datapoints $cnt"

tgt=$(( $cnt / 100 ))

if [ $tgt -le 1 ]; then
  tgt=1
fi

echo target $tgt

mv $1.png $1.1.png

cat ~/bin/blobutils/plot.gp | sed -re "s/NAME/$1/g" -e "s/SKIP/$tgt/g" | gnuplot - && feh /tmp/plot.png

mv /tmp/plot.png "$1".png
