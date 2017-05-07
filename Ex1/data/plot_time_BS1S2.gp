set xlabel "Elementos (n)"
set ylabel "Tempo (segundos)"
set format x "%.0f"
set format y "%.0f"
set xrange [0:1000000]
set yrange [0:60]
set xtics 100000
set ytics 2
plot "times/Shell1_time.data" using 1:2 with linespoints title "Shell Sort 3h+1",\
	"times/Shell2_time.data" using 1:2 with linespoints title "Shell Sort 2h",\
	"times/Bubble_time.data" using 1:2 with linespoints title "Bubble Sort"
