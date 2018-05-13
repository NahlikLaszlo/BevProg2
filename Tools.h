#ifndef TOOLS_H
#define TOOLS_H
#include<string>
#include<sstream>
class Tools
{
    public:
        virtual int StoI(std::string str);
        virtual std::string ItoS(int a);
        virtual double degtorad(int a);
};

#endif // TOOLS_H
