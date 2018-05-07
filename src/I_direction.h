#ifndef I_DIRECTION_H
#define I_DIRECTION_H
#include "auxbug.h"
#include "Instruction.h"

class I_direction : public Instruction {
    private:
        auxbug::tdirection d;
        auxbug::tstate x;
        auxbug::tstate y;
    public:
        void execute(Bug b);
        void parse(std::string args);    
};

#endif /* I_DIRECTION_H */

