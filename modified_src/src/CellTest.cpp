

#include <stdlib.h>
#include "Cell.h"
#include "bug.h"
#include "gtest/gtest/gtest.h"
using namespace std;
/*
 * Simple C++ Test Suite
 */

TEST(CellTest, StaticGetters){
    Cell obstruct = Cell('#');
    Cell black_home = Cell('-');
    Cell red_home = Cell('+');
    EXPECT_TRUE(obstruct.get_obstructed());
    EXPECT_TRUE(black_home.is_black_home_area());
    EXPECT_TRUE(red_home.is_red_home_area());
}

TEST(CellTest, OccupantGetters){
    Bug occupant = Bug();
    Cell cell = Cell('.');
    try{
        cell.get_occupant();
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Occupant hasn't been set yet");
    }
    cell.set_occupant(occupant);
    Bug occupantReceived = cell.get_occupant();
    EXPECT_TRUE(occupantReceived == occupant);
}

TEST(CellTest, FoodGetters){
    Cell cell = Cell('9');
    EXPECT_EQ(cell.get_food(), 9);
    cell = Cell('.');
    EXPECT_EQ(cell.get_food(), 0);
    cell.set_food(105);
    EXPECT_EQ(cell.get_food(), 105);
    try{
        cell.set_food(-102);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Food can't be negative valued");
    }
}

