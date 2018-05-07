#include "I_direction.h"
#include <vector>
#include <string>
#include "Bug.h"
#include "tokenizer.h"


void I_direction::execute(Bug b) {
    aux::tdirection di=b.get_direction();
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
    aux::tdirection a(std::stoi(s));
    d = a;
    it++;
    s = *it;
    aux::tstate aux(s);
    x = aux;
    it++;
    s = *it;
    aux::tstate aux2(s);
    y = aux2;
}