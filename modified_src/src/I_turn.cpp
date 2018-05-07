#include "I_turn.h"
#include <vector>
#include <string>
#include "tokenizer.h"
#include "aux.h"
#include "Instruction.h"

int turn (aux::tleftright l, aux::tdirection dir) {
    switch(l.l) {
        case 0://left
            return (dir.d + 5) % 6;
            break;
        case 1://right
            return (dir.d + 1) % 6;
            break;
        default:
            throw "Turn value error.\n";
            break;
    }
}

void I_turn::execute(Bug b) {
    b.set_direction(turn(lr, b.get_direction()));
    b.set_state(z);
}

void I_turn::parse(std::string args) {
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    aux::tleftright aux(s);
    lr = aux;
    it++;
    s = *it;
    aux::tstate aux2(s);
    z = aux2;
}