#include <stdio.h>
#include <stdlib.h>

#include "data_loader.h"

int *load_data(const char *filename, int size)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    int *data = malloc(size * sizeof(int));

    if (data == NULL)
    {
        fclose(file);
        perror("Erreur d'allocation mémoire");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        if (fscanf(file, "%d", &data[i]) != 1)
        {
            fprintf(stderr, "Erreur : '%s' contient moins de %d valeurs (a l'index %d)\n", filename, size, i);
            free(data);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);

    return data;
}