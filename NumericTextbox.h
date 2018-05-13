#ifndef NUMERICTEXTBOX_H
#define NUMERICTEXTBOX_H
#include"NumericUpDown.hpp"
#include "Textbox.hpp"
#include"StaticText.h"

class NumericTextbox:public NumericUpDown
{
    public:
        NumericTextbox(int x, int y,int minvalue,int maxValue,std::string n, int c,char e);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual void SetFocus();
        virtual void NoFocus();
        virtual bool is_focused();
        virtual void SetValue(std::string str);
        virtual bool Text_Changed(std::string str);
        NumericUpDown *u;
        StaticText *name;
        Textbox *field;
    private:
        std::string backup;
        char extra;

};

#endif // NUMERICTEXTBOX_H
