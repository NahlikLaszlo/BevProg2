#include "NumericUpDown.hpp"
#include <sstream>
using namespace genv;
NumericUpDown::NumericUpDown(int x, int y, int sx, int sy, int minvalue, int maxvalue,std::string n):Widgets(x,y,sx,sy)
{
    value= minValue=minvalue;
    maxValue=maxvalue;
    name=new StaticText(x, y-sy);
    name->SetValue(n);
    name->SetColor(3);
}
std::string NumericUpDown::GetValue()
{
    std::stringstream ss;
    ss<<value;
    return ss.str();
}

void NumericUpDown::draw()
{
    int p1;
    int p2;
    if(focused)
    {
     p1=_x-_size_x/2-4;
     p2=_y-_size_y/2-4;
    gout<<move_to(p1,p2)<<color(255,255,255)<<box(_size_x+4,_size_y+4);
    }
    else
    {
    ///border
     p1=_x-_size_x/2;
     p2=_y-_size_y/2;
    gout<<move_to(p1,p2)<<color(255,255,255)<<box(_size_x,_size_y);
    }
    name->draw();
    ///textfield
    int k1=p1+2;
    int k2=p2+2;
    int s1=_size_x-3;
    int s2=_size_y-3;
    gout<<move_to(k1,k2)<<color(128,128,128)<<box(s1,s2);
    ///value
    std::stringstream ss;
    ss<<value;
    k1=_x-gout.twidth(ss.str())/2;
    k2=_y+gout.cascent()-2*gout.cdescent();
    gout<<move_to(k1,k2)<<color(255,255,255)<<text(ss.str());
    ///buttons
    k1=_x+_size_x/2;
    k2=p2;
    s1=_size_y/2;
    gout<<move_to(k1,k2)<<color(0,128,128)<<box(s1,s1);
    k2+=2*s1/3;
    int sl1=-s1/3;
    gout<<move_to(k1,_y)<<color(255,255,0)<<box(s1,s1);
    k1+=s1/4;
    k2=p2+s1/2;
    gout<<move_to(k1,k2)<<color(153,0,0)<<line_to(k1+s1/4,k2+sl1);
    gout<<move_to(k1+s1/2,k2)<<color(153,0,0)<<line_to(k1+s1/4,k2+sl1);
    k2+=s1;
    gout<<move_to(k1,k2)<<color(153,0,0)<<line_to(k1+s1/4,k2-sl1);
    gout<<move_to(k1+s1/2,k2)<<color(153,0,0)<<line_to(k1+s1/4,k2-sl1);
    k1+=s1/4;
    gout<<move_to(k1,k2-sl1)<<color(153,0,0)<<line(0,-s1/2);
    k2-=s1;
    gout<<move_to(k1,k2+sl1)<<color(153,0,0)<<line(0,s1/2);
    ///help

}
void NumericUpDown::handle(genv::event ev)
{
    if(focused)
    {
    if((ev.keycode==key_up || (ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_x>_x+_size_x/2 && ev.pos_y>_y-_size_y/2 && ev.pos_y<_y && ev.button==btn_left)) && value<maxValue)
        value++;
    if((ev.keycode==key_down || (ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_x>_x+_size_x/2 && ev.pos_y>_y && ev.pos_y<_y+_size_y/2 && ev.button==btn_left)) && value>minValue)
        value--;
    if(ev.keycode==key_pgup && value+10<=maxValue)
        value+=10;
    else if(ev.keycode==key_pgup && value+10>maxValue)
        value=maxValue;
    if(ev.keycode==key_pgdn && value-10>=minValue)
        value-=10;
    else if (ev.keycode==key_pgdn && value-10<minValue)
        value=minValue;
    if(!(ev.pos_x>_x-_size_x/2 && ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_y>_y-_size_y/2 && ev.pos_y<_y+_size_y) && ev.button==btn_left)
        NoFocus();
    }
}
void NumericUpDown::SetValue(std::string a)
{
    int n;
    stringstream ss;
    ss<<a;
    ss>>n;
    if(n>maxValue)
        value=maxValue;
    if(n<minValue)
        value=minValue;
    if(n>minValue&& n<maxValue)
        value=n;
}
bool NumericUpDown::is_selected(int ex,int ey)
{
    if(ex>_x-_size_x/2 && ex<_x+_size_x/2+_size_y/2 && ey>_y-_size_y/2 && ey<_y+_size_y)
        focused=true;

    return focused;
}
