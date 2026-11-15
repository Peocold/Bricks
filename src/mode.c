#include <stdio.h>
#include <print.h>
#include <time_calc.h>
#include <input.h>
#include <mode.h>

Game_State Bricks_State=
{
    .score = 0,
    .mode = START,
    .start = 0,
    .next_time = 0,
};

void Game_Start(int *key_input)
{
    if(Bricks_State.start == 0)
    {
        Bricks_State.score = 0;
        Plane.x = Plane.y = 16;
        Print_Content[Plane.y][Plane.x] = Print_Content[Plane.y][Plane.x+1] = '=';
        Bricks_State.start = 1;
    }
    Plane_PosiCtrl(*key_input);
    Refresh_Bullet(*key_input);
    Refresh_Brick();
    Screen_Print(Print_Content);
}
