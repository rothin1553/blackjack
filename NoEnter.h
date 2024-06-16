/*
this class will minipulate the stream to not wait for "ENTER" to get input

To use:
    1. declare class NoEnter idenifier;
    2. call idenifier.on() to turn on; .off() to turn off.
    3. char c = getchar(); to get the one single character.
*/

#ifndef NoEnter_h
#define NoEnter_h

#include <unistd.h>
#include <termios.h>

class NoEnter
{
private:
    struct termios old_tio, new_tio;

public:
    void on()
    {
        /* get the terminal settings for stdin */
        tcgetattr(STDIN_FILENO,&old_tio);
        /* we want to keep the old setting to restore them a the end */
        new_tio=old_tio;
        /* disable canonical mode (buffered i/o) and local echo */
        new_tio.c_lflag &=(~ICANON & ~ECHO);
        /* set the new settings immediately */
        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    }

    void off()
    {
        /* restore the former settings */
        tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    }

    ~NoEnter()
    {
        off();
    }
};


#endif