#include "l_turn.h"
#include <vector>
#include <string>
#include "bug.h"
#include "tokenizer.h"
#include "aux.h"
#include "instruction.h"


int turn (aux::tleftright l,aux::tdirection dir)
{
    switch(l.l)
    {
        case 0://left
            return (dir.d+5)%6;
        break;
        case 1://right
            return (dir.d+1)%6;
        break;
    }
}

void l_turn::execute(Bug b)
{
    b.set_direction(turn(lr,b.get_direction()));
    b.set_state(z);
}

void l_turn::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tleftright aux(s);
    lr=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    z=aux2;
}