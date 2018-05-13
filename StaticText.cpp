#include "StaticText.h"
using namespace genv;

StaticText::StaticText(int x,int y):Widgets(x,y,0,0)
{

}
StaticText::StaticText(int x,int y,std::string n, int c):Widgets(x,y,0,0)
{
    SetValue(n);
    SetColor(c);
}
void StaticText::SetPosition(int x, int y)
{
    _x=x;
    _y=y;
}
std::string StaticText::GetValue(){return value;}
void StaticText::handle(genv::event ev){}
void StaticText::draw()
{
    int k1=_x-gout.twidth(value)/2;
    int k2=_y+gout.cascent()-2*gout.cdescent();
    gout<<move_to(k1,k2)<<color(r,g,b)<<text(value);
}
void StaticText::SetValue(std::string str){value=str;}
void StaticText::SetColor(int n)
{
    switch(n)
    {
    case 0:
        r=g=b=0;
        break;
    case 1:
        r=255;
        g=b=0;
        break;
    case 2:
        r=b=0;
        g=255;
        break;
    case 3:
        r=g=0;
        b=255;
        break;
    case 4:
        r=g=255;
        b=0;
        break;
    case 5:
        r=g=b=n;
        break;
    default:
        r=255;
        g=b=0;
        break;
    }
}
