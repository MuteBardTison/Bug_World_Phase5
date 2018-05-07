#ifndef I_PICKUP_H
#define I_PICKUP_H
#include "aux.h"
#include "World.h"
#include "Bug.h"
#include "Instruction.h"

class I_pickup : public Instruction {
    private:
        aux::tstate x;
        aux::tstate y;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};


#endif /* I_PICKUP_H */

