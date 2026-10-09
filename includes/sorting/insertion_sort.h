#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sorting/sort_stats.h"
/*
 * Trie le tableau en ordre croissant.
 * Retourne une structure SortStats qui contient le nombre de comparaisons et de déplacements.
 */
SortStats insertion_sort(int *data, int size);

#endif