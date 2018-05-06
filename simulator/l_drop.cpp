#include "l_drop.h"
#include <vector>
#include <string>
#include "bug.h"
#include "tokenizer.h"
#include "aux.h"
#include "instruction.h"


void l_drop::execute(Bug b, World w )
{
    aux::tposition t=b.get_position();
    Cell &cell=*(w.get_cell(t));
    if(b.get_has_food())
    {
        cell.set_food(cell.get_food()+1);
        b.set_has_food(false);
    }
    b.set_state(z);   
}

void l_drop::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tstate aux(s);
    z=aux;
}