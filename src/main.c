#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "benchmark.h"
#include "data_generator.h"

int main(void) 
{

    srand(time(NULL));

    int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    generate_random_datasets(sizes, count, 1000);
    
    run_all_benchmarks(sizes, count);

    return 0;
}