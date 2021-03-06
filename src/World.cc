#include "World.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include "tokenizer.h"
#include "Program.h"

bool even(int n){
    return (n % 2);
}

bool odd(int n){
    return !(n % 2);
}

int World::load(std::string filenames){
    std::vector<std::string> files = tokens_in_vector(filenames);
    std::vector<std::string>::iterator it = files.begin();
    std::ifstream wf, pf;
    std::string line;
    auxbug::tcolor black;
    auxbug::tcolor red;
    black.c = 0;
    red.c = 1;
    int bbcount = 0;
    int rbcount = 0;
    wf.open(*it, std::ios::in);
    if(wf.is_open()){
        wf >> width >> length;
    }
    else{
        error("No such file exists. Check again? \n");
        return 1;
    }
    std::cout << "Width: "<< width << std::endl;
    std::cout << "Length: " << length << std::endl;
    
    cell_container.resize(length);
    std::cout << "Mother vector resized \n" ;
            
    for(size_t i = 0; i < width; i++){
        cell_container[i].resize(width);
    }
    std::cout << "Child vectors resized \n";
    
    getline(wf, line);
    std::cout << line;
    for (int l = 0; l < length; l++){
        getline(wf, line);
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        for (int w = 0; w < width; w++){
            //std::cout << line[w];
            Cell *new_cell = new Cell(line[w]);
            cell_container[l][w] = new_cell;
            if(line[w] == '+'){
                //Bug new_bug = (new_cell->get_occupant());                
                Bug *new_bug = new Bug(red, rbcount+bbcount, 0);
                new_bug->set_position(w, l);
                new_bug->set_has_food(false);
                redbugs.push_back(new_bug);
                new_cell->set_occupant(redbugs[rbcount]);
                rbcount++;
                //std::cout << "Red bug home base found; Creating a bug...\n";
            }
            if(line[w] == '-'){
                //Bug new_bug = (new_cell->get_occupant());
                Bug *new_bug = new Bug(black, bbcount+rbcount, 0);
                new_bug->set_position(w, l);
                new_bug->set_has_food(false);
                blackbugs.push_back(new_bug);
                new_cell->set_occupant(blackbugs[bbcount]);
                bbcount++;
                //std::cout << "Black bug home base found; Creating a bug...\n";
            }
            
            //std::cout << "Cell assigned successfully" << std::endl;
        }
        std::cout << std::endl;
        
    }
    it++;
    Program b = Program(filenames, *this);//program black bugs
    pb = &b;
    Program r = Program(filenames, *this);//program red bugs
    pr = &r;
    std::cout << "World initialization complete.\n";
    return 0;
}

int World::cell_test() {
    for(int l = 0; l < length; l++) {
        for(int w = 0; w < width; w++) {
            if(cell_container[l][w]) {
                //std::cout << "Cell " << l << " " << w << " exists. \n" << std::endl;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

auxbug::tposition World::adjacent(auxbug::tdirection dir, auxbug::tposition pos) {
    int d = dir.d;
    auxbug::tposition res;
    switch(d) {
        case 0:
            res.x = pos.x + 1;
            res.y = pos.y;
            break;
        case 1:
            if(even(pos.y)) {
                res.x = pos.x;
                res.y = pos.y + 1;
            }
            else{
                res.x = pos.x + 1;
                res.y = pos.y + 1;
            }
            break;
        case 2:
            if(even(pos.y)) {
                res.x = pos.x - 1;
                res.y = pos.y + 1;
            }
            else{
                res.x = pos.x;
                res.y = pos.y + 1;
            }
            break;
        case 3:
            res.x = pos.x - 1;
            res.y = pos.y;
            break;
        case 4:
            if(even(pos.y)) {
                res.x = pos.x - 1;
                res.y = pos.y - 1;
            }
            else{
                res.x = pos.x;
                res.y = pos.y - 1;
            }
            break;
        case 5:
            if(even(pos.y)) {
                res.x = pos.x;
                res.y = pos.y - 1;
            }
            else{
                res.x = pos.x + 1;
                res.y = pos.y - 1;
            }
            break;
        default:
            res.x = -1;
            res.y = -1;
            throw std::invalid_argument("Invalid direction integer!\n");
            ///raise exception here;
            break;
    }
    return res;
    
}

auxbug::tcolor World::other_color(auxbug::tcolor c) {
    auxbug::tcolor res;
    res.c = 1 - c.c;
    return res;
}

//winner method

int World::red_food() {
    int count = 0;
    for(int i = 0; i < World::red_count(); i++) {
        if(redbugs[i]->get_has_food()) {
            std::cout << "Red Bug "<< i << " has food\n";
            count++;
        }
    }
    return count;
}

int World::black_food() {
    int count = 0;
    for(int i = 0; i < World::black_count(); i++) {
        if(blackbugs[i]->get_has_food()) {
            std::cout << "Black Bug "<< i << " has food\n";
            count++;
        }
    }
    return count;
}

int World::red_count() {
    return redbugs.size();
}
int World::black_count() {
    return blackbugs.size();
}

void World::error(std::string msg) {
    std::cout << msg << std::endl;
}

void World::log(std::string msg) {
    std::ofstream logfile;
    logfile.open("log.txt", std::ios::out);
    if(logfile.is_open()) {
        logfile << msg << std::endl;
        std::cout << "successfully logged \n"; 
    }
    logfile.close();  
}

void World::print_grid(){
    for(int i = 0; i < cell_container.size(); i++){
        for(int j = 0; j < cell_container[0].size(); j++){
            std::cout << cell_container[i][j]->get_char() << " ";
        }
        std::cout << std::endl;
    }
}

void World::place_at(auxbug::tposition p, Bug* b) {
    if(cell_container[p.y][p.x]->occupied()) {
        throw std::invalid_argument("The cell is already occupied!");
    }
    else{
        b->set_position(p.x, p.y);
    }
}

int World::food_at(auxbug::tposition p) {
    return get_cell(p)->get_food();
}

bool World::set_food_at(auxbug::tposition p, int f){ //not additive;
    if(get_cell(p)->get_obstructed() ){
        return false;
    }
    else{
        get_cell(p)->set_food(f);
        return true;
    }
}
    
bool World::base_at(auxbug::tposition p, auxbug::tcolor c) {
    if(c.c == 0) {
        return get_cell(p)->is_black_home_area();
    }
    else 
        return get_cell(p)->is_red_home_area();
}

bool World::other_base_at(auxbug::tposition p, auxbug::tcolor c) {
    return !base_at(p, c);
}
    
//Martial arts
int World::adjacent_other_bugs(auxbug::tposition p, auxbug::tcolor c) {
    auxbug::tdirection d;
    int count = 0;
    for(int i = 0; i < 6; i++) {
        d.d = i;
        auxbug::tposition adjp = adjacent(d, p);
        if(get_cell(adjp)->occupied()) {
            if(get_cell(adjp)->get_occupant()->get_color().c == c.c) {
                count++;
            }
        }
    }
    return count;
}

void World::kill_if_surrounded(auxbug::tposition p) {
    if(p.x < 1 || p.y < 1 || p.x > width - 2 || p.y > length - 2) {
        //std::cout << "Invalid coordinates. \n";
        return;
    }
    if(get_cell(p)->occupied()) {
        Bug* b = get_cell(p)->get_occupant();
        auxbug::tcolor oc = other_color(b->get_color());
        if(adjacent_other_bugs(p, oc) > 4) {
            std::cout <<"This bug is surrounded! Alas, I must commit seppuku...\n";
            int i = 0;
            if (b->get_has_food()) { //drop an extra food if bug had one
                i = 1;
            }
            
            //set the cell up accordingly 
            set_food_at(p, (5 + i));
            std::cout << "Coordinates of the dead bug: \n" << "x: " << p.x << " y: " << p.y << std::endl;
            get_cell(p)->get_occupant()->kill();
            get_cell(p)->set_occupant(NULL);
            get_cell(p)->set_occupancy(false);
        }
        else{
           //std::cout <<"I shall live to see another day!\n";
        }
    }
}

void World::check_for_surrounded_bugs(auxbug::tposition p) {
    kill_if_surrounded(p);
    auxbug::tdirection dir;
    for(int d = 0; d < 6; d++) {
        dir.d = d;
        kill_if_surrounded(adjacent(dir, p));
    }
}

void World::execute_cycle() {
   int rbcount = redbugs.size();
   int bbcount = blackbugs.size();
   int r = 0;//index red bugs
   int b = 0;//index black bugs
   for(int i = 0;i < rbcount + bbcount; i++) {
        if(redbugs[r]->get_prog_id() == i) {
           pr->step(*redbugs[r], *this);
           r++;
        }
        if(blackbugs[b]->get_prog_id() == i) {
            pr->step(*blackbugs[b], *this);
            b++;
        }
   }
}

auxbug::tcolor World::winner() {
    int foodb = 0, foodr = 0;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            if(cell_container[i][j]->is_black_home_area()) {
                foodb += cell_container[i][j]->get_food();
            }
            if(cell_container[i][j]->is_red_home_area()) {
                foodr += cell_container[i][j]->get_food();
            }
        }
    }
    if(foodr > foodb) {
        return auxbug::tcolor(0);
    }
    else
        return auxbug::tcolor(1);
}