#include "Bug.h"
#include <iostream>

Bug::Bug() {
    color.c = 0;
    prog_id = 999;
    resting = 0;
    dead = false;
    direction.d = 0;
    has_food = false;  
}

Bug::Bug(auxbug::tcolor c, int new_pid, int new_resting) {
    if(c.c > 1 || c.c < 0) {
        throw std::invalid_argument("Color number must be 0 or 1.\n");
    }
    color = c;
    prog_id = new_pid;
    resting = new_resting;
    remaining_rest=0;   
}

int Bug::get_state() {
    return state.st;
}

void Bug::set_state(auxbug::tstate s) {
    state = s;
}

int Bug::get_direction() {
    return direction.d;
}

void Bug::set_direction(int dir) {
    direction.d = dir;
}

bool Bug::get_has_food() {
    return has_food;
}

void Bug::set_has_food(bool f) {
    if(has_food == true && f == true) {
        throw std::invalid_argument("Bug already has food! \n");
    }
    if(has_food == false && f == true) {
        throw std::invalid_argument("Grabbing food!\n");
    }
    has_food = f;
}

auxbug::tcolor Bug::get_color() { //this returns either a 0 or 1, i.e. black or red. 
    return color; 
}

void Bug::set_color(int cl) {
    if(cl < 0 || cl > 1) {
        throw std::invalid_argument("Color must be 1 or 0.\n");
    }
    color.c = cl;
}

int Bug::get_prog_id() {
    return prog_id;
}

void Bug::set_position(int x, int y) {
    pos.x = x;
    pos.y = y;
}

auxbug::tposition Bug::get_position() {
    return pos;
}

void Bug::start_resting() {
    if(remaining_rest == resting)
        throw std::invalid_argument("The bug was already resting\n");
    remaining_rest=resting; 
}

bool Bug::rested(){
    if(remaining_rest > 0) {
        remaining_rest--;
        return false;
    }
    else
        return true;
}

bool Bug::is_dead() {
    return dead;
}

void Bug::kill() {
    if(dead == true) {
        throw std::invalid_argument("Bug is already dead!\n");
    }
    dead = true;
}

void Bug::bug_stats(){
    std::cout << "Bug stats: \n";
    std::cout << "Color:" << color.c << std::endl;
    std::cout << "ProgID:" << prog_id << std::endl;
    std::cout << "Dead:" << dead << std::endl;
    std::cout << "Resting:" << resting << std::endl;
}

int Bug::get_resting() {
    return resting;
}