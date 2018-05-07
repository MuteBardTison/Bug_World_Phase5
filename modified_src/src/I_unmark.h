#ifndef I_UNMARK_H
#define I_UNMARK_H
#include "aux.h"
#include "Bug.h"
#include "World.h"
#include "Instruction.h"

class I_unmark: public Instruction {
    private: 
        int m;
        aux::tstate z;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_UNMARK_H */

