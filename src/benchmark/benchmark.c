#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "benchmark.h"
#include "data_loader.h"
#include "sorting/insertion_sort.h"
#include "sorting/bubble_sort.h"
#include "sorting/merge_sort.h"
#include "sorting/heap_sort.h"
#include "sorting/selection_sort.h"
#include "sorting/quick_sort.h"
#include "results_writer.h"

#define RESULTS_FILE "results/raw/benchmarks.csv"

/*
 * Les algorithmes O(n log n) sont rapides : on peut repeter davantage.
 * Les algorithmes O(n^2) sont lents : on limite les repetitions.
 */
#define FAST_REPETITIONS 7
#define SLOW_REPETITIONS 3

typedef SortStats (*SortFunction)(int *data, int size);

static double get_time_seconds(void)
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER counter;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);

    return (double)counter.QuadPart / (double)frequency.QuadPart;
}

static double compute_median(double *values, int count)
{
    for (int i = 1; i < count; i++)
    {
        double key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j--;
        }

        values[j + 1] = key;
    }

    return values[count / 2];
}

static void benchmark_algorithm(const char *name, SortFunction sort, const int *data, int size, int repetitions)
{
    int *working_data[repetitions];

    for (int i = 0; i < repetitions; i++)
    {
        working_data[i] = copy_data(data, size);

        if (working_data[i] == NULL)
        {
            fprintf(stderr, "Erreur d'allocation memoire.\n");

            for (int j = 0; j < i; j++)
            {
                free(working_data[j]);
            }

            return;
        }
    }

    double times[repetitions];
    SortStats stats = {0, 0};

    for (int i = 0; i < repetitions; i++)
    {
        double start = get_time_seconds();

        SortStats current_stats = sort(working_data[i], size);

        double end = get_time_seconds();

        times[i] = end - start;

        if (i == 0)
        {
            stats = current_stats;
        }
    }

    double time_taken = compute_median(times, repetitions);

    if (!append_result(RESULTS_FILE, name, size, time_taken, stats))
    {
        fprintf(stderr, "Impossible d'enregistrer les resultats.\n");
    }

    printf("%s | n = %d | %.9f s | Comparaisons = %lld | Deplacements = %lld\n", name, size, time_taken, stats.comparisons, stats.moves);

    for (int i = 0; i < repetitions; i++)
    {
        free(working_data[i]);
    }
}

static void benchmark_insertion_sort(const int *data, int size);
static void benchmark_bubble_sort(const int *data, int size);
static void benchmark_merge_sort(const int *data, int size);
static void benchmark_heap_sort(const int *data, int size);
static void benchmark_selection_sort(const int *data, int size);
static void benchmark_quick_sort(const int *data, int size);

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
    benchmark_bubble_sort(data, size);
    benchmark_merge_sort(data, size);
    benchmark_heap_sort(data, size);
    benchmark_selection_sort(data, size);
    benchmark_quick_sort(data, size);

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
    benchmark_algorithm("Insertion Sort", insertion_sort, data, size, SLOW_REPETITIONS);
}

static void benchmark_bubble_sort(const int *data, int size)
{
    benchmark_algorithm("Bubble Sort", bubble_sort, data, size, SLOW_REPETITIONS);
}

static void benchmark_merge_sort(const int *data, int size)
{
    benchmark_algorithm("Merge Sort", merge_sort, data, size, FAST_REPETITIONS);
}

static void benchmark_heap_sort(const int *data, int size)
{
    benchmark_algorithm("Heap Sort", heap_sort, data, size, FAST_REPETITIONS);
}

static void benchmark_selection_sort(const int *data, int size)
{
    benchmark_algorithm("Selection Sort", selection_sort, data, size, SLOW_REPETITIONS);
}

static void benchmark_quick_sort(const int *data, int size)
{
    benchmark_algorithm("Quick Sort", quick_sort, data, size, FAST_REPETITIONS);
}