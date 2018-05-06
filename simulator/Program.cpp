#include "program.h"
#include <fstream>
#include <iostream>
#include "instruction.h"
#include "l_direction.h"
#include "l_drop.h"
#include "l_flip.h"
#include "l_mark.h"
#include "l_move.h"
#include "l_pickup.h"
#include "l_sense.h"
#include "l_turn.h"
#include "l_unmark.h"
#include "tokenizer.h"

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
            l_sense* t;
            t->parse(s);
            lse.push_back(*t);
            order[i]=make_pair(lse.size(),"sense");
            i++;
        }
        else if(*it=="flip"){
            l_flip * f;
            f->parse(s);
            lfl.push_back(*f);
            order[i]=make_pair(lfl.size(),"flip");
            i++;
        }
        else if(*it=="pickup"){
            l_pickup *p;
            p->parse(s);
            lpi.push_back(*p);
            order[i]=make_pair(lpi.size(),"pickup");
            i++;
        }
        else if(*it=="mark"){
            l_mark* t;
            t->parse(s);
            lma.push_back(*t);
            order[i]=make_pair(lma.size(),"mark");
            i++;
        }
        else if(*it=="unmark"){
            l_unmark* u;
            u->parse(s);
            lun.push_back(*u);
            order[i]=make_pair(lun.size(),"unmark");
            i++;
        }
        else if(*it =="direction"){
            l_direction * d;
            d->parse(s);
            ldi.push_back(*d);
            order[i]=make_pair(ldi.size(),"direction");
            i++;
        }
        else if(*it=="move"){    
            l_move * m;
            m->parse(s);
            lmo.push_back(*m);
            order[i]=make_pair(lmo.size(),"move");
            i++;
        }
        else if(*it=="turn"){
            l_turn* t;
            t->parse(s);
            ltu.push_back(*t);
            order[i]=make_pair(ltu.size(),"turn");
            i++;
        }
        else if(*it== "drop"){
            l_drop* dr;
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
                l_sense in=lse[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="flip")
            {
                l_flip in=lfl[aux.first];
                in.execute(b);
            }
            if(aux.second=="pickup")
            {
                l_pickup in=lpi[aux.first];
                in.execute(b,w);
            } 
            if(aux.second=="mark")
            {
                l_mark in=lma[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="unmark")
            {
                l_unmark in=lun[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="direction")
            {
                l_direction in=ldi[aux.first];
                in.execute(b);
            }
            if(aux.second=="move")
            {
                l_move in=lmo[aux.first];
                in.execute(b,w);
            }
            if(aux.second=="turn")
            {
                l_turn in=ltu[aux.first];
                in.execute(b);
            }
            if(aux.second=="drop")
            {
                l_drop in=ldr[aux.first];
                in.execute(b,w);
            }
        }
    }
}