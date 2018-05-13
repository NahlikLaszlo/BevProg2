#include "Widgets.hpp"
using namespace genv;
Widgets::Widgets(int x, int y, int sx, int sy): _x(x), _y(y), _size_x(sx),_size_y(sy)
{
    focused=false;
    tool=new Tools;
}
void Widgets::SetFocus(){focused=true;}
void Widgets::NoFocus(){focused=false;}
bool Widgets::is_focused(){return focused;}
bool Widgets::is_selected(int ex, int ey)
{
    if(ex>_x-_size_x/2 && ex<_x+_size_x/2 && ey>_y-_size_y/2 && ey<_y+_size_y/2)
        focused=true;
    else if(!(ex>_x-_size_x/2 && ex<_x+_size_x/2 && ey>_y-_size_y/2 && ey<_y+_size_y/2))
        focused=false;
    return focused;
}
