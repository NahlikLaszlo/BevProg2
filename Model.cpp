#include "Model.h"
#include "Tools.h"
using namespace genv;


Model::Model(int X, int Y) :
    x(X),y(Y)
{
    gout.open(X,Y);
}
void Model::Clear()
{
    gout<<move_to(0,0)<<color(255,255,255)<<box(x,y);
}
void Model::Menu()
{
    Textbox *h=new Textbox(x/10,y/2,"Player 1");
    Textbox *p=new Textbox(8*x/9,y/2,"Player 2");
    NumericUpDown *n=new NumericUpDown(x/10,3*y/4,x/10,x/20,1,3,"Costume");
    NumericUpDown *f=new NumericUpDown(8*x/9,3*y/4,x/10,x/20,1,3,"Costume");
    Tools *tool=new Tools;
    Button *b=new Button(x/2-x/40,1*y/2,x/20,x/40,"OK",[this,h,p,b,tool,n,f]()
    {
        t[0]->SetName(h->GetValue());
        t[0]->SetCostume(tool->StoI(n->GetValue())-1);
        t[1]->SetName(p->GetValue());
        t[1]->SetCostume(tool->StoI(f->GetValue())-1);
        loop();
        delete h;
        delete p;
        delete b;
        delete n;
        delete f;
        delete tool;
    });
    event ev;
    std::vector<Widgets*> w;
    w.push_back(h);
    w.push_back(p);
    w.push_back(n);
    w.push_back(f);
    w.push_back(b);
    while(gin>>ev && ev.keycode!=key_escape)
    {
        Clear();

            for(int i=1; i<=3;i++)
            {
                StaticText *t=new StaticText(2*x/10,(i)*y/9);
                t->SetValue(" - "+tool->ItoS(i));
                Tank *a=new Tank(x/10,(i)*y/9,x/50,x/100,i-1,1,0,0);
                a->draw();
                t->draw();
            }
            for(int i=1; i<=3;i++)
            {
                StaticText *t=new StaticText(8*x/10,(i)*y/9);
                t->SetValue(tool->ItoS(i)+" - ");
                Tank *a=new Tank(9*x/10,(i)*y/9,x/50,x/100,i-1,-1,0,0);
                a->draw();
                t->draw();
            }

        for(Widgets* v:w)
        {
            v->draw();
            v->handle(ev);
        }
            for(size_t i=0; i<w.size(); i++)
                if(w[i]->is_selected(ev.pos_x,ev.pos_y)&& ev.button==btn_left)
                    w[i]->SetFocus();
                else if(!(w[i]->is_selected(ev.pos_x,ev.pos_y))&& ev.button==btn_left)
                        w[i]->NoFocus();


                    gout<<refresh;

    }
}

    void Model::addChild(Tank *n)
    {
        t.push_back(n);
    }
    void Model::loop()
    {
        event ev;
        gin.timer(20);
        int focus=0;
        int nofocus=1;
        bool ingame=true;
        while(gin>>ev && ev.keycode!=key_escape)
            {
            for(Tank* s:t)
                if(s->Have_Bullet()&& s->shot)
                    ingame=false;
            Clear();

            if(ingame==true)
            {
            for(int i=0; i<t.size(); i++)
              {
                if(i==focus)
                {
                    t[i]->SetFocus();
                }
                else
                {
                    t[i]->NoFocus();
                    nofocus=i;
                }
                    }
            for(Tank * s:t)
            {
                if(s->is_focused())
                    s->handle(ev);
                s->draw();
                if(s->is_finished())
                {
                    if(focus==1)
                        focus=0;
                    else
                        focus++;
                }
                if(ev.type==ev_timer && s->Have_Bullet()&& s->t->can_Move())
                    {s->DrawBullets(t.at(focus));
                     if(s->shot==true)
                        ingame=false;
                    }
            }
            gout<<refresh;
        }
         else if (ingame==false)
           {
            GameOver(t.at(nofocus));
            delete t[0];
            delete t[1];
            break;}
    }
    }

void Model::GameOver(Tank* me)
{
        event ev;
        while(gin>>ev && ev.keycode!=key_escape)
        {
    gout<<move_to(x/2-gout.twidth(me->GetValue()+" won!")/2,y/2)<<color(0,0,255)<<text(me->GetValue()+" won!")<<refresh;
        }
}
