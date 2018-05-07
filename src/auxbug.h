#ifndef AUXBUG_H
#define AUXBUG_H

#include <algorithm>
#include <string>

namespace auxbug {
    struct tcolor {
        int c; //0 or 1 for black or red 
        tcolor(int x) {
            if(x != 0 && x != 1)
                throw "The color is not in proper boundaries\n";
            c = x;
        };
        tcolor():c(0){};
    };

    struct tdirection {
        int d;
        tdirection(int x) {
            if(x < 0 || x > 5)
                throw "The direction is out of boundaries\n";
            d = x;
        };
        tdirection():d(0){};
    };

    struct tsensedir {
        int s;
        tsensedir(int x) {
            if(x < 0 || x > 3)
                throw "The sense direction is out of boundaries\n";
            s = x;
        };
        tsensedir(std::string a) {
            std::transform(a.begin(), a.end(), a.begin(), ::tolower);
            if(a == "here")
                s = 0;
            else if(a == "ahead")
                s = 1;
            else if(a == "leftahead")
                s = 2;
            else if(a == "rightahead")
                s = 3;
            else 
                throw "The sense direction is out of boundaries\n";
        };
    };

    struct tleftright {
        int l;
        tleftright(int x) {
            if(x != 0 || x != 1)
                throw "The leftright parameter is out of boundaries\n";
            l = x;
        };
        tleftright(std::string s) {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(s == "left")
                l = 0;
            else if(s == "right")
                l = 1;
            else
                throw "The leftright parameter is out of boundaries\n";
        }
    };

    struct tmark {
        int m;
        tmark():m(0){};
        tmark(int x) {
            if(x < 0 || x > 5)
                throw "The mark is out of boundaries\n";
            m = x;
        };
    };

    struct tstate {
        int st;
        tstate(int x):st(x) {
            if(st < 0 || st > 9999)
                throw "The state is out of boundaries\n";
        };
        tstate():st(0){};
        tstate(std::string x):st(std::stoi(x)) {
            if(st < 0 || st > 9999)
                throw "The state is out of boundaries\n";
        };
    };

    struct tcondition {
        int cond;
        tcondition(int x):cond(x){};
        tcondition(std::string s) {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(s == "friend")
                cond = 0;
            else if(s == "foe")
                cond = 1;
            else if(s == "friendwithfood")
                cond = 2;
            else if(s == "foewithfood")
                cond = 3;
            else if(s == "food")
                cond = 4;
            else if(s == "rock")
                cond = 5;
            else if(s == "marker(0)")
                cond = 6;
            else if(s == "marker(1)")
                cond = 7;
            else if(s == "foemarker")
                cond = 8;
            else if(s == "home")
                cond = 9;
            else if(s == "foehome")
                cond = 10;
            else if(s == "marker(2)")
                cond = 11;
            else if(s == "marker(3)")
                cond = 12;
            else if(s == "marker(4)")
                cond = 13;
            else if(s == "marker(5)")
                cond = 14;
            else 
                throw "Unspecified condition\n";
        }
    };

    struct tposition {
        int x;
        int y;
        tposition(int t, int q):x(t),y(q){};
        tposition():x(0),y(0){};
    };
};
#endif /* AUXBUG_H */

