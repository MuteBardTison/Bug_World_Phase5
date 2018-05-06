#ifndef I_DIRECTION_H
#define I_DIRECTION_H
#include "aux.h"

class I_direction : public Instruction {
    private:
        aux::tdirection d;
        aux::tstate x;
        aux::tstate y;
    public:
        void execute(Bug b);
        void parse(std::string args);    
};

#endif /* I_DIRECTION_H */

