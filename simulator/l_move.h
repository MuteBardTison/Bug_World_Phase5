/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_move.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:53 PM
 */

#ifndef L_MOVE_H
#define L_MOVE_H
#include "aux.h"

class l_move{
private:
    aux::tstate x;
    aux::tstate y;
public:
    void execute(Bug b, World w);
    void parse(string args);
};


#endif /* L_MOVE_H */

