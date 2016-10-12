#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "memory.h"
#include "string.h"
#include "BBB_Profiler.h"

int BBB_memory_profiler(void) // profiler to calculate time for all memory functions
{
int i;
uint8_t src[5000], dst[5000];
struct timeval my_memmove_start,my_memmove_end,memmove_start,memmove_end,my_memzero_start,my_memzero_end,memset_start,memset_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_memmove_start, NULL); // gets time in the start
my_memmove(src,dst,length); // executes function my_memove
gettimeofday(&my_memmove_end, NULL);// gets time in the end
secs  = my_memmove_end.tv_sec  - my_memmove_start.tv_sec;
usecs = my_memmove_end.tv_usec - my_memmove_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_memove for %d bytes: %ld usec\n", length,time);

gettimeofday(&memmove_start, NULL); 
memmove(src,dst,length); // executes memmove_function
gettimeofday(&memmove_end, NULL);
secs  = memmove_end.tv_sec  - memmove_start.tv_sec;
usecs = memmove_end.tv_usec - memmove_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for memmove for %d bytes: %ld usec\n", length,time);

gettimeofday(&my_memzero_start,NULL);
my_memzero(src,length);// executes my_memzero function
gettimeofday(&my_memzero_end, NULL);
secs  = my_memzero_end.tv_sec  - my_memzero_start.tv_sec;
usecs = my_memzero_end.tv_usec - my_memzero_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_memzero for %d bytes: %ld usec\n", length,time);

gettimeofday(&memset_start,NULL);
memset(src,0,length);//executes memset function
gettimeofday(&memset_end, NULL);
secs  = memset_end.tv_sec  - memset_start.tv_sec;
usecs = memset_end.tv_usec - memset_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for memset for %d bytes: %ld usec\n", length,time);

gettimeofday(&my_reverse_start,NULL);
my_reverse(src,0,length);// executes my_reverse function
gettimeofday(&my_reverse_end,NULL);
secs  = my_reverse_end.tv_sec  - my_reverse_start.tv_sec;
usecs = my_reverse_end.tv_usec - my_reverse_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_reverse for %d bytes: %ld usec\n", length,time);


return 0;
}

int BBB_data_profiler(void)// profiler fo all data functions
{
int i;
uint8_t src[5000], dst[5000];
struct timeval my_atoi_start,my_atoi_end, atoi_start, atoi_end, my_itoa_start, my_itoa_end, my_ftoa_start, my_ftoa_end;
long time,mtime, secs, usecs;

gettimeofday(&my_atoi_start, NULL);
my_atoi(src);// executes my_atoi function
gettimeofday(&my_atoi_end, NULL);
secs  = my_atoi_end.tv_sec  - my_atoi_start.tv_sec;
usecs = my_atoi_end.tv_usec - my_atoi_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_atoi: %ld usec\n",time);


gettimeofday(&atoi_start, NULL);
atoi(src); //executes atoi function
gettimeofday(&atoi_end, NULL);
secs  = atoi_end.tv_sec  - atoi_start.tv_sec;
usecs = atoi_end.tv_usec - atoi_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for atoi : %ld usec\n",time);


gettimeofday(&my_itoa_start, NULL);
my_itoa(1234, src, 10);// executes my_itoa function
gettimeofday(&my_itoa_end, NULL);
secs  = my_itoa_end.tv_sec  - my_itoa_start.tv_sec;
usecs = my_itoa_end.tv_usec - my_itoa_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_itoa : %ld usec\n", time);


getimeofday(&my_ftoa_start, NULL);
ftoa(12.34, src, 3); // executes ftoa function
gettimeofday(&my_ftoa_end, NULL);
secs  = my_ftoa_end.tv_sec  - my_ftoa_start.tv_sec;
usecs = my_ftoa_end.tv_usec - my_ftoa_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_ftoa: %ld usec\n",time);

return 0;
}

int BBB_print_profiler(void)// profiler fo all printf types
{
int i;
uint8_t src[5000], dst[5000];
struct timeval my_print1_start,my_print1_end,my_print2_start, my_print2_end, my_print3_start, my_print3_end,my_print4_start,my_print4_end;
long time,mtime, secs, usecs;
int32_t x=1234;
float y=12.34;
char str[100]="Test";
int32_t length=10;
gettimeofday(&my_print1_start, NULL);
printf("TESTCHARACTERSPRINTUSINGPROFILER");// printf of 20 characters
gettimeofday(&my_print1_end, NULL);
secs  = my_print1_end.tv_sec  - my_print1_start.tv_sec;
usecs = my_print1_end.tv_usec - my_print1_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of 20 characters: %ld usec\n", time);

gettimeofday(&my_print2_start, NULL);
printf("%d\n",x);// printf of 1 variable
gettimeofday(&my_print2_end, NULL);
secs  = my_print2_end.tv_sec  - my_print2_start.tv_sec;
usecs = my_print2_end.tv_usec - my_print2_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of one character: %ld usec\n", time);


gettimeofday(&my_print3_start, NULL);
printf("%d\t%f\n",x,y);// printf of 2 variables
gettimeofday(&my_print3_end, NULL);
secs  = my_print3_end.tv_sec  - my_print3_start.tv_sec;
usecs = my_print3_end.tv_usec - my_print3_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of two variables: %ld usec\n", time);

gettimeofday(&my_print4_start, NULL);
printf("%d\t%f\t,%s\n",x,y,str);//printf of 3 variables
gettimeofday(&my_print4_end, NULL);
secs  = my_print4_end.tv_sec  - my_print4_start.tv_sec;
usecs = my_print4_end.tv_usec - my_print4_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of three variables: %ld usec\n", time);

return 0;
}
