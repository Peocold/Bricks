#ifndef __TIME_CALC_H
#define __TIME_CALC_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct Time_Diff_t
{
    int sec;
    int min;
    int hour;
} Time_Diff;

Time_Diff Get_Time(uint8_t *open_state);
double Now_Second(void);
void Sleep_Second(double);
void Time_Refresh(double *next_time, int rate);
void Time_Display(void);

#endif