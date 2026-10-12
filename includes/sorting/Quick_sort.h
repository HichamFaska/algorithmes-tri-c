#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stddef.h>

/* Si SortStats est deja defini dans bubble_sort.h, supprimez ce bloc
   et incluez plutot le header qui le contient. */
#ifndef SORT_STATS_DEFINED
#define SORT_STATS_DEFINED
typedef struct
{
    long long comparisons;
    long long moves;
} SortStats;
#endif

SortStats quick_sort(int *data, size_t size);

#endif /* QUICK_SORT_H */