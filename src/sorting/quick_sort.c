#include <stddef.h>

#include "sorting/quick_sort.h"

/*
 * Echange deux elements du tableau.
 * Chaque ecriture dans le tableau compte comme un mouvement.
 */
static void swap(int *a, int *b, SortStats *stats)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    stats->moves += 2;
}

/*
 * Trie la portion data[low..high].
 * Le pivot est la valeur situee au milieu de la portion.
 */
static void quick_sort_recursive(
    int data[],
    int low,
    int high,
    SortStats *stats
)
{
    int i = low;
    int j = high;
    int pivot = data[low + (high - low) / 2];

    while (i <= j)
    {
        /*
         * Rechercher un element >= pivot depuis la gauche.
         */
        while (i <= high)
        {
            stats->comparisons++;

            if (data[i] >= pivot)
            {
                break;
            }

            i++;
        }

        /*
         * Rechercher un element <= pivot depuis la droite.
         */
        while (j >= low)
        {
            stats->comparisons++;

            if (data[j] <= pivot)
            {
                break;
            }

            j--;
        }

        if (i <= j)
        {
            if (i != j)
            {
                swap(&data[i], &data[j], stats);
            }

            i++;
            j--;
        }
    }

    if (low < j)
    {
        quick_sort_recursive(data, low, j, stats);
    }

    if (i < high)
    {
        quick_sort_recursive(data, i, high, stats);
    }
}

SortStats quick_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    if (data == NULL || size <= 1)
    {
        return stats;
    }

    quick_sort_recursive(data, 0, size - 1, &stats);

    return stats;
}