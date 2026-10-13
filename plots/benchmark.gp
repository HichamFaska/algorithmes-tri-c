# ------------------------------------------------------------
# Graphiques des benchmarks de tri
# Usage : load 'plots/benchmark.gp'   (depuis la racine du projet)
# ------------------------------------------------------------

datafile = 'results/raw/benchmarks.csv'
outdir   = 'results/plots/'

# Algorithmes (doivent correspondre exactement aux noms dans le CSV)
array algos[6] = ["Insertion Sort", "Bubble Sort", "Merge Sort", \
                  "Heap Sort", "Selection Sort", "Quick Sort"]

# Metriques : colonne du CSV, nom du fichier, label de l'axe Y
array cols[3]   = [3, 4, 5]
array files[3]  = ["temps", "comparaisons", "deplacements"]
array labels[3] = ["Temps d'execution (s)", "Nombre de comparaisons", \
                   "Nombre de deplacements"]

set datafile separator ','
set terminal pngcairo size 1000,650 enhanced font 'Sans,11'
set logscale xy
set grid
set key left top
set xlabel "Taille du tableau (n)"
set style data linespoints

do for [m=1:3] {
    set output outdir . files[m] . '.png'
    set title labels[m] . " selon la taille du tableau"
    set ylabel labels[m]

    plot for [a=1:6] datafile using 2:cols[m] \
         if (strcol(1) eq algos[a]) \
         title algos[a] pt 7 ps 1
}

unset output
print "Graphiques generes dans ".outdir