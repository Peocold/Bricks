#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time_calc.h>
#include <input.h>
#include <print.h>
#include <mode.h>

int main(void)
{
    Term_Init();
    Windows_Init();
    int key_input=0;
    
    while(1)
    {
        Time_Refresh(&Bricks_State.next_time, 60);
        key_input = Read_Key();
        State_Update(key_input);
        Time_Display();
        switch(Bricks_State.mode)
        {
            case START:
                Game_Start(&key_input);
                break;
            case PAUSE:
                break;
            case OVER: default:
                Bricks_State.start = 0;
                break;
        }
        if(Bricks_State.mode == EXIT)
        {
            break;
        }
        if(Bricks_State.mode == OVER)
        {
            for(int i = 0; i < 17; i++)
            {
                for(int j = 0; j < 36; j++)
                {
                    Print_Content[i][j] = ' ';
                }
                Print_Content[i][36] = '\0';
            }
            Screen_Print(Print_Content);
        }
    }
    Term_Restore();
    return 0;
}