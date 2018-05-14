#include "Bullett.h"
Bullett::Bullett(int x,int y,int sx,int sy,int Angle,int d,int v,int c):Widgets(x,y,sx,sy){
    t0=1;
    x0=x;
    y0=y;
    v0=v;
    angle=Angle;
    costume=c;
    direction=d;
    }
void Bullett::handle(genv::event ev){
}
void Bullett::Move(double power){

if(can_Move())
   {
    _x=x0+direction*(1+v0*0.015*power/100*cos(tool->degtorad(angle))*t0);
    _y=y0+1+v0*0.015*(power/100)*sin(tool->degtorad(angle))*t0+0.1*pow(t0,2);
    t0++;
   }

}
int Bullett::getx(){return _x+direction*(40*cos(tool->degtorad(angle)))-direction*_size_x/2;}
int Bullett::gety(){return _y+(sin(tool->degtorad(angle))*40)-_size_y/2;}




bool Bullett::can_Move(){

int a=_y+(sin(tool->degtorad(angle))*40)-_size_y/2;
int b=y0+v0/y0*_size_y;
int c=_x+direction*(40*cos(tool->degtorad(angle)))-direction*_size_x/2;
int d=_size_x+direction*(40*cos(tool->degtorad(angle)));
int e=_x+direction*(40*cos(tool->degtorad(angle)))-direction*_size_x/2;
int f=_y+(sin(tool->degtorad(angle))*40)-_size_y/2+t0;
int g=_size_y;
return a<b && c>d && e<v0 && f>g;}




bool Bullett::is_selected(int ex,int ey){return focused;}
void Bullett::SetCostume(int n){costume=n;}
std::string Bullett::GetValue(){return "";}
void Bullett::draw()
{
    switch(costume)
    {
    case 0:
        r=g=b=0;
        break;
    case 1:
        r=255;
        g=b=0;
        break;
    case 2:
        r=g=0;
        b=255;
        break;
    default:
        r=g=b=85;
        break;
    }
gout<<move_to(_x+direction*(40*cos(tool->degtorad(angle)))-direction*_size_x/2,_y+(sin(tool->degtorad(angle))*40)-_size_y/2)<<color(r,g,b)<<box(direction*_size_x,_size_y);
}
void Bullett::SetAngle(int degree){angle=tool->degtorad(degree);}

