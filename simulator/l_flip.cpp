#include "l_flip.h"
#include <vector>
#include <string>
#include "bug.h"
#include "tokenizer.h"
#include "aux.h"
#include "instruction.h"


void l_flip::execute(Bug b)
{
    int r=randomint();
    if(r==0)
        b.set_state(x);
    else
        b.set_state(y);
}

void l_flip::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    p=std::stoi(s);
    it++;
    s=*it;
    aux::tstate aux(s);
    x=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    y=aux2;
}