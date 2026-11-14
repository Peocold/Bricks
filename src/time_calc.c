#include <stdio.h>
#include <time_calc.h>

static time_t open_timeinfo;

double Now_Second(void);
void Sleep_Second(double);

time_diff Get_Time(__uint8_t *open_state)
{
    time_diff time_total = {0,0,0};
    time_t timeinfo = time(NULL);

    // 登游判断
    if(*open_state == 0)
    {
        open_timeinfo = timeinfo;
        (*open_state)++;
    }
    else
    {
        long diff = timeinfo - open_timeinfo;
        time_total.sec = (int)(diff % 60);
        time_total.min = (int)((diff % 3600) / 60);
        time_total.hour = (int)(diff / 3600);
    }
    return time_total;
}

double Now_Second(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec+ts.tv_nsec/1e9;
}

void Sleep_Second(double second)
{
    if(second <= 0) 
    {
        return;
    }
    struct timespec ts;
    // 截取秒得到剩余小数部分并换算成纳秒
    ts.tv_sec = (time_t)second;
    ts.tv_nsec = (long)((second - ts.tv_sec) * 1e9);
    nanosleep(&ts, NULL);
}

void Refresh(double *next_time, int rate)
{
    if(rate <= 0 || next_time == NULL)
    {
        return;
    }
    double T = 1.0/rate;
    *next_time += T;
    double diff = *next_time - Now_Second();
    if(diff > 0)
    {
        Sleep_Second(diff);
    }
    else if(diff < -T)
    {
        *next_time = Now_Second();
    }
    printf("\033[3J\033[H");
    fflush(stdout);
}