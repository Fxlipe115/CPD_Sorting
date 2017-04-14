set xlabel "Elementos (n)"
set ylabel "Tempo (s)"
set format x "%.0f"
set format y "%.3f"
set xrange [0:1000000]
set yrange [0:60]
set xtics 100000
set ytics 1
plot "Shell1_time.plt" using 1:2 with linespoints title "Shell Sort 3h+1",\
	"Shell2_time.plt" using 1:2 with linespoints title "Shell Sort 2h",\
	"Bubble_time.plt" using 1:2 with linespoints title "Bubble Sort"