#include "I_sense.h"

#include "tokenizer.h"
#include "adjacent_cell.h"

bool cellmatch(World w, int x, int y, auxbug::tcondition condition, auxbug::tcolor color)
{
    bool match = false;
    Cell* cell = w.get_cell(auxbug::tposition(x, y));
    Bug* bug = w.bug_at(auxbug::tposition(x, y));
    if(cell->get_obstructed())
        //Rock: 5
        condition = auxbug::tcondition(5);//to change str to int
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
                match = cell->mark.check_marker(auxbug::tmark(0),color);
                break;
            //Marker 1
            case 7:
                match = cell->mark.check_marker(auxbug::tmark(1),color);
                break;
            //FoeMarker
            case 8:
                match = cell->mark.check_other_marker(color);
                break;
            //Home
            case 9:
                match = w.base_at(auxbug::tposition(x, y), color);
                break;
            //FoeHome
            case 10:
                match = w.other_base_at(auxbug::tposition(x, y), color);
                break;
            //Marker 2
            case 11:
                match = cell->mark.check_marker(auxbug::tmark(2),color);
                break;
            //Marker 3
            case 12:
                match = cell->mark.check_marker(auxbug::tmark(3),color);
                break;
            //Marker 4
            case 13:
                match = cell->mark.check_marker(auxbug::tmark(4),color);
                break;
            //Marker 5
            case 14:
                match = cell->mark.check_marker(auxbug::tmark(5),color);
                break;
            default:
                throw "Cell Match Error.\n";
                break;
        }
    }
    return match;
}

void sensecell(int x, int y, auxbug::tdirection d,auxbug::tsensedir sen,int *sensex,int *sensey)
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

void I_sense::execute(Bug b, World w){
    int sensex, sensey;
    auxbug::tposition t=b.get_position();
    auxbug::tdirection d=b.get_direction();
    auxbug::tcolor c=b.get_color();
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

void I_sense::parse(std::string args){
    std::vector<std::string> command = tokens_in_vector(args);
    std::vector<std::string>::iterator it = command.begin();
    it++;
    std::string s = *it;
    /*
    0-Here
    1-Ahead
    2-LeftAhead
    3-RightAhead
    */
    auxbug::tsensedir auxbug(s);
    dir = auxbug;
    it++;
    s = *it;
    auxbug::tstate auxbug2(s);
    x = auxbug2;
    it++;
    s = *it;
    auxbug::tstate auxbug3(s);
    y = auxbug3;
    it++;
    s = *it;
    auxbug::tcondition t(s);
    condition = t;
}