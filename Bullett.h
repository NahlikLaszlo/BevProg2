#ifndef BULLETT_H
#define BULLETT_H
#include "Widgets.hpp"
#include<vector>
#include<math.h>
class Bullett:public Widgets
{
    public:
        Bullett(int x, int y, int sx,int sy,int Angle,int d,int v,int c);
        virtual void SetCostume(int n);
        virtual std::string GetValue();
        virtual bool is_selected(int ex, int ey);
        virtual void draw();
        virtual void handle(genv::event ev);///move
        virtual void SetAngle(int degree);
        virtual void Move(double power);
        virtual bool can_Move();
        virtual int getx();
        virtual int gety();
    protected:
        int costume;
        int r;
        int g;
        int b;
        int t0;
        int x0,y0;
        int v0;
        int angle;
        int direction;

};

#endif // BULLETT_H
