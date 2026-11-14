#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time_calc.h>
#include <input.h>

int main(void)
{
    uint8_t first_open=0;
    time_diff Time_Display;
    double next_time = Now_Second();
    int keyboard_input=0;

    Term_Init();
    while(1)
    {
        Refresh(&next_time, 30);
        Time_Display = Get_Time(&first_open);
        printf("已运行%d时%d分%d秒\n",Time_Display.hour,Time_Display.min,Time_Display.sec);
        keyboard_input = Read_Key();
        if(keyboard_input == KEY_EXIT)
        {
            break;
        }
    }
    Term_Restore();
    return 0;
}