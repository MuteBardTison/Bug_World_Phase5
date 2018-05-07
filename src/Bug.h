#ifndef BUG_H
#define BUG_H

#include "auxbug.h"

class Bug{
    private:
        auxbug::tstate state;
        auxbug::tcolor color;
        auxbug::tdirection direction;
        int resting;
        bool has_food = false;
        int prog_id;
        auxbug::tposition pos;
        bool dead = false;
        int remaining_rest = 0;

    public:
        Bug();
        ~Bug(){};
        Bug(auxbug::tcolor c, int new_pid, int new_resting);
        int get_state();
        void set_state(auxbug::tstate s);
        int get_direction();
        void set_direction(int dir);
        bool get_has_food();
        void set_has_food(bool f);
        auxbug::tcolor get_color();
        void set_color(int cl);
        int get_prog_id();
        void set_position(int x, int y);
        auxbug::tposition get_position();
        void start_resting();
        bool rested();
        bool is_dead();
        void kill();
        void bug_stats();

        inline bool operator== (const Bug& b) { 
            if((b.color.c == color.c) && (b.prog_id == prog_id)) {
                return true;
            }
            return false;                
        }
};

#endif /* BUG_H */

