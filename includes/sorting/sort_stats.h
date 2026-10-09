#ifndef SORT_STATS_H
#define SORT_STATS_H

/*
 * Structure qui regroupe les statistiques d'un algorithme de tri.
 */
typedef struct
{
    long long comparisons;  // Nombre de comparaisons entre éléments
    long long moves; // Nombre d'écritures dans le tableau
} SortStats;

#endif