#ifndef WINDOWS_H
#define WINDOWS_H
#include "Widgets.hpp"
#include <vector>

class Windows
{
    public:
    Windows(int X, int Y) ;
    virtual void Save(Widgets* n);
    virtual void SetFocus(event ev, int tabindex);
    virtual void Clear();
    virtual void loop();
    protected:
        int _X, _Y;
        std::vector<Widgets*> w;

};

#endif // WINDOWS_H
