#include "Windows.h"
#include<cstdlib>
#include<fstream>
using namespace genv;


Windows::Windows(int X, int Y) :
    _X(X),_Y(Y)
{
    gout.open(X,Y);
}
void Windows::Clear()
{
    gout<<move_to(0,0)<<color(255,255,255)<<box(_X,_Y);
}
void Windows::Save(Widgets* n)
{
    ofstream myfile("value.txt");
    myfile<<"Value: "<<n->GetValue();
    myfile.close();
    system("value.txt");
}
void Windows::SetFocus(genv::event ev,int tabindex)
{
    if(tabindex!=-1)
    {
        for(size_t i=0; i<w.size(); i++)
            if(i!=tabindex)
                w[i]->NoFocus();

        w[tabindex]->SetFocus();
    }
    if(tabindex==-1)
    {
        for(size_t i=0; i<w.size(); i++)
            if(w[i]->is_selected(ev))
                 tabindex=i;
        for(size_t i=0; i<w.size(); i++)
            if(i!=tabindex)
                w[i]->is_selected(ev);
    }
}
void Windows::loop()
{
    event ev;
    int tabindex=-1;
    while(gin>>ev && ev.keycode!=key_escape)
    {
    Clear();
        for(Widgets* v:w)
        {

            v->draw();
            v->handle(ev);
            if(ev.keycode==key_lctrl && v->is_focused())
                Save(v);
        }
        if(ev.keycode==key_tab || ev.type==ev_mouse)
        {
            if(ev.type==ev_mouse)
                for(int i=0;i<w.size(); i++)
                    if(w[i]->is_selected(ev))
                      tabindex=i;
            if(ev.keycode==key_tab)
                if(tabindex>=w.size()-1 )
                    tabindex=0;
                else
                    tabindex++;
        }
        SetFocus(ev,tabindex);


        gout<<refresh;
}}
