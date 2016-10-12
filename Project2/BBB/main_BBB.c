#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "string.h"

int main()
{
	BBB_memory_profiler();
	BBB_data_profiler();
	BBB_print_profiler();
	return 0;
}
