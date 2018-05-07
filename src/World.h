#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Bug.h"
#include "auxbug.h"
#include "Cell.h"

class Program;

#define MAX_SIZE 500;

class World {
    private:
        int width;
        int length;
        Program* pb;//program for black bugs
        Program* pr; //program for red bugs
        std::vector<Bug*> redbugs;
        std::vector<Bug*> blackbugs;
        std::vector< std::vector<Cell*> > cell_container;
        
    public:
        World() {
            width = 0;
            length = 0;
        };
        ~World(){};
        int load(std::string);
        void execute_cycle();
        //cell::Cell get_cell(auxbug::tposition);
        auxbug::tposition adjacent(auxbug::tdirection, auxbug::tposition);
        auxbug::tcolor other_color(auxbug::tcolor);
        auxbug::tcolor winner();
        int red_food();
        int black_food();
        int red_count();
        int black_count();
        void error(std::string);
        void log(std::string);
        void print_grid();
        int cell_test();
        int get_length(){
            return length;
        };
        Cell* get_cell(auxbug::tposition p){
            return cell_container[p.y][p.x];
        }
        int get_width(){
            return width;
        };
        std::vector<Bug*> get_redbugs(){
            return redbugs;
        }
        std::vector<Bug*> get_blackbugs(){
            return blackbugs;
        }
        std::vector< std::vector<Cell*> > get_cellcont(){
            return cell_container;
        }
        
        Bug* bug_at(auxbug::tposition p){
            return cell_container[p.y][p.x]->get_occupant();
        }
        void place_at(auxbug::tposition, Bug*);
        int food_at(auxbug::tposition);
        bool set_food_at(auxbug::tposition, int);
        
        bool base_at(auxbug::tposition, auxbug::tcolor);
        bool other_base_at(auxbug::tposition, auxbug::tcolor);
        
        //Martial arts
        int adjacent_other_bugs(auxbug::tposition, auxbug::tcolor);
        void kill_if_surrounded(auxbug::tposition);
        void check_for_surrounded_bugs(auxbug::tposition);
};

#endif /* WORLD_H */

