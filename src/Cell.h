#ifndef CELL_H
#define CELL_H

#include "Bug.h"
#include "Marker.h"

class Cell{
    private:
        Bug* occupant;
        bool obstructed; //Blocked cell
        int food;
        bool home_black_bug;
        bool home_red_bug;
        bool occupant_set;
        char c;
    public:
        Marker mark;
        Cell(char symb);
        Bug* get_occupant();
        void set_occupant(Bug* new_occupant);
        void set_occupancy(bool);
        int get_food();
        void set_food(int new_food);
        bool get_obstructed();
        bool is_black_home_area();
        bool is_red_home_area();
        bool occupied();
        char get_char();
};

#endif /* CELL_H */

