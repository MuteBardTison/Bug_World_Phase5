#ifndef I_FLIP_H
#define I_FLIP_H
#include <math.h>
#include "Instruction.h"
#include "Bug.h"
#include "auxbug.h"

class I_flip: public Instruction {
    private:
        int p;
        auxbug::tstate x;
        auxbug::tstate y;
        int seed=12345;
        
        int randomint() {
            int s1 = (seed * 22695477 + 1) % int(pow(2, 30));
            int s2 = (s1 * 22695477 + 1) % int(pow(2, 30));
            int s3 = (s2 * 22695477 + 1) % int(pow(2, 30));
            int s4 = (s3 * 22695477 + 1) % int(pow(2, 30));
            int x = ((int)(s4 / pow(2, 16)) % int(pow(2, 30)));
            seed = s1;
            return x;
            }
    public:
        void execute(Bug b);
        void parse(std::string args);
};

#endif /* I_FLIP_H */