#include <stdio.h>

#include "sorting/selection_sort.h"

int main(void)
{
    int data[] = {5, 3, 4, 1, 2};

    int size = sizeof(data) / sizeof(data[0]);

    SortStats stats = selection_sort(data, size);

    printf("Tableau trie : ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\nComparaisons : %lld\n", stats.comparisons);
    printf("Deplacements : %lld\n", stats.moves);

    return 0;
}