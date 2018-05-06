/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruction.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:19 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "aux.h"
#include "world.h"
#include "bug.h"

class Instruction
{
private:
    
public:
    void execute(Bug b);
    void parse(string args);
};

#endif /* INSTRUCTION_H */

