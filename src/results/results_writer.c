
#include <stdio.h>

#include "results_writer.h"

/*
 * Crée un nouveau CSV et écrit son en-tête.
 */
int initialize_results_file(const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        perror("Erreur lors de la creation du CSV");
        return 0;
    }

    if (fprintf(file, "algorithm,size,time_seconds,comparisons,moves\n") < 0)
    {
        perror("Erreur lors de l'ecriture de l'en-tete du CSV");
        fclose(file);
        return 0;
    }

    if (fclose(file) != 0)
    {
        perror("Erreur lors de la fermeture du CSV");
        return 0;
    }

    return 1;
}


int append_result(const char *filename, const char *algorithm, int size, double time_taken, SortStats stats)
{
    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du CSV");
        return 0;
    }

    int result = fprintf(file, "%s,%d,%.9f,%lld,%lld\n", algorithm, size, time_taken, stats.comparisons, stats.moves);

    if (result < 0)
    {
        perror("Erreur lors de l'ecriture du CSV");
        fclose(file);
        return 0;
    }

    if (fclose(file) != 0)
    {
        perror("Erreur lors de la fermeture du CSV");
        return 0;
    }

    return 1;
}
