#include <stdio.h>
#include <print.h>

Content_t Content;
char Content_All[240];

void Windows_Sizeset(void)
{
    // 18*15
    printf("\033[8;18;15t");
    fflush(stdout);
}

