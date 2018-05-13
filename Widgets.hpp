#ifndef WIDGETS_HPP
#define WIDGETS_HPP
#include "graphics.hpp"
#include "Tools.h"
using namespace std;
using namespace genv;
class Widgets
{
    protected:
        int _x,_y,_size_x,_size_y;
        bool focused;
        Tools *tool;
    public:
        Widgets(int x, int y, int sx,int sy);
        virtual std::string GetValue()=0;
        virtual bool is_selected(int ex, int ey);///with mouse
        virtual void draw()=0;
        virtual void handle(genv::event ev)=0;
        ///keypress
        virtual void SetFocus();
        virtual void NoFocus();
        virtual bool is_focused();


};

#endif // WIDGETS_H
