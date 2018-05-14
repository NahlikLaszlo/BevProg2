#ifndef STATICTEXT_H
#define STATICTEXT_H
#include"Widgets.hpp"
class StaticText:public Widgets
{
    public:
        StaticText(int x, int y);
        StaticText(int x, int y,std::string n, int c);
        virtual std::string GetValue();
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual void SetValue(std::string str);
        virtual void SetColor(int n);
        virtual void SetPosition(int x,int y);
    protected:
        std::string value;
        int r,g,b;
};

#endif // STATICTEXT_H
