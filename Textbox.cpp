#include "Textbox.hpp"
#include<string>
#include<iostream>
using namespace genv;
Textbox::Textbox(int x, int y,std::string n):Widgets(x,y,genv::gout.cascent()*10,5*genv::gout.cascent()/2)
{
    cursorindex=value.length();
    actcharacters=maxcharacters=0;
    border=2;
    clicked=false;
    std::string test="";
    while(gout.twidth(test)+gout.twidth("ó")<_size_x-2*border)
    {
        test+='ó';
        maxcharacters++;
    }
    name=new StaticText(x,y-5*genv::gout.cascent()/2);
    name->SetValue(n);
    name->SetColor(3);
}

void Textbox::draw()
{
    int p1=_x-_size_x/2;
    int p2=_y-_size_y/2;
    border=2;
    gout<<move_to(p1,p2)<<color(51,153,255)<<box(_size_x,_size_y);
    gout<<move_to(p1+border,p2+border)<<color(255,255,255)<<box(_size_x-2*border,_size_y-2*border);
    name->draw();
    if(clicked)
    {
        border=4;
        gout<<move_to(p1,p2)<<color(51,153,255)<<box(_size_x,_size_y);
        gout<<move_to(p1+border,p2+border)<<color(255,255,255)<<box(_size_x-2*border,_size_y-2*border);
        if(value.length()<=maxcharacters)
            gout<<move_to(p1+2*border,_y+gout.cascent()/3)<<color(255,0,0)<<text(value.substr(actcharacters,value.length()));
        if(value.length()>maxcharacters)
            gout<<move_to(p1+2*border,_y+gout.cascent()/3)<<color(255,0,0)<<text(value.substr(actcharacters,maxcharacters));
        if(cursorindex<maxcharacters)
            gout<<move_to(p1+2*border+gout.twidth(value.substr(0,cursorindex)),p2+gout.cascent()/2)<<color(0,0,255)<<line(0,_size_y-3*border);
    }
        if(value.length()<=maxcharacters)
            gout<<move_to(p1+2*border,_y+gout.cascent()/3)<<color(255,0,0)<<text(value.substr(actcharacters,value.length()));
        if(value.length()>maxcharacters)
            gout<<move_to(p1+2*border,_y+gout.cascent()/3)<<color(255,0,0)<<text(value.substr(actcharacters,maxcharacters));

}
void Textbox::handle(event ev)
{
    if(is_selected(ev.pos_x,ev.pos_y)&& ev.button==btn_left)
        clicked=true;
    if(clicked && ev.type==ev_key)
    {
        switch(ev.keycode)
        {
        case key_backspace:
            if(cursorindex>0 && value.length()<=maxcharacters)
                {
                value.erase(value.begin()+cursorindex-1);
                cursorindex--;
                if(actcharacters>0)
                    actcharacters--;
                }
            if(cursorindex>0 && value.length()>maxcharacters)
            {
                value.erase(value.begin()+actcharacters+cursorindex-1);
                if(actcharacters>0)
                    actcharacters--;
            }
            break;
        case key_delete:
            if(cursorindex!=value.length())
            {
                value.erase(value.begin()+cursorindex);
            }
            break;
        case key_lshift:
            break;
        case key_rshift:
            break;
        case key_lctrl:
            break;
        case key_rctrl:
            break;
        case key_lalt:
            break;
        case key_ralt:
            break;
        case key_pgdn:
            break;
        case key_pgup:
            break;
        case key_up:
            break;
        case key_down:
            break;
        case key_enter:
            break;
        case key_tab:
            break;
        case key_left:
            {
            if(cursorindex<=0)
                cursorindex=0;
            if(cursorindex==0 && actcharacters>0)
                actcharacters--;
            else if(cursorindex>0)
               cursorindex--;

            break;
            }
        case key_right:
            if(value.length()<maxcharacters && cursorindex>=value.length())
                cursorindex=value.length()-1;
            {if(cursorindex>maxcharacters)
                cursorindex=maxcharacters;
             if(cursorindex==maxcharacters && actcharacters<value.length()-maxcharacters-1)
                    actcharacters++;
            else if(cursorindex<maxcharacters)
                cursorindex++;

            }

            break;
        case key_end:

            {if(value.length()>maxcharacters)
            {
                cursorindex=maxcharacters;
            actcharacters=value.length()-maxcharacters;
            }
            if(value.length()<maxcharacters)
                {cursorindex=value.length();
                actcharacters=0;}
            }
            break;
        case key_home:
            {
            cursorindex=0;
            actcharacters=0;
            }
            break;
        default:
            if((cursorindex==value.length() || cursorindex==maxcharacters) && ev.keycode>0)
            {
                value+=(char) ev.keycode;
                if(value.length()>=maxcharacters+1)
                    actcharacters++;

                if(cursorindex<maxcharacters)
                    cursorindex++;
            }
            if(value.length()<maxcharacters && cursorindex<value.length()&& ev.keycode>0)
            {
                value.insert(value.begin()+cursorindex,(char)ev.keycode);
                cursorindex++;
            }

}
if(!is_selected(ev.pos_x,ev.pos_y)&& ev.button==btn_left)
    clicked=false;
}
}
void Textbox::SetFocus()
{
    clicked=focused=true;
}
void Textbox::NoFocus()
{
    clicked=focused=false;
}
std::string Textbox::GetValue()
{
    return value;
}
void Textbox::SetText(std::string str)
{
    value=str;
    cursorindex=value.length();
}
