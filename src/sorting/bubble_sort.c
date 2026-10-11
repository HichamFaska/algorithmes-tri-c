#include "sorting/bubble_sort.h"

SortStats bubble_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - 1 - i; j++)
        {
            stats.comparisons++;

            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                stats.moves += 2;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }

    return stats;
}
