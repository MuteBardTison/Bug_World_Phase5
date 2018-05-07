#ifndef I_DROP_H
#define I_DROP_H
#include "aux.h"
#include "Bug.h"
#include "World.h"
#include "Instruction.h"

class I_drop: public Instruction {
    private:
        aux::tstate z;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_DROP_H */