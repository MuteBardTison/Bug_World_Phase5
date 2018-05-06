#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <map>
#include <utility>
#include "Bug.h"
#include "World.h"
#include "Instruction.h"
#include "I_direction.h"
#include "I_drop.h"
#include "I_flip.h"
#include "I_mark.h"
#include "I_move.h"
#include "I_pickup.h"
#include "I_sense.h"
#include "I_turn.h"
#include "I_unmark.h"
#include "tokenizer.h"

class Program{
    private:
        int id;
        vector<I_direction> ldi;
        vector<I_drop> ldr;
        vector<I_flip> lfl;
        vector<I_mark> lma;
        vector<I_move> lmo;
        vector<I_pickup> lpi;
        vector<I_sense> lse;
        vector<I_turn> ltu;
        vector<I_unmark> lun;
        map<int,pair<int,string>> order;
        World w;
        /*
        The values in order tell from which vector must we take the next command 
        and also the order of the command in the respective vector
        */
        int i;//number of instructions
    public:
        Program(std::string filename, World w);
        Program(){};
        void step(Bug b, World w);

};

#endif