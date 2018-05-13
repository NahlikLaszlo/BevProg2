#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Widgets.hpp"
#include<functional>
#include"StaticText.h"

class Button:public Widgets
{

    public:
        Button(int x, int y, int sx ,int sy, std::string lab,std::function<void()>);
        Button(int x, int y, int sx ,int sy, std::string lab);
        virtual void handle(genv::event ev);
        virtual void action(std::function<void()>);
        virtual void draw();
        virtual bool is_selected(int ex, int ey);
        virtual std::string GetValue();
    protected:
        std::function<void()> press;
        StaticText *label;
};

#endif // BUTTON_H
