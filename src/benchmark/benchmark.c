#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark.h"
#include "data_loader.h"
#include "sorting/insertion_sort.h"
#include "results_writer.h"

#define RESULTS_FILE "results/raw/insertion_sort.csv"

static void benchmark_insertion_sort(const int *data, int size);

void run_benchmark(const char *filename, int size)
{
    /*
     * Charger les données originales
     */
    int *data = load_data(filename, size);

    if (data == NULL)
    {
        return;
    }

    /*
     * Appeler le benchmark de chaque algorithme.
     */
    benchmark_insertion_sort(data, size);

    /*
     * Les autres appels seront ajoutés progressivement :
     *
     * benchmark_bubble_sort(data, size);
     * benchmark_selection_sort(data, size);
     * benchmark_merge_sort(data, size);
     * benchmark_quick_sort(data, size);
     * benchmark_heap_sort(data, size);
     */

    /*
     * Libérer les données originales
     */
    free(data);
}

void run_all_benchmarks(const int sizes[], int count)
{
    if (!initialize_results_file(RESULTS_FILE))
    {
        fprintf(stderr, "Impossible d'initialiser les resultats.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        char filename[100];

        snprintf(filename, sizeof(filename), "data/input/random/random_%d.txt", sizes[i]);

        run_benchmark(filename, sizes[i]);
    }
}


static void benchmark_insertion_sort(const int *data, int size)
{

    int *working_data = copy_data(data, size);

    if (working_data == NULL)
    {
        return;
    }

    clock_t start = clock();

    SortStats stats = insertion_sort(working_data, size);

    clock_t end = clock();

    if (start == (clock_t)-1 || end == (clock_t)-1)
    {
        fprintf(stderr, "Erreur lors de la mesure du temps.\n");
        free(working_data);
        return;
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (!append_result(RESULTS_FILE, "Insertion Sort", size, time_taken, stats))
    {
        fprintf(stderr, "Impossible d'enregistrer les resultats.\n");
    }

    printf("Insertion Sort | n = %d | %.6f s | Comparaisons = %lld | Deplacements = %lld\n", size, time_taken, stats.comparisons, stats.moves);

    free(working_data);
}