#include "Cell.h"
#include "aux.h"

void adjacentCell(int x, int y, int d, int *adjx, int *adjy) {
    switch(d){
        case 0:
            *adjx = x + 1;
            *adjy = y;
            break;
        case 1:
            if(y % 2 == 0) {
                *adjx = x;
                *adjy = y + 1;
            }
            else {
                *adjx = x + 1;
                *adjy = y + 1;
            }
            break;
        case 2:
            if(y % 2 == 0) {
                *adjx = x - 1;
                *adjy = y + 1;
            }
            else {
                *adjx = x;
                *adjy = y + 1;    
            }
            break;
        case 3:
            *adjx = x - 1;
            *adjy = y;
            break;
        case 4:
            if(y % 2 == 0) {
                *adjx = x - 1;
                *adjy = y - 1;
            }
            else {
                *adjx = x;
                *adjy = y - 1;
            }    
            break;
        case 5:
            if(y % 2 == 0) {
                *adjx = x;
                *adjy = y - 1;
            }
            else {
                *adjx = x + 1;
                *adjy = y - 1;
            }
            break;
        default:
            throw "The direction isn't in the proper boundaries\n";
            break;
    }
}