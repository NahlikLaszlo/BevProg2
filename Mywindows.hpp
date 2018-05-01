#ifndef MYWINDOWS_H
#define MYWINDOWS_H
#include<Windows.h>
#include<Tank.h>
class Mywindows:public Windows
{
    public:
        Tank *mytank;
        Mywindows(int X,int Y);
};


#endif // MYWINDOWS_H
