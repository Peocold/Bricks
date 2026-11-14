#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <input.h>

static struct termios g_old;
static int g_term_saved = 0;

void Term_Init(void)
{
    if(tcgetattr(STDIN_FILENO, &g_old) == -1)
    {
        return;
    }
    g_term_saved = 1;
    struct termios t = g_old;
    t.c_lflag &= ~(ICANON | ECHO);
    // 非阻塞
    t.c_cc[VMIN]  = 0;      
    t.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void Term_Restore(void)
{
    if(g_term_saved) {
        tcsetattr(STDIN_FILENO, TCSANOW, &g_old);
        g_term_saved = 0;
    }
}

int Read_Key(void)
{
    unsigned char first_byte;
    // 没读取到或读取错误
    if(read(STDIN_FILENO, &first_byte, 1) <= 0)
    {
        return EOF;
    }
    int input = first_byte;

    if(input == KEY_EXIT)
    {
        unsigned char next_byte;
        ssize_t next_count = read(STDIN_FILENO, &next_byte, 1);
        // 读取到ESC 
        if(next_count <= 0 || next_byte != '[')
        {
            return KEY_EXIT;
        }
        // 把第三个字节读掉
        unsigned char arrow_byte;
        if(read(STDIN_FILENO, &arrow_byte, 1) < 0)
        {
        }
        input = EOF;
    }
    return input;
}