#include "MyWindows.h"

MyWindows::MyWindows(int x, int y):Model(x,y)
{
    me=new Tank(x/5,y/3,x/50,x/100,0,1,x,y);
    enemy=new Tank(3*x/5,y/3,x/50,x/100,1,-1,x,y);
    addChild(me);
    addChild(enemy);

}
