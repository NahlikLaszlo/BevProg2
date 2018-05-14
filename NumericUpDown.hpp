#ifndef NUMERICUPDOWN_HPP
#define NUMERICUPDOWN_HPP

#include "widgets.hpp"
#include"StaticText.h"
class NumericUpDown:public Widgets
{
protected:
    int value;
    int minValue;
    int maxValue;
    StaticText *name;
    bool clicked;
public:
    NumericUpDown(int x, int y, int sx, int sy, int minValue,int maxValue,std::string n);
    virtual std::string GetValue();
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void SetValue(std::string a);
    virtual bool is_selected(int ex,int ey);

};

#endif // NUMERICUPDOWN_H
