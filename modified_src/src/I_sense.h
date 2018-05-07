#ifndef I_SENSE_H
#define I_SENSE_H
#include "aux.h"
#include "World.h"
#include "Bug.h"
#include "Instruction.h"

class I_sense: public Instruction {
    private:
        aux::tsensedir dir;
        aux::tstate x;
        aux::tstate y;
        aux::tcondition condition;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_SENSE_H */

