#include "Tank.h"
#include<math.h>
#include<sstream>
using namespace genv;
Tank::Tank(int X,int Y,int SX,int SY,int c,int d,int v0,int h0):Widgets(X,Y,SX,SY)
{
u=new NumericUpDown(v0/8,5*h0/6,5*v0/100,5*v0/200,1,3,"Bullet costume");
shot=false;
windows_height=h0;
windows_width=v0;
t=NULL;
direction=d;
costume=c;
finished=false;
angle=3.14/180;
name=new StaticText(X,Y-SX," ",3);
n=new NumericTextbox(v0/4,5*h0/6,0,90,"Angle",1,'°');
i=new Indicator(v0/2,5*h0/6,0,100,'%');
b=new Button(3*v0/4,4*h0/5,15*v0/100,15*v0/200,"Fire",[this]()
             {
                t=new Bullett(_x,_y,5,5,angle,direction,windows_width,tool->StoI(u->GetValue())-1);
                finished=true;
             });
}
bool Tank::Have_Bullet(){return t; }
void Tank::SetName(std::string n)
{
    name->SetValue(n);
}
void Tank::draw()
{
    int hb1=_x-_size_x;
    int lb1=_x-_size_x/2;
    int lb2=_y-3*_size_y/4;
    switch (costume)
    {
        case 0:
            g1=255;
            b1=r1=0;
            r2=255;
            b2=g2=0;
            r3=g3=0;
            b3=255;
            break;
        case 1:
            r1=255;
            g1=b1=0;
            r2=b2=0;
            g2=255;
            r3=g3=0;
            b3=255;
            break;
        case 2:
            r1=g1=0;
            r2=b2=0;
            r3=b3=0;
            b1=255;
            g2=255;
            g3=255;
    }
    gout<<move_to(hb1,_y)<<color(r1,g1,b1)<<box(2*_size_x,_size_y);
     gout<<move_to(_x+direction*_size_x/2,_y-_size_y/2)<<color(r3,g3,b3)<<line(direction*40*cos(tool->degtorad(direction*angle)),direction*(sin(tool->degtorad(direction*angle))*40));
    gout<<move_to(lb1,lb2)<<color(r2,g2,b2)<<box(_size_x,3*_size_y/4);
    ///cannon

    name->draw();
    if(focused)
    {
    gout<<move_to(_x-gout.twidth("You turn!")/2,_y-3*_size_x-_size_y)<<color(255,0,0)<<text("You turn!");
    gout<<move_to(_x-_size_x/4,_y-2*_size_x)<<color(255,0,0)<<line(_size_x/4,_size_x/4)<<line(0,-(_size_x+_size_y))<<genv::move(0,_size_x+_size_y)<<line(_size_x/4,-_size_x/4);
    n->draw();
    i->draw();
    b->draw();
    u->draw();
}
}
void Tank::SetCostume(int i){costume=i;}
bool Tank::is_finished(){return finished;}
void Tank::handle(genv::event ev)
{
    if(focused)
    {
    srand(time(nullptr));
    if(ev.keycode==key_right && _x<windows_width-_size_x)
        _x+=5;
    if(ev.keycode==key_left && _x>2*_size_x)
        _x-=5;
    angle=tool->StoI(n->GetValue());


    name->SetPosition(_x,_y-_size_x);
    if(i->is_selected(ev.pos_x,ev.pos_y))
       {
        if(!n->is_selected(ev.pos_x,ev.pos_y)&& u->is_selected(ev.pos_x,ev.pos_y))
            {n->NoFocus();
            u->NoFocus();}
        i->handle(ev);
       }
  if(n->is_selected(ev.pos_x,ev.pos_y))
    {
        if(!i->is_selected(ev.pos_x,ev.pos_y)&& !u->is_selected(ev.pos_x,ev.pos_y))
            {i->NoFocus();
            u->NoFocus();}
        n->handle(ev);

    }
    if(u->is_selected(ev.pos_x,ev.pos_y))
    {
        if(!i->is_selected(ev.pos_x,ev.pos_y)&& !!n->is_selected(ev.pos_x,ev.pos_y))
            {
                i->NoFocus();
                n->NoFocus();
                }
            u->handle(ev);

    }
    angle=tool->StoI(n->GetValue());
    b->handle(ev);}
}
void Tank::DrawBullets(Tank* enemy)
{
int a=t->getx();
int b=t->gety();
int c=enemy->gx();
int d=enemy->gsx();
int h=enemy->gsy();
int e=enemy->gy();
if((a>=c-d) && (a<=c+d) && (b>e-h) && (b<e+h))
    shot=true;
if(t->can_Move())
    t->Move(tool->StoI(i->GetValue()));
t->draw();
}
std::string Tank::GetValue()
{
    return name->GetValue();
}
bool Tank::is_selected(int ex ,int ey)
{
    return false;
}
void Tank::NoFocus()
{
   finished=false;
   focused=false;


}
void Tank::SetFocus()
{
    finished=false;
    focused=true;
}
int Tank::gx(){return _x;}
int Tank::gy(){return _y;}
int Tank::gsx(){return _size_x;}
int Tank::gsy(){return _size_y;}
