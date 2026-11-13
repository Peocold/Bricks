#include <stdio.h>
#include <unistd.h>
#include <time_calc.h>

int main(void)
{
    printf("\033[H\033[2J");
    fflush(stdout);
    __uint8_t first_open=0;
    time_diff Time_Display;
    for(int i = 0; i < 10; i++)
    {
        Time_Display = Get_Time(&first_open);
        printf("已运行了 %2d %2d %2d\n",Time_Display.hour,Time_Display.min,Time_Display.sec);
        sleep(1);
    }
    return 0;
}