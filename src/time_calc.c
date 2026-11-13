#include <stdio.h>
#include <time_calc.h>

static time_t open_timeinfo;

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