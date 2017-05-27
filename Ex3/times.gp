set xlabel "Elementos (n)"
set ylabel "Tempo (segundos)"
set format x "%.0f"
set format y "%.4f"
set xrange [100:1000]
set yrange [0:.0002]
set xtics 100
set ytics .00001
plot "times.data" using 1:2 with linespoints title "Merge Sort",\
	"times.data" using 1:3 with linespoints title "Hybrid Sort k=10",\
	"times.data" using 1:4 with linespoints title "Insertion Sort"
