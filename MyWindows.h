#ifndef MYWINDOWS_H
#define MYWINDOWS_H
#include "Model.h"
class MyWindows:public Model
{
    public:
        Tank *me;
        Tank *enemy;
        MyWindows(int x, int y);
};

#endif // MYWINDOWS_H
