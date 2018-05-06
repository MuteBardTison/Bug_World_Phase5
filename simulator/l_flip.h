/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_flip.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:23 PM
 */

#ifndef L_FLIP_H
#define L_FLIP_H
#include <math.h>

class l_flip: public Instruction
{
private:
    int p;
    aux::tstate x;
    aux::tstate y;
    int seed=12345;
    
    int randomint(){
        int i;
        int s1=(seed*22695477+1)%int(pow(2,30));
        int s2=(s1*22695477+1)%int(pow(2,30));
        int s3=(s2*22695477+1)%int(pow(2,30));
        int s4=(s3*22695477+1)%int(pow(2,30));
        int x=((int)(s4/pow(2,16))%int(pow(2,30)));
        seed=s1;
        return x;
        }
public:
    void execute(Bug b);
    void parse(string args);
};

#endif /* L_FLIP_H */

