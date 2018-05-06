#ifndef I_MOVE_H
#define I_MOVE_H
#include "aux.h"
#include "Bug.h"
#include "World.h"

class I_move {
    private:
        aux::tstate x;
        aux::tstate y;
    public:
        void execute(Bug b, World w);
        void parse(string args);
};


#endif /* I_MOVE_H */

