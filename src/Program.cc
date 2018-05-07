#include "Program.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "tokenizer.h"

Program::Program(std::string filename, World w) {
    this->w = w;
    std::ifstream f(filename.c_str());
   
    if(!f.is_open()) {
        throw "Unable to open the assembly language program file\n";
    }
    
    i=0;
    std::string s;

    while(f.good()) {
        getline(f,s);
        std::vector<std::string> command = tokens_in_vector(s);
        std::vector<std::string>::iterator it = command.begin();
        if(*it == "sense") {
            I_sense* t = nullptr;
            t->parse(s);
            ise.push_back(*t);
            order[i] = std::make_pair(ise.size(), "sense");
            i++;
        }
        else if(*it == "flip") {
            I_flip* f = nullptr;
            f->parse(s);
            ifl.push_back(*f);
            order[i] = std::make_pair(ifl.size(), "flip");
            i++;
        }
        else if(*it == "pickup") {
            I_pickup* p = nullptr;
            p->parse(s);
            ipi.push_back(*p);
            order[i] = std::make_pair(ipi.size(), "pickup");
            i++;
        }
        else if(*it == "mark") {
            I_mark* t = nullptr;
            t->parse(s);
            ima.push_back(*t);
            order[i] = std::make_pair(ima.size(), "mark");
            i++;
        }
        else if(*it == "unmark") {
            I_unmark* u = nullptr;
            u->parse(s);
            iun.push_back(*u);
            order[i] = std::make_pair(iun.size(), "unmark");
            i++;
        }
        else if(*it == "direction") {
            I_direction * d = nullptr;
            d->parse(s);
            idi.push_back(*d);
            order[i] = std::make_pair(idi.size(), "direction");
            i++;
        }
        else if(*it=="move") {    
            I_move * m = nullptr;
            m->parse(s);
            imo.push_back(*m);
            order[i] = std::make_pair(imo.size(), "move");
            i++;
        }
        else if(*it == "turn") {
            I_turn* t = nullptr;
            t->parse(s);
            itu.push_back(*t);
            order[i] = std::make_pair(itu.size(), "turn");
            i++;
        }
        else if(*it == "drop") {
            I_drop* dr = nullptr;
            dr->parse(s);
            idr.push_back(*dr);
            order[i] = std::make_pair(idr.size(), "drop");
            i++; 
        }
        else{
            throw "Unspecified command\n";
        }
    }  
}

void Program::step(Bug b, World w) {
    if(!b.is_dead()) {
        int rest = b.rested();
        if(rest == 1) {
            aux::tstate s = b.get_state();
            std::pair<int, std::string> aux = order[s.st];// recall first value the position, second value the type of instruction
            if(aux.second == "sense") {
                I_sense in = ise[aux.first];
                in.execute(b,w);
            }
            if(aux.second == "flip") {
                I_flip in = ifl[aux.first];
                in.execute(b);
            }
            if(aux.second == "pickup") {
                I_pickup in = ipi[aux.first];
                in.execute(b,w);
            } 
            if(aux.second == "mark") {
                I_mark in = ima[aux.first];
                in.execute(b,w);
            }
            if(aux.second == "unmark") {
                I_unmark in = iun[aux.first];
                in.execute(b,w);
            }
            if(aux.second == "direction") {
                I_direction in = idi[aux.first];
                in.execute(b);
            }
            if(aux.second == "move") {
                I_move in = imo[aux.first];
                in.execute(b,w);
            }
            if(aux.second == "turn") {
                I_turn in = itu[aux.first];
                in.execute(b);
            }
            if(aux.second == "drop") {
                I_drop in = idr[aux.first];
                in.execute(b,w);
            }
        }
    }
}