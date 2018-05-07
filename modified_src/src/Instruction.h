#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Bug.h"

class Instruction {   
    public:
        void execute(Bug b);
        void parse(std::string args);
};

#endif /* INSTRUCTION_H */

