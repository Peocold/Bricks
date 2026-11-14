#ifndef __TIME_CALC_H
#define __TIME_CALC_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct time_diff_t
{
    int sec;
    int min;
    int hour;
} time_diff;

time_diff Get_Time(uint8_t *open_state);
double Now_Second(void);
void Sleep_Second(double);
void Refresh(double *next_time, int rate);

#endif