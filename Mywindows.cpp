#include "Mywindows.hpp"
#include "CloseButton.h"
#include<AveregeButton.h>
Mywindows::Mywindows(int x,int y):Windows(x,y)
{
   mytank=new Tank(200,200,x/20,x/40);
   w.push_back(mytank);
}
