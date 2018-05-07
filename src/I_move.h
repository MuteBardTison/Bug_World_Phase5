#ifndef I_MOVE_H
#define I_MOVE_H
#include "auxbug.h"
#include "Bug.h"
#include "World.h"
#include "Instruction.h"

class I_move : public Instruction{
    private:
        auxbug::tstate x;
        auxbug::tstate y;
    public:
        void execute(Bug b, World w);
        void parse(std::string args);
};


#endif /* I_MOVE_H */

