#ifndef MARKER_H
#define MARKER_H

#include "aux.h"

class Marker{
    private:
        unsigned int bits;

    public:
        Marker();        
        void check_inputs(aux::tmark mark, aux::tcolor color);
        void set_marker(aux::tmark mark, aux::tcolor color);
        void clear_marker(aux::tmark mark, aux::tcolor color);
        bool check_marker(aux::tmark mark, aux::tcolor color);
        bool check_other_marker(aux::tcolor color);
};

#endif /* MARKER_H */

