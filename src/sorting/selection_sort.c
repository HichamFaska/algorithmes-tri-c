#include "sorting/selection_sort.h"

SortStats selection_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            stats.comparisons++;
            if (data[j] < data[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int temp = data[min_index];
            data[min_index] = data[i];
            data[i] = temp;

            stats.moves += 2;
        }
    }

    return stats;
}
