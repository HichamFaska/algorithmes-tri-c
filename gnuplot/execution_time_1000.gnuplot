
set datafile separator ","
set terminal pngcairo size 1920,1200 enhanced font "Arial,16"
set output "results/graphs/execution_time_1000.png"

set title "Comparaison des temps d'execution (n <= 1000)"
set xlabel "Taille du tableau (n)"
set ylabel "Temps d'execution (ms)"
set yrange [0:*]
set ytics 0.1
set grid
set key outside right
set samples 1000

file = "results/raw/benchmarks.csv"

c1 = "#cc0000"
c2 = "#0000cc"
c3 = "#006600"
c4 = "#cc6600"
c5 = "#660099"
c6 = "#007777"

plot \
    file every 6::1 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c1 title "Insertion Sort", \
    file every 6::1 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c1 smooth csplines notitle, \
    file every 6::2 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c2 title "Bubble Sort", \
    file every 6::2 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c2 smooth csplines notitle, \
    file every 6::3 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c3 title "Merge Sort", \
    file every 6::3 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c3 smooth csplines notitle, \
    file every 6::4 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c4 title "Heap Sort", \
    file every 6::4 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c4 smooth csplines notitle, \
    file every 6::5 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c5 title "Selection Sort", \
    file every 6::5 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c5 smooth csplines notitle, \
    file every 6::6 using (($2<=1000)?$2:NaN):($3*1000) with points pt 7 ps 1.5 lc rgb c6 title "Quick Sort", \
    file every 6::6 using (($2<=1000)?$2:NaN):($3*1000) with lines lw 2 lc rgb c6 smooth csplines notitle

set output
