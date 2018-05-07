#include "I_flip.h"
#include <vector>
#include <string>
#include "tokenizer.h"

void I_flip::execute(Bug b) {
    int r = randomint();
    if(r == 0)
        b.set_state(x);
    else
        b.set_state(y);
}

void I_flip::parse(std::string args) {
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    p = std::stoi(s);
    it++;
    s = *it;
    auxbug::tstate auxbug(s);
    x = auxbug;
    it++;
    s = *it;
    auxbug::tstate auxbug2(s);
    y = auxbug2;
}