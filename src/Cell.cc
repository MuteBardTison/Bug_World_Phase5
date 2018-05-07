#include <iostream>
#include "Cell.h"

Cell::Cell(char symb) {
    food = 0;
    c = symb;
    if (symb == '#') {
        obstructed = true;
        home_black_bug = false;
        home_red_bug = false;
        //cout << "Created obstructed cell \n";

    } 
    else if (symb == '-') {
        obstructed = false;
        home_black_bug = true;
        home_red_bug = false;
        //cout << "Created black home cell cell \n";
    } 
    else if (symb == '+') {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = true;
        //cout << "Created red home cell \n";
    } 
    else if (symb == '.') {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = false;
        //cout << "Created empty cell \n";
    } 
    else if (symb >= 49 && symb <= 57) {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = false;
        food = symb - '0';
        //cout << "Created food cell \n";
    } 
    else {
        throw std::invalid_argument("Invalid symbol\n");
    }
}

Bug* Cell::get_occupant() {
    if(occupant_set){
        return occupant;
    }
    else{
        throw std::invalid_argument("Occupant hasn't been set yet");
    }
}

void Cell::set_occupant(Bug* new_occupant) {
    if(!occupant_set) occupant_set = true;
    occupant = new_occupant;
}


void Cell::set_occupancy(bool b) {
    occupant_set = b;
    occupant=NULL;
}

int Cell::get_food() {
    return food;
}

void Cell::set_food(int new_food) {
    if (new_food >= 0) {
        food = new_food;
    } 
    else {
        throw std::invalid_argument("Food can't be negative valued.");
    }
}

bool Cell::get_obstructed() {
    return obstructed;
}

bool Cell::is_black_home_area() {
    return home_black_bug;
}

bool Cell::is_red_home_area() {
    return home_red_bug;
}

bool Cell::occupied(){
    return occupant_set;
}

char Cell::get_char(){
    return c;
}