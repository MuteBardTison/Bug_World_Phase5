#ifndef I_SENSE_H
#define I_SENSE_H
#include "auxbug.h"
#include "World.h"
#include "Bug.h"
#include "Instruction.h"

class I_sense: public Instruction {
    private:
        auxbug::tsensedir dir;
        auxbug::tstate x;
        auxbug::tstate y;
        auxbug::tcondition condition;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_SENSE_H */

