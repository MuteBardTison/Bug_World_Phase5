/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_mark.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:34 PM
 */

#ifndef L_MARK_H
#define L_MARK_H
#include "aux.h"
#include "instruction.h"
using namespace aux;

class l_mark: public Instruction{
private:
    int m;
    tstate z;
public:
    void execute(Bug b, World w);
    void parse(std::string args);
};

#endif /* L_MARK_H */

