#ifndef INDICATOR_H
#define INDICATOR_H
#include "NumericTextbox.h"

class Indicator:public NumericTextbox
{
    public:
        Indicator(int x, int y,int minvalue,int maxvalue,char e);
        virtual void handle(genv::event ev);
        virtual bool is_selected(int ex, int ey);
        NumericTextbox *n;
        virtual void draw();
};

#endif // INDICATOR_H
