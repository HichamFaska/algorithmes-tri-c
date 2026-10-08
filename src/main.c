#include <stdlib.h>
#include <time.h>

#include "data_generator.h"

int main(void) 
{

    srand(time(NULL));
    generate_random_data("data/input/random_10.txt", 100, 100);

    return 0;
}