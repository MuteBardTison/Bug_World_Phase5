#ifndef I_MARK_H
#define I_MARK_H

#include "auxbug.h"
#include "World.h"
#include "Bug.h"
#include "Instruction.h"

class I_mark: public Instruction {
    private:
        int m;
        auxbug::tstate z;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};

#endif /* I_MARK_H */