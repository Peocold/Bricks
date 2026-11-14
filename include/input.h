#ifndef __INPUT_H
#define __INPUT_H

#include <stdio.h>

#define KEY_EXIT 27

void Term_Init(void);
int Read_Key(void);
void Term_Restore(void);

#endif