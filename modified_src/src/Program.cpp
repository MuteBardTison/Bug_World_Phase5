#include "Program.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Program::Program(string filename, World w)
{
    this->w=w;
    ifstream f(filename.c_str());
   
    if(!f.is_open())
    {
        throw "Unable to open the assembly language program file\n";
    }
    
   // vector<string> command;
    i=0;
    string s;

    while(f.good())
    {
        getline(f,s);
        vector<string> command=tokens_in_vector(s);
        vector<string>::iterator it=command.begin();
        if(*it== "sense"){
            I_sense* t;
            t->parse(s);
            lse.push_back(*t);
            order[i]=make_pair(lse.size(),"sense");
            i++;
        }
        else if(*it=="flip"){
            I_flip * f;
            f->parse(s);
            lfl.push_back(*f);
            order[i]=make_pair(lfl.size(),"flip");
            i++;
        }
        else if(*it=="pickup"){
            I_pickup *p;
            p->parse(s);
            lpi.push_back(*p);
            order[i]=make_pair(lpi.size(),"pickup");
            i++;
        }
        else if(*it=="mark"){
            I_mark* t;
            t->parse(s);
            lma.push_back(*t);
            order[i]=make_pair(lma.size(),"mark");
            i++;
        }
        else if(*it=="unmark"){
            I_unmark* u;
            u->parse(s);
            lun.push_back(*u);
            order[i]=make_pair(lun.size(),"unmark");
            i++;
        }
        else if(*it =="direction"){
            I_direction * d;
            d->parse(s);
            ldi.push_back(*d);
            order[i]=make_pair(ldi.size(),"direction");
            i++;
        }
        else if(*it=="move"){    
            I_move * m;
            m->parse(s);
            lmo.push_back(*m);
            order[i]=make_pair(lmo.size(),"move");
            i++;
        }
        else if(*it=="turn"){
            I_turn* t;
            t->parse(s);
            ltu.push_back(*t);
            order[i]=make_pair(ltu.size(),"turn");
            i++;
        }
        else if(*it== "drop"){
            I_drop* dr;
            dr->parse(s);
            ldr.push_back(*dr);
            order[i]=make_pair(ldr.size(),"drop");
            i++; 
        }
        else{
            throw "Unspecified command\n";
        }
    }
    
    
    /*vector<string>::iterator it=command.begin();
    for(it; it!=command.end();it++)
    {
        cout<<*it<<endl; checked if input well read
    }*/
    
}

void Program::step(Bug b, World w)
{
    if(!b.is_dead()){
        int rest=b.rested();
        if(rest==1){
            aux::tstate s=b.get_state();
            pair<int,string> aux=order[s.st];// recall first value the position, second value the type of instruction
            if(aux.second=="sense")
            {
                I_sense in=lse[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="flip")
            {
                I_flip in=lfl[aux.first];
                in.execute(b);
            }
            if(aux.second=="pickup")
            {
                I_pickup in=lpi[aux.first];
                in.execute(b,w);
            } 
            if(aux.second=="mark")
            {
                I_mark in=lma[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="unmark")
            {
                I_unmark in=lun[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="direction")
            {
                I_direction in=ldi[aux.first];
                in.execute(b);
            }
            if(aux.second=="move")
            {
                I_move in=lmo[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="turn")
            {
                I_turn in=ltu[aux.first];
                in.execute(b);
            }
            if(aux.second=="drop")
            {
                I_drop in=ldr[aux.first];
                in.execute(b,w);
            }
        }
    }
}