#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include"Widgets.hpp"
#include "StaticText.h"
class Textbox:public Widgets
{
    public:
        Textbox(int x,int y,std::string n);
        virtual void draw();
        virtual void handle(genv::event ev) ;
        std::string GetValue();
        virtual void SetText(std::string str);
        virtual void NoFocus();
        virtual void SetFocus();

    protected:
    std::string value;
    int cursorindex;
    int actcharacters;
    int maxcharacters;
    int border;
    bool clicked;
    StaticText *name;
};

#endif // TEXTBOX_H
