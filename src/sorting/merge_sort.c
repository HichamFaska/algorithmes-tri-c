#include "sorting/merge_sort.h"

void fusion(int *data, int gauche, int milieu, int droite, SortStats *stats)
{
    int temp[droite - gauche + 1];
    int i = gauche, j = milieu + 1, k = 0;

    while (i <= milieu && j <= droite)
    {
        (*stats).comparisons++;

        if (data[i] <= data[j])
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];

        (*stats).moves++;
    }

    while (i <= milieu)
    {
        temp[k++] = data[i++];
        (*stats).moves++;
    }

    while (j <= droite)
    {
        temp[k++] = data[j++];
        (*stats).moves++;
    }

    for (i = gauche, k = 0; i <= droite; i++, k++)
    {
        data[i] = temp[k];
        (*stats).moves++;
    }
}

void tri_fusion(int *data, int gauche, int droite, SortStats *stats)
{
    if (gauche >= droite)
        return;

    int milieu = (gauche + droite) / 2;

    tri_fusion(data, gauche, milieu, stats);
    tri_fusion(data, milieu + 1, droite, stats);

    fusion(data, gauche, milieu, droite, stats);
}

SortStats merge_sort(int *data, int size)
{
    SortStats stats = {0, 0};

    if (size > 1)
        tri_fusion(data, 0, size - 1, &stats);

    return stats;
}
