set title "Simulacao volei"
set xlabel "Chance ponto time 1"
set ylabel "Vitorias em 10000 partidas"
set grid

set xrange [50:75]
set yrange [-10000:110000]

set term png
set output "chart.png"

plot "volei.dat" using 1:2 with lines title "Vitorias time 1",\
     "volei.dat" using 1:3 with lines title "Vitorias time 2"

