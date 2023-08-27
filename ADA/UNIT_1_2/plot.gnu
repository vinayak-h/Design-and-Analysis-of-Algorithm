set xlabel "Input size"
set ylabel "Time taken(secs)"
set title "Time Efficiency of Selection Sort"
plot "plot-data.txt" u 1:2 w lp pt 1 title 'Actual Time', '' u 1:3 w lp pt 1 title 'Estimated Time'
set term png
set output "sorteff.png"
replot
