#include "Marker.h"
#include "Bug.h"
#include <iostream>

Marker::Marker() {
    bits = 0; //set all bits to 0 at initialization
}

void Marker::check_inputs(auxbug::tmark mark, auxbug::tcolor color) {
    if(!(mark.m >= 0 && mark.m <= 5)) {
        throw std::invalid_argument("Mark must be number between 0 and 5\n");
    }
    else if(!(color.c == 0 || color.c == 1)) {
        throw std::invalid_argument("Color must be either 0 or 1\n");
    }
}

void Marker::set_marker(auxbug::tmark mark, auxbug::tcolor color) {
    check_inputs(mark, color);
    switch (color.c) {
        case 0: //black
            bits |= (1UL << mark.m); //sets bit mark.m from the right by shifting 0000000001 left by mark.m places
            break;
        case 1://red
            bits |= (1UL << (mark.m + 6)); //sets bit (mark.m + 6) from the right
            break;
    }
}

void Marker::clear_marker(auxbug::tmark mark, auxbug::tcolor color) {
    check_inputs(mark, color);
    switch (color.c) {
        case 0://black
            bits &= ~(1UL << mark.m); //unsetting the bit mark.m from the right by shifting 000000001 left and negating/ AND gating
            break;
        case 1://red
            bits &= ~(1UL << (mark.m + 6));
            break;
    }
}

bool Marker::check_marker(auxbug::tmark mark, auxbug::tcolor color) {
    check_inputs(mark, color);
    int bit;
    switch (color.c) {
        case 0://black
            bit = (bits >> mark.m) & 1U;
            return (bit == 1);
        case 1://red
            bit = (bits >> (mark.m + 6)) & 1U;
            return (bit == 1);
    }
    throw std::invalid_argument("Check Marker Error.\n");
}

bool Marker::check_other_marker(auxbug::tcolor color) {
    auxbug::tmark mark;
    mark.m = 0;
    check_inputs(mark, color); /*set mark to 0 so that the first case passes and color is checked */
    int bit;
    switch (color.c) {
        case 0://black
            for (int i = 0; i < 5; i++) {
                bit = (bits >> i) & 1U;
                if (bit == 1) return true;
            }
            return false;
        case 1://red
            for (int i = 0; i < 5; i++) {
                bit = (bits >> (i + 5)) & 1U;
                if (bit == 1) return true;
            }
            return false;
    }
    throw std::invalid_argument("Check Marker Error.\n");
}

