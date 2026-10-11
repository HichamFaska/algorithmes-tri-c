#include "sorting/heap_sort.h"

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify(int *data, int size, int root, SortStats *stats)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size)
    {
        stats->comparisons++;

        if (data[left] > data[largest])
            largest = left;
    }

    if (right < size)
    {
        stats->comparisons++;

        if (data[right] > data[largest])
            largest = right;
    }

    if (largest != root)
    {
        swap(&data[root], &data[largest]);
        stats->moves += 2;

        heapify(data, size, largest, stats);
    }
}

SortStats heap_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(data, size, i, &stats);

    for (int i = size - 1; i > 0; i--)
    {
        swap(&data[0], &data[i]);
        stats.moves += 2;

        heapify(data, i, 0, &stats);
    }

    return stats;
}
