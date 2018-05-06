#ifndef PROGRAM_H
#define PROGRAM_H

#include "bug.h"
#include "instruction.h"
#include  <vector>
#include <map>
#include "l_drop.h"
#include "l_direction.h"
#include "l_flip.h"
#include "l_mark.h"
#include "l_move.h"
#include "l_pickup.h"
#include "l_sense.h"
#include "l_turn.h"
#include "l_unmark.h"
#include <utility>

class Program{
private:
  int id;
  vector<l_direction> ldi;
  vector<l_drop> ldr;
  vector<l_flip> lfl;
  vector<l_mark> lma;
  vector<l_move> lmo;
  vector<l_pickup> lpi;
  vector<l_sense> lse;
  vector<l_turn> ltu;
  vector<l_unmark> lun;
  map<int,pair<int,string>> order;
  World w;
  /*
  The values in order tell from which vector must we take the next command 
  and also the order of the command in the respective vector
  */
  int i;//number of instructions
public:
  Program(std::string filename, World w);
  Program(){};
  void step(Bug b, World w);

};


#endif

