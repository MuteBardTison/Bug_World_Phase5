README for parts done by Seongjin Bien
Phase 1 of Software Engineering

NOTE: Instructions on how to setup the googletest environment has been included in the other README, specifically by Mohit. 

Index.
0. aux.h
1. bug.h + bug.cpp
2. world.h + world.cpp
3. bugtest.cpp
4. worldtest.cpp 

----------------

0. aux.h

aux.h implements the required auxillary structures for the program, e.g.
    tdirection
    tposition
    tcolor
    and so on.

1. bug.h + bug.cpp

Bug class:
private:
    state
    color
    direction
    resting
    has_food
    prog_id
    pos (for position)
    dead   
    remaining_rest

public:
    refer to the header file

Most of the methods for the bug class has been implemented in the header file, since the methods are quite simple and thus doesn't occupy so much memory when loaded in. Also, the methods are used very frequently

bug.cpp just has one method, bug_stats(), which prints out the attributes the corresponding bug has. This has been put in separately since this is a mostly bug-fixing feature.

2. world.h + world.cpp

World class:
private: 
    width
    length
    redbugs
    blackbugs
    cell_container
public:
    refer to header file for greater detail.

The playground of our little game. The methods have been neatly separated into cpp and h files, since they tend to be rather complex. Save for the winner() and execute_cycle() methods, the rest have been more or less fully implemented. 

The load(char*) method still needs some touching, especially with parsing the second program.txt file, but that will be left for later. For now, it corretly parses the world.txt file (pulled out from bugs.pdf) and creates the right cell and creates an instance of bug if it is a home cell with the corresponding position. 

Adjacency method also works. 

3. bugtest.cpp 

A googletest-based testing file for trying out various methods in the Bug class.

4. worldtest.cpp

A googletest-based testing file for trying out various methods in the World class. Currently, the load file works correctly, among many others. There is a weird bug right now, where setting one member of the redbugs & blackbugs vector to have food changes the property for every single other member. Due to time constraints, this hasn't been fully figured out. 
