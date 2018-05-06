/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bug.h"
#include <iostream>

using namespace std;

void Bug::bug_stats(){
    cout << "Bug stats: \n";
    cout << "Color:" << color.c << endl;
    cout << "ProgID:" << prog_id << endl;
    cout << "Dead:" << dead << endl;
    cout << "Resting:" << resting << endl;
}