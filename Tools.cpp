#include "Tools.h"

int Tools::StoI(std::string str)
{
    std::stringstream ss;
    int f;
    ss<<str;
    ss>>f;
    return f;
}
std::string Tools::ItoS(int a)
{
    std::stringstream ss;
    ss<<a;
    return ss.str();
}
double Tools::degtorad(int a)
{
    float h;
    h=-a*3.14/180;
    return h;
}

