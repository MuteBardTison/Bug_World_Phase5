#include <iostream>
#include <exception>

#include "World.h"
#include "Cell.h"
#include "Bug.h"
#include "Marker.h"
#include "auxbug.h"
#include "adjacent_cell.h"
#include "gtest/gtest.h"
#include "Program.h"
#include "Instruction.h"

const std::string FILE_NAME = "map.txt";

TEST(Buggy, ProgramTest){Program program;}
TEST(Buggy, WorldTest){World world;}
TEST(Buggy, InstructionTest){}
TEST(Buggy, CellTest){
    Cell obstruct = Cell('#');
    Cell black_home = Cell('-');
    Cell red_home = Cell('+');
    EXPECT_TRUE(obstruct.get_obstructed());
    EXPECT_TRUE(black_home.is_black_home_area());
    EXPECT_TRUE(red_home.is_red_home_area());

    Bug bug;
    Bug* bugptr = &bug;
    Cell cell = Cell('-');
    EXPECT_THROW(cell.get_occupant(), std::invalid_argument);
    cell.set_occupant(bugptr);
    EXPECT_EQ(cell.get_occupant(), bugptr);    

    Cell cell2 = Cell('9');
    EXPECT_EQ(cell2.get_food(), 9);
    cell2 = Cell('.');
    EXPECT_EQ(cell2.get_food(), 0);
    cell2.set_food(105);
    EXPECT_EQ(cell2.get_food(), 105);
    EXPECT_THROW(cell2.set_food(-102), std::invalid_argument);
}

TEST(Buggy, BugTest){
    Bug nbug = Bug();
    EXPECT_EQ(nbug.get_prog_id(),999);
    EXPECT_EQ(nbug.get_resting(), 0);
    EXPECT_FALSE(nbug.is_dead());
    EXPECT_FALSE(nbug.get_has_food());

    Bug nbug2 = Bug();
    nbug2.set_state(5);
    EXPECT_EQ(nbug2.get_state(),5);

    Bug nbug3 = Bug();
    nbug3.set_direction(5);
    EXPECT_EQ(nbug3.get_direction(),5);

    Bug nbug4 = Bug();
    EXPECT_THROW(nbug4.set_has_food(true), std::invalid_argument);
    EXPECT_FALSE(nbug4.get_has_food());

    Bug nbug5= Bug();
    EXPECT_THROW(nbug5.set_color(2), std::invalid_argument);
    nbug5.set_color(1);
    EXPECT_EQ(nbug5.get_color().c, 1);

    Bug nbug6= Bug();
    nbug6.set_position(1,1);
    auxbug::tposition n = nbug6.get_position();
    EXPECT_EQ(1,n.x);
    EXPECT_EQ(1,n.y);

    Bug nbug7= Bug();
    EXPECT_FALSE(nbug7.is_dead());
    nbug7.kill();
    EXPECT_TRUE(nbug7.is_dead());
    EXPECT_THROW(nbug7.kill(), std::invalid_argument);
}

TEST(Buggy, MarkerTest){
    Marker marker;
    auxbug::tmark mark= auxbug::tmark(0);
    auxbug::tcolor color= auxbug::tcolor(0);
    marker.set_marker(mark, color);
    EXPECT_EQ(marker.check_marker(mark,color), 1);

    Marker marker2;
    auxbug::tcolor color2= auxbug::tcolor(1);
    EXPECT_EQ(marker2.check_other_marker(color2),0);

}

TEST(Buggy, AuxbugTest){
    auxbug::tcolor tc;
    EXPECT_EQ(tc.c,0);
    EXPECT_THROW(auxbug::tcolor(3),std::invalid_argument);
    auxbug::tdirection td;
    EXPECT_EQ(td.d,0);
    EXPECT_THROW(auxbug::tdirection(6),std::invalid_argument);
    auxbug::tsensedir ts("ahead");
    EXPECT_EQ(ts.s,1);
    EXPECT_THROW(auxbug::tsensedir(4),std::invalid_argument);
    auxbug::tleftright lr("left");
    EXPECT_EQ(lr.l,0);
    EXPECT_THROW(auxbug::tleftright(3),std::invalid_argument);
    auxbug::tmark tm;
    EXPECT_EQ(tm.m,0);
    EXPECT_THROW(auxbug::tmark(6),std::invalid_argument);
    auxbug::tstate st;
    EXPECT_EQ(st.st,0);
    EXPECT_THROW(auxbug::tstate(-1),std::invalid_argument);
    auxbug::tcondition cd("friend");
    EXPECT_EQ(cd.cond,0);
    EXPECT_THROW(auxbug::tcondition("sky"),std::invalid_argument);
    auxbug::tposition tp;
    EXPECT_EQ(tp.x,0);
    EXPECT_EQ(tp.y,0);
}

TEST(Buggy, AdjacentCellTest){
    int x, y;
    int *a = &x;
    int *b = &y;
    adjacentCell(0,0,0,a,b);
    EXPECT_EQ(*a,1);
    EXPECT_EQ(*b,0);
    EXPECT_THROW(adjacentCell(0,0,-1,a,b),std::invalid_argument);
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}