#include "Button.hpp"
#include<iostream>
using namespace genv;
Button::Button(int x, int y, int sx,int sy, std::string lab):Widgets(x,y,sx,sy)
{
    label=new StaticText(x+sx/2-gout.twidth(lab),y);
    label->SetValue(lab);
}

Button::Button(int x, int y, int sx,int sy, std::string lab,std::function<void()> Press):Widgets(x,y,sx,sy)
{
    label=new StaticText(x+sx/2-gout.twidth(lab),y);
    label->SetValue(lab);
    press=Press;
}
void Button::handle(genv::event ev)
{
    if(is_selected(ev.pos_x,ev.pos_y)&&  ev.button==btn_left && ev.type==ev_mouse)
        press();

}
void Button::action(std::function<void()> Press)
{
    press=Press;
}
void Button::draw()
{
    gout<<move_to(_x,_y)<<color(120,120,120)<<box(_size_x,_size_y);
    gout<<move_to(_x+_size_x/2-gout.twidth(label->GetValue())/2,_y+_size_y/2)<<color(255,255,255)<<text(label->GetValue());
}
bool Button::is_selected(int ex, int ey)
{
    if((ex>_x && ex<_x+_size_x && ey>_y && ey<_y+_size_y))
    {
        focused=true;
    }
    else if(!(ex>_x && ex<_x+_size_x && ey>_y && ey<_y+_size_y))
    {
        focused=false;
    }
    return focused;
}
std::string Button::GetValue()
{
    return label->GetValue();
}
