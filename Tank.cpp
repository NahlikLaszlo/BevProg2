#include "Tank.h"
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace genv;
Tank::Tank(int X,int Y,int SX,int SY):Widgets(X,Y,SX,SY)
{
angle=3.14/180;
h=0;
}
void Tank::draw()
{
    int hb1=_x-_size_x;
    int lb1=_x-_size_x/2;
    int lb2=_y-3*_size_y/4;
    gout<<move_to(hb1,_y)<<color(0,255,0)<<box(2*_size_x,_size_y);
    gout<<move_to(lb1,lb2)<<color(255,0,0)<<box(_size_x,3*_size_y/4);
    ///cannon
    gout<<move_to(_x+_size_x/2,_y-_size_y/2)<<color(0,0,255)<<line((40*cos(angle)-4*(sin(angle))),(sin(angle)*40)+cos(angle)*4);


}
void Tank::handle(genv::event ev)
{
}
std::string Tank::GetValue()
{
    return "Alma";
}
bool Tank::is_selected(genv::event ev)
{
    return true;
}
void Tank::setAngle(int v)
{
    v=abs(v);
    while(!(v<=90))
          v-=90;
    angle=-v*3.14/180;
    std::cout<<angle<<std::endl;
}
