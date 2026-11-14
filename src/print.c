#include <stdio.h>
#include <print.h>
#include <time_calc.h>

// 可动范围: 17行36列
char Print_Content[17][37];
Plane_t Plane=
{
    .x = 16,
    .y = 16,
};

void Windows_Init(void)
{
    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 36; j++)
        {
            Print_Content[i][j] = ' ';
        }
        Print_Content[i][36] = '\0';
    }
    // 记录初始时间
    Print_Content[Plane.y][Plane.x] = '=';
    Print_Content[Plane.y][Plane.x+1] = '=';
    Bricks_State.next_time = Now_Second();
    printf("\033[8;18;18t");
    fflush(stdout);
}

void Screen_Print(char Content[17][37])
{
    for(int i = 0; i < 17; i++)
    {
        if(i == 16)
        {
            printf("%s",Content[i]);
        }
        else
        {
            printf("%s\n",Content[i]);
        }
    }
}

void Tank_Ctrl(int key_input)
{
    switch (key_input)
    {
        case 'w': case 'W':
            if(Plane.y > 0)
            {
                Print_Content[Plane.y][Plane.x] = ' ';
                Print_Content[Plane.y][Plane.x+1] = ' ';
                Plane.y--;
                Print_Content[Plane.y][Plane.x] = '=';
                Print_Content[Plane.y][Plane.x+1] = '=';
            }
            break;
        case 's': case 'S':
            if(Plane.y < 16)
            {
                Print_Content[Plane.y][Plane.x] = ' ';
                Print_Content[Plane.y][Plane.x+1] = ' ';
                Plane.y++;
                Print_Content[Plane.y][Plane.x] = '=';
                Print_Content[Plane.y][Plane.x+1] = '=';
            }
            break;
        case 'a': case 'A':
            if(Plane.x > 0)
            {
                Print_Content[Plane.y][Plane.x] = ' ';
                Print_Content[Plane.y][Plane.x+1] = ' ';
                Plane.x--;
                Print_Content[Plane.y][Plane.x] = '=';
                Print_Content[Plane.y][Plane.x+1] = '=';
            }
            break;
        case 'd': case 'D':
            if(Plane.x < 34)
            {
                Print_Content[Plane.y][Plane.x] = ' ';
                Print_Content[Plane.y][Plane.x+1] = ' ';
                Plane.x++;
                Print_Content[Plane.y][Plane.x] = '=';
                Print_Content[Plane.y][Plane.x+1] = '=';
            }
            break; 
        default:
            break;
    }
}