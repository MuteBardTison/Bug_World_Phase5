#include "l_sense.h"
#include "bug.h"
#include "aux.h"
#include "tokenizer.h"
#include "world.h"
#include "adjacent_cell.h"

bool cellmatch(World w, int x, int y, aux::tcondition condition, aux::tcolor color)
{
    bool match;
    Cell* cell = w.get_cell(aux::tposition(x, y));
    Bug* bug = w.bug_at(aux::tposition(x, y));
    if(cell->get_obstructed())
        //Rock: 5
        condition = aux::tcondition(5);//to change str to int
    else{
        switch(condition.cond) {
            //Friend
            case 0:
                match = cell->occupied() && color.c == bug->get_color().c;
                break;
            //Foe
            case 1:
                match = cell->occupied() && color.c != bug->get_color().c;
                break;
            //FriendWithFood
            case 2:
                match = cell->occupied() && color.c == bug->get_color().c && bug->get_has_food();
                break;
            //FoeWithFood
            case 3:
                match = cell->occupied() && color.c != bug->get_color().c && bug->get_has_food();
                break;
            //Food
            case 4:
                match = !cell->occupied() && cell->get_food() > 0;
                break;
            //Rock
            case 5:
                match = false;
                break;
            //Marker 0
            case 6:
                match = cell->mark.check_marker(aux::tmark(0),color);
                break;
            //Marker 1
            case 7:
                match = cell->mark.check_marker(aux::tmark(1),color);
                break;
            //FoeMarker
            case 8:
                match = cell->mark.check_other_marker(color);
                break;
            //Home
            case 9:
                match = w.base_at(aux::tposition(x, y), color);
                break;
            //FoeHome
            case 10:
                match = w.other_base_at(aux::tposition(x, y), color);
                break;
            //Marker 2
            case 11:
                match = cell->mark.check_marker(aux::tmark(2),color);
                break;
            //Marker 3
            case 12:
                match = cell->mark.check_marker(aux::tmark(3),color);
                break;
            //Marker 4
            case 13:
                match = cell->mark.check_marker(aux::tmark(4),color);
                break;
            //Marker 5
            case 14:
                match = cell->mark.check_marker(aux::tmark(5),color);
                break;
            default:
                break;
        }
    }
    return match;
}

void sensecell(int x, int y, aux::tdirection d,aux::tsensedir sen,int *sensex,int *sensey)
{
    if(sen.s==0){
        sensex=&x;
        sensey=&y;
    }
    else if(sen.s==1)
    {
        adjacentCell(x,y,d.d,sensex,sensey);

    }
    else if(sen.s==2)
    {
        adjacentCell(x,y,(d.d+5)%6,sensex,sensey);
    }
    else if(sen.s==3)
    {
        adjacentCell(x,y,(d.d+1)%6,sensex,sensey);
    }
}

void l_sense::execute(Bug b, World w){
    int sensex, sensey;
    aux::tposition t=b.get_position();
    aux::tdirection d=b.get_direction();
    aux::tcolor c=b.get_color();
    sensecell(t.x,t.y,d,dir,&sensex,&sensey);
    if(cellmatch(w,sensex,sensey,condition,c))
    {
        b.set_state(x);
    }
    else
    {
        b.set_state(y);
    }

}

void l_sense::parse(string args){
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    /*
    0-Here
    1-Ahead
    2-LeftAhead
    3-RightAhead
    */
    aux::tsensedir aux(s);
    dir=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    x=aux2;
    it++;
    s=*it;
    aux::tstate aux3(s);
    y=aux3;
    it++;
    s=*it;
    aux::tcondition t(s);
    condition=t;
}