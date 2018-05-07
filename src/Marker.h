#ifndef MARKER_H
#define MARKER_H

#include "auxbug.h"

class Marker{
    private:
        unsigned int bits;

    public:
        Marker();        
        void check_inputs(auxbug::tmark mark, auxbug::tcolor color);
        void set_marker(auxbug::tmark mark, auxbug::tcolor color);
        void clear_marker(auxbug::tmark mark, auxbug::tcolor color);
        bool check_marker(auxbug::tmark mark, auxbug::tcolor color);
        bool check_other_marker(auxbug::tcolor color);
};

#endif /* MARKER_H */

