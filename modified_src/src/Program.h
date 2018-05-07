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

class Program{
    private:
        //int id;
        std::vector<I_direction> idi;
        std::vector<I_drop> idr;
        std::vector<I_flip> ifl;
        std::vector<I_mark> ima;
        std::vector<I_move> imo;
        std::vector<I_pickup> ipi;
        std::vector<I_sense> ise;
        std::vector<I_turn> itu;
        std::vector<I_unmark> iun;
        std::map<int, std::pair<int, std::string> > order;
        World w;
        /*
        The values in order tell from which vector must we take the next command 
        and also the order of the command in the respective vector
        */
        int i;//number of instructions
    public:
        Program(){};
        Program(std::string filename, World w);
        void step(Bug b, World w);
};

#endif