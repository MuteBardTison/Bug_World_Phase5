#include "I_drop.h"
#include <vector>
#include <string>
#include "tokenizer.h"

void I_drop::execute(Bug b, World w ) {
    auxbug::tposition t = b.get_position();
    Cell &cell = *(w.get_cell(t));
    if(b.get_has_food()) {
        cell.set_food(cell.get_food() + 1);
        b.set_has_food(false);
    }
    b.set_state(z);   
}

void I_drop::parse(std::string args) {
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    auxbug::tstate auxbug(s);
    z = auxbug;
}