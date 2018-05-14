#ifndef TANK_H
#define TANK_H
#include"StaticText.h"
#include"Widgets.hpp"
#include"NumericTextbox.h"
#include "Bullett.h"
#include "Indicator.h"
#include "Button.hpp"
#include <cstdlib>
#include <time.h>
class Tank:public Widgets
{
    public:
        Tank(int X, int Y, int SX, int SY,int c,int d,int v0, int h0);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual std::string GetValue();
        virtual bool is_selected(int ex, int ey);
        virtual void DrawBullets(Tank * enemy);
        virtual bool is_finished();
        virtual void NoFocus();
        virtual void SetFocus();
        virtual bool Have_Bullet();
        virtual void SetName(std::string n);
        virtual int gx();
        virtual int gy();
        virtual int gsx();
        virtual int gsy();
        virtual void SetCostume(int i);
        bool shot;
        Bullett *t;
    protected:
        int direction;
        int costume;
        int r1,g1,b1;
        int r2,g2,b2;
        int r3,g3,b3;
        bool finished;
        StaticText *name;
        int angle;
        NumericTextbox *n;
        Indicator *i;
        Button *b;
        NumericUpDown *u;
        int windows_width;
        int windows_height;


};

#endif // TANK_H
