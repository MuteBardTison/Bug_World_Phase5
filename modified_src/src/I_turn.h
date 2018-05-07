#ifndef I_TURN_H
#define I_TURN_H
#include "aux.h"
#include "Bug.h"
#include "Instruction.h"

class I_turn: public Instruction {
    private:
        aux::tleftright lr;
        aux::tstate z;
    public:
        void execute(Bug b);
        void parse (std::string args);
};


#endif /* I_TURN_H */

