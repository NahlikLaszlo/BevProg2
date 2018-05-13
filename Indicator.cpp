#include "Indicator.h"

Indicator::Indicator(int x, int y,int minvalue, int maxvalue,char e):NumericTextbox(x,y,minvalue,maxvalue," ",3,e)
{
    n=new NumericTextbox(x,y,minvalue,maxvalue,"Power",1,e);
    value=tool->StoI(n->GetValue());
}
void Indicator::draw()
{
    n->draw();
    genv::gout<<genv::move_to(_x-_size_x/2,_y+_size_y/2)<<color(128,128,128)<<box(_size_x,_size_y/2);
    genv::gout<<genv::move_to(_x-_size_x/2,_y+5*_size_y/8)<<color(255,0,0)<<box(value*_size_x/100,_size_y/4);
}
void Indicator::handle(genv::event ev)
{
    if(is_selected(ev.pos_x,ev.pos_y) && ev.button==btn_left)
        clicked=true;
    if(clicked)
        n->handle(ev);
    value=tool->StoI(n->GetValue());
}
bool Indicator::is_selected(int ex,int ey)
{
    if(ex>_x-_size_x/2 && ex<_x+_size_x/2+_size_y/2 && ey>_y-_size_y/2 && ey<_y+7*_size_y/8)
        focused=true;

    return focused;
}
