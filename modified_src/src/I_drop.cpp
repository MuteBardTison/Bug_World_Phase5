#include "I_drop.h"
#include <vector>
#include <string>

void I_drop::execute(Bug b, World w )
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

void I_drop::parse(std::string args)
{
    vector<std::string> command=tokens_in_vector(args);
    vector<std::string>::iterator it=command.begin();
    it++;
    std::string s=*it;
    aux::tstate aux(s);
    z=aux;
}