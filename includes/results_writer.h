#ifndef RESULTS_WRITER_H
#define RESULTS_WRITER_H

#include "sorting/sort_stats.h"

int initialize_results_file(const char *filename);

int append_result(const char *filename, const char *algorithm, int size, double time_taken, SortStats stats);

#endif