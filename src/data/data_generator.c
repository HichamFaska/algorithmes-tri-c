#include <stdio.h>
#include <stdlib.h>

#include "data_generator.h"

void generate_random_data(const char *filename, int size, int max_value)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        int value = rand() % max_value;

        fprintf(file, "%d\n", value);
    }

    fclose(file);
}

void generate_random_datasets(const int sizes[], int count, int max_value)
{
    for (int i = 0; i < count; i++)
    {
        char filename[100];

        snprintf(
            filename,
            sizeof(filename),
            "data/input/random/random_%d.txt",
            sizes[i]
        );

        generate_random_data(
            filename,
            sizes[i],
            max_value
        );
    }
}