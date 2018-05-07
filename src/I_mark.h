#ifndef I_MARK_H
#define I_MARK_H

#include "aux.h"
#include "World.h"
#include "Bug.h"
#include "Instruction.h"

class I_mark: public Instruction {
    private:
        int m;
        aux::tstate z;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_MARK_H */