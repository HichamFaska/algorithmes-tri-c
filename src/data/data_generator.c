#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_generator.h"

void generate_random_data(const char *filename, int size, int max_value)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    for (int i = 0; i < size; i++) {
        int value = rand() % max_value;

        fprintf(file, "%d\n", value);
    }

    fclose(file);
}