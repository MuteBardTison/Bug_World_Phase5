#include "World.h"
#include "Bug.h"
#include "Cell.h"
#include "adjacent_cell.h"
#include "auxbug.h"

int otherColor(auxbug::tcolor val) {
    if(val.c==0)
        return 1;
    else
        return 0;
}

int adjacentBug(World &w, int x, int y, int color) {
    int nb=0;
    for(int dir = 0; dir < 6; dir++) {
        int adjx, adjy;
        adjacentCell(x, y, dir, &adjx, &adjy);
        auxbug::tposition t(adjx, adjy);
        Cell &cell = *w.get_cell(t);
        if(cell.occupied()) {
            Bug &b = *cell.get_occupant();
            if(b.get_color().c==color) {
                nb++;
            }
        }
    }
    return nb;
}

void checkforsurrounded(World *w, int x, int y) {
    auxbug::tposition t(x,y);
    Cell &cell = *w->get_cell(t);
    if(cell.occupied()) {
        Bug &bug = *cell.get_occupant();
        //if surrounded, kill bug and leave food in the cell
        if(adjacentBug(*w, x, y, otherColor(bug.get_color())) >= 5) {
            cell.set_occupancy(false);
            bug.kill();
            int val = bug.get_has_food();
            cell.set_food(cell.get_food() + val);
        }
    }
}

//checks for adjacent bugs
void checkforbugs(World *w, int x, int y) {
    checkforsurrounded(w,x,y);
    for(int dir = 0; dir < 6; dir++) {
        int adjx, adjy;
        adjacentCell(x, y, dir, &adjx, &adjy);
        checkforsurrounded(w, adjx, adjy);
    }
}
