#include "sorting/insertion_sort.h"

void insertion_sort(int *data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}