#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "aux.h"
#include "World.h"
#include "Bug.h"

class Instruction {   
    public:
        void execute(Bug b);
        void parse(std::string args);
};

#endif /* INSTRUCTION_H */

