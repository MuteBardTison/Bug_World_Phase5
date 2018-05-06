#include "l_pickup.h"
#include <vector>
#include <string>
#include "bug.h"
#include "tokenizer.h"
#include "aux.h"
#include "instruction.h"


void l_pickup::execute(Bug b, World w)
{
    aux::tposition t=b.get_position();
    Cell &cell=*w.get_cell(t);
    if(b.get_has_food()||cell.get_food()==0)
    {
        b.set_state(y);
    }
    else
    {
        cell.set_food(cell.get_food()-1);
        b.set_has_food(true);
        b.set_state(x);
    }
}

void l_pickup::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tstate aux(s);
    x=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    y=aux2;
}