#include "I_move.h"
#include <vector>
#include <string>
#include "tokenizer.h"
#include "Instruction.h"
#include "checkforbugs.h"

void I_move::execute(Bug b, World w) {
    int nx,ny;
    auxbug::tposition t = b.get_position();
    adjacentCell(t.x, t.y, b.get_direction(), &nx, &ny);
    auxbug::tposition n(nx, ny);
    Cell &cell = *w.get_cell(n);
    Cell &oldcell = *w.get_cell(t);
    if(cell.get_obstructed() || cell.occupied()) {
        b.set_state(y);
    }
    else {
        cell.set_occupant(&b);
        oldcell.set_occupancy(false);
        b.set_position(nx,ny);
        b.set_state(x);
        b.start_resting();
        checkforbugs(&w, nx, ny);
    }
}

void I_move::parse(std::string args) {
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    auxbug::tstate auxbug(s);
    x = auxbug;
    it++;
    s = *it;
    auxbug::tstate auxbug2(s);
    y = auxbug2;
}