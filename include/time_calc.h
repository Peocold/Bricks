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

typedef enum
{
    START,
    GAME,
} MODE;

typedef struct Game_State_t
{
    uint8_t start;
    double next_time;
    MODE mode;
    Time_Diff Time_Display;
} Game_State;

Time_Diff Get_Time(uint8_t *open_state);
double Now_Second(void);
void Sleep_Second(double);
void Time_Refresh(double *next_time, int rate);
void Time_Display(void);
void Refresh_Bullet(void);

extern Game_State Bricks_State;

#endif