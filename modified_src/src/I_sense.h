#ifndef I_SENSE_H
#define I_SENSE_H
#include "aux.h"
#include "World.h"
#include "Bug.h"
#include "tokenizer.h"
#include "adjacent_cell.h"

class I_sense: public Instruction {
    private:
        tsensedir dir;
        tstate x;
        tstate y;
        tcondition condition;
    public:
        void execute(Bug b, World w);
        void parse(string args);
};

#endif /* I_SENSE_H */

