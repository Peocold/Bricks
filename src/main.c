#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time_calc.h>
#include <input.h>
#include <print.h>

int main(void)
{
    Term_Init();
    Windows_Init();
    int key_input=0;
    while(1)
    {
        Time_Refresh(&Bricks_State.next_time, 60);
        Time_Display();
        key_input = Read_Key();
        Tank_PosiCtrl(key_input);
        Refresh_Bullet(key_input);
        Refresh_Brick();
        Screen_Print(Print_Content);

        if(key_input == KEY_EXIT)
        {
            break;
        }
    }
    Term_Restore();
    return 0;
}