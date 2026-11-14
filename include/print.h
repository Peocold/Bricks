#ifndef __PRINT_H
#define __PRINT_H

#include <stdio.h>
#include <stdint.h>

typedef struct Plane_struct_t
{
    uint8_t x;
    uint8_t y;
} Plane_t;

void Windows_Init(void);
void Screen_Print(char Content[17][37]);
void Tank_PosiCtrl(int key_input);
void Refresh_Bullet(int key_input);
void Refresh_Brick(void);

extern char Print_Content[17][37];
extern Plane_t Plane;

#endif