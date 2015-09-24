set terminal pngcairo size 1280,980 enhanced font 'Verdana,7'
set style line 1 lc rgb '#0060ad' lt 1 lw 1 pt 1 ps 1.5
set output "/tmp/plot.png"
set xtics rotate

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#99bbff"

nth(countCol,labelCol,n) = \
  ((int(column(countCol)) % n == 0) ? stringcolumn(labelCol) : "")

plot '/tmp/plot.dat' using 1:2:xtic(nth(1,3,SKIP)) with line ti "NAME"

