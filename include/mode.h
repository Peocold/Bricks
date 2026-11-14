#ifndef __MODE_H
#define __MODE_H

#include <time_calc.h>
#include <stdio.h>

typedef enum
{
    START,
    PAUSE,
    OVER,
    EXIT,
} MODE;

typedef struct Game_State_t
{
    int score;
    uint8_t start;
    double next_time;
    MODE mode;
    Time_Diff Time_Display;
} Game_State;

void Game_Start(int *key_input);

extern Game_State Bricks_State;

#endif