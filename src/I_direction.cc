#include "I_direction.h"
#include <vector>
#include <string>
#include "Bug.h"
#include "tokenizer.h"


void I_direction::execute(Bug b) {
    auxbug::tdirection di=b.get_direction();
    if(di.d == d.d) {
        b.set_state(x);
    }
    else
        b.set_state(y);   
}

void I_direction::parse(std::string args) {
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    auxbug::tdirection a(std::stoi(s));
    d = a;
    it++;
    s = *it;
    auxbug::tstate auxbug(s);
    x = auxbug;
    it++;
    s = *it;
    auxbug::tstate auxbug2(s);
    y = auxbug2;
}