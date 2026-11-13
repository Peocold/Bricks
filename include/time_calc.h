#include <stdio.h>
#include <time.h>

typedef struct time_diff_t
{
    int sec;
    int min;
    int hour;
} time_diff;

time_diff Get_Time(__uint8_t *open_state);