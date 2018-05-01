#ifndef TANK_H
#define TANK_H
#include <graphics.hpp>
#include<Widgets.hpp>
class Tank:public Widgets
{
    public:
        Tank(int X, int Y, int SX, int SY);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual std::string GetValue();
        virtual bool is_selected(genv::event ev);
        virtual void setAngle(int v);
    protected:
        float angle;

};

#endif // TANK_H
