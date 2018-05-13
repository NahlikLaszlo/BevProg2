#include "NumericTextbox.h"
#include<sstream>
#include<iostream>
NumericTextbox::NumericTextbox(int x,int y,int minvalue,int maxvalue,std::string n, int c,char e):NumericUpDown(x,y,genv::gout.cascent()*10,5*genv::gout.cascent()/2,minvalue,maxvalue,n)
{
extra=e;
u=new NumericUpDown(x,y,genv::gout.cascent()*10,5*genv::gout.cascent()/2,minvalue,maxValue,n);
name=new StaticText(x,y-_size_y,n,c);
name->SetValue(n);
field=new Textbox(x,y,"");
field->SetText(GetValue()+e);
value= minValue=minvalue;
maxValue=maxvalue;

}
void NumericTextbox::draw()
{
    u->draw();
    field->draw();
    name->draw();
}
bool NumericTextbox::Text_Changed(std::string str)
{
    if(backup==str)
        return false;
    else if(backup!=str)
    {
        backup=str;
        return true;
    }
}
void NumericTextbox::handle(genv::event ev)
{
    if(is_selected(ev.pos_x,ev.pos_y)&& ev.button==btn_left)
        clicked=true;
    if(clicked)
    {
    if(((ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_x>_x+_size_x/2 && ev.pos_y>_y-_size_y/2 && ev.pos_y<_y && ev.button==btn_left)) && value<maxValue)
        value++;
    if(((ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_x>_x+_size_x/2 && ev.pos_y>_y && ev.pos_y<_y+_size_y/2 && ev.button==btn_left)) && value>minValue)
        value--;
    if(ev.keycode==key_pgup && value<=90)
    {
        if(value+5>=maxValue)
            value=maxValue;
        else
            value+=5;
    field->SetText(GetValue()+extra);
    }
    if(ev.keycode==key_pgdn&& value>minValue)
    {
        if(value-5<minValue)
            value=minValue;
        else
            value-=5;
    field->SetText(GetValue()+extra);
    }
    field->SetFocus();
    field->handle(ev);
    stringstream ss;
    ss<<field->GetValue();
    int norm;
    ss>>norm;
    if(ev.keycode==key_enter && norm<=maxValue && norm>=minValue)
    {
    SetValue(field->GetValue());
    field->SetText(GetValue()+extra);
    NoFocus();
    }
    if(Text_Changed(GetValue())&& ev.button==btn_left)
        field->SetText(GetValue()+extra);

    if(!(ev.pos_x>_x-_size_x/2 && ev.pos_x<_x+_size_x/2+_size_y/2 && ev.pos_y>_y-_size_y/2 && ev.pos_y<_y+_size_y)&& norm<=maxValue && norm>=minValue && ev.button==btn_left )
    {
        SetValue(field->GetValue());
        field->SetText(GetValue()+extra);
        NoFocus();
    }

    }
}

void NumericTextbox::SetFocus()
{
    clicked=true;
    focused=true;
    field->SetFocus();
    u->SetFocus();
}
void NumericTextbox::NoFocus()
{
    focused=false;
    clicked=false;
    field->NoFocus();
    u->NoFocus();
}
void NumericTextbox::SetValue(std::string str)
{
    stringstream ss;
    ss<<str;
    ss>>value;
    field->SetText(str);
}
bool NumericTextbox::is_focused(){return clicked;}
