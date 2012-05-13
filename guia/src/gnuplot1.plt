set terminal png
set output "senyals.png"
set format y "%g%%"
plot\
"aptime.plt" using 1:2 title "prueba columna 1" with lines,\
"aptime.plt" using 1:3 title "prueba column 2" with lines,\
"aptime.plt" using 1:4 title "prueba column 3" with lines,\
"aptime.plt" using 1:5 title "prueba column 4" with lines,\
"aptime.plt" using 1:6 title "prueba column 5" with lines,\
"aptime.plt" using 1:7 title "prueba column 6" with lines
