#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include <time_calc.h>
#include <input.h>
#include <print.h>

int main(void)
{
    Term_Init();
    Windows_Sizeset();
    Bricks_State.next_time = Now_Second();

    int keyboard_input=0;
    
    while(1)
    {
        Refresh(&Bricks_State.next_time, 30);
        Bricks_State.Time_Display = Get_Time(&(Bricks_State.start));
        printf("已运行%d时%d分%d秒\n",Bricks_State.Time_Display.hour,
               Bricks_State.Time_Display.min,Bricks_State.Time_Display.sec);
        keyboard_input = Read_Key();
        if(keyboard_input == KEY_EXIT)
        {
            break;
        }
    }
    Term_Restore();
    return 0;
}