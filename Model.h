#ifndef MODEL_H
#define MODEL_H
#include "Tank.h"
#include <vector>
class Model
{
    public:
        Model(int X,int Y);
        virtual void Clear();
        virtual void Menu();
        virtual void loop();
        virtual void addChild(Tank *n);
        virtual void GameOver(Tank *n);
    protected:
        int x,y;
        std::vector<Tank *> t;
};

#endif // MODEL_H
