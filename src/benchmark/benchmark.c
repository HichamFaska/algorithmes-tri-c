#include <stdio.h>
#include <stdlib.h>

#include "benchmark.h"
#include "data_loader.h"
#include "sorting/insertion_sort.h"

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
     * Insertion Sort
     */
    int *insertion_data = malloc(size * sizeof(int));

    if (insertion_data == NULL)
    {
        free(data);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        insertion_data[i] = data[i];
    }

    insertion_sort(insertion_data, size);

    printf("Tri termine : n = %d\n", size);

    free(insertion_data);

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