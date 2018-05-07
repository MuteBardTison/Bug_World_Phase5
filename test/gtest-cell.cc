#include <iostream>
#include <exception>

#include "Cell.h"
#include "Bug.h"

#include "gtest/gtest.h"

TEST(CellTest, StaticGetters){
    Cell obstruct = Cell('#');
    Cell black_home = Cell('-');
    Cell red_home = Cell('+');
    EXPECT_TRUE(obstruct.get_obstructed());
    EXPECT_TRUE(black_home.is_black_home_area());
    EXPECT_TRUE(red_home.is_red_home_area());
}
/*
TEST(CellTest, OccupantGetters){
    Bug occupant = Bug();
    Cell cell = Cell('.');
    try{
        cell.get_occupant();
    }
    catch(std::exception e){
        EXPECT_STREQ(e.what(), "Occupant hasn't been set yet");
    }
    cell.set_occupant(&occupant);
    Bug* occupantReceived = cell.get_occupant();
    EXPECT_TRUE(occupantReceived == &occupant);
}
*/
TEST(CellTest, FoodGetters){
    Cell cell = Cell('9');
    EXPECT_EQ(cell.get_food(), 9);
    cell = Cell('.');
    EXPECT_EQ(cell.get_food(), 0);
    cell.set_food(105);
    EXPECT_EQ(cell.get_food(), 105);
    EXPECT_THROW(cell.set_food(-102), std::invalid_argument);
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}