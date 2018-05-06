#include "Bug.h"
#include <iostream>

void Bug::bug_stats(){
    std::cout << "Bug stats: \n";
    std::cout << "Color:" << color.c << std::endl;
    std::cout << "ProgID:" << prog_id << std::endl;
    std::cout << "Dead:" << dead << std::endl;
    std::cout << "Resting:" << resting << std::endl;
}