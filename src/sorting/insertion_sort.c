#include "sorting/insertion_sort.h"

SortStats insertion_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    for (int i = 1; i < size; i++)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0)
        {
            stats.comparisons++;
            if (data[j] <= key)
            {
                break;
            }
            data[j + 1] = data[j];
            stats.moves++;
            j--;
        }

        data[j + 1] = key;
        stats.moves++;
    }

    return stats;
}