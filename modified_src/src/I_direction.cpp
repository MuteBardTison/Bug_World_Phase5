#include "I_direction.h"
#include <vector>
#include <string>
#include "bug.h"
#include "tokenizer.h"
#include "aux.h"
#include "Instruction.h"

void I_direction::execute(Bug b)
{
    aux::tdirection di=b.get_direction();
    if(di.d==d.d)
    {
        b.set_state(x);
    }
    else
        b.set_state(y);   
}

void I_direction::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tdirection a(std::stoi(s));
    d=a;
    it++;
    s=*it;
    aux::tstate aux(s);
    x=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    y=aux2;
}