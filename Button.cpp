#include "Button.hpp"
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
    gout<<move_to(_x-_size_x/2,_y-_size_y/2)<<color(150,0,0)<<box(_size_x,_size_y);
    gout<<move_to(_x-gout.twidth(label->GetValue())/2,_y)<<color(255,255,255)<<text(label->GetValue());
}
bool Button::is_selected(int ex, int ey)
{
    if((ex>_x-_size_x/2 && ex<_x+_size_x/2 && ey>_y-_size_y/2 && ey<_y+_size_y/2))
    {
        focused=true;
    }
    else if(!(ex>_x-_size_x/2 && ex<_x+_size_x/2 && ey>_y-_size_y/2 && ey<_y+_size_y/2))
    {
        focused=false;
    }
    return focused;
}
std::string Button::GetValue()
{
    return label->GetValue();
}
