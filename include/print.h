#ifndef __PRINT_H
#define __PRINT_H

typedef struct Plane_t
{
    uint8_t x;
    uint8_t y;
};

typedef struct Content_struct_t
{
    char Y_01[15];
    char Y_02[15];
    char Y_03[15];
    char Y_04[15];
    char Y_05[15];
    char Y_06[15];
    char Y_07[15];
    char Y_08[15];
    char Y_09[15];
    char Y_10[15];
    char Y_11[15];
    char Y_12[15];
    char Y_13[15];
    char Y_14[15];
    char Y_15[15];
    char Y_16[15];
    char Y_17[15];
    char Y_18[15];
} Content_t;

void Windows_Sizeset(void);

#endif