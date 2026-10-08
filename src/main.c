#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_generator.h"

int main(void) 
{

    srand(time(NULL));

    int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < count; i++) {

        char filename[100];

        snprintf(filename, sizeof(filename), "data/input/random/random_%d.txt", sizes[i]);
        generate_random_data(filename, sizes[i], 1000);
    }

    return 0;
}