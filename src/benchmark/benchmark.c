#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark.h"
#include "data_loader.h"
#include "sorting/insertion_sort.h"

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
    for (int i = 0; i < count; i++)
    {
        char filename[100];

        snprintf(filename, sizeof(filename), "data/input/random/random_%d.txt", sizes[i]);

        run_benchmark(filename, sizes[i]);
    }
}


static void benchmark_insertion_sort(const int *data, int size)
{

    int *working_data = malloc(size * sizeof(int));

    if (working_data == NULL)
    {
        perror("Erreur d'allocation memoire");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        working_data[i] = data[i];
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

    printf("Insertion Sort | n = %d | %.6f s | Comparaisons = %lld | Deplacements = %lld\n", size, time_taken, stats.comparisons, stats.moves);

    free(working_data);
}