#include <stdio.h>
#include <stdlib.h>
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
    fflush(stdout);
}

void Tank_PosiCtrl(int key_input)
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

void Refresh_Bullet(int key_input)
{
    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 36; j++)
        {
            if(Print_Content[i][j] == '|')
            {
                Print_Content[i][j] = ' ';
                if(i > 0)
                {
                    Print_Content[i-1][j] = '|';
                }
            }
        }
    }
    if(Plane.y > 0)
    {
        for(int i = 0; i < 1 && (key_input == 'j' || key_input == 'J'); i++)
        {
            Print_Content[Plane.y-1][Plane.x] = '|';
            Print_Content[Plane.y-1][Plane.x+1] = '|';
        }

    }
}

void Refresh_Brick(void)
{
    static double next_spawn = 0;
    double now = Now_Second();
    if(now >= next_spawn)
    {
        for(int i = 15; i >= 0; i--)
        {
            for(int j = 0; j < 36; j++)
            {
                if(Print_Content[i][j] == '-')
                {
                    Print_Content[i][j] = ' ';
                    Print_Content[i+1][j] = '-';
                }
            }
        }
        next_spawn = now + 1.0;
        for(int i = 0; i < 5; i++)
        {
            Print_Content[0][rand() % 36] = '-';
        }
    }
}