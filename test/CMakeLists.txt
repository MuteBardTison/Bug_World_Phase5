cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/src)

enable_testing()
find_package(GTest REQUIRED)

set(
    LIBS 
    adjacent_cell 
    auxbug 
    Bug 
    Cell 
    checkforbugs 
    I_direction 
    I_drop 
    I_flip
    I_mark
    I_move
    I_pickup
    I_sense
    I_turn
    I_unmark
    Instruction 
    Marker 
    Program
    tokenizer
    World
)

add_executable(gtest-cell gtest-cell.cc)
target_link_libraries(gtest-cell GTest::GTest GTest::Main ${LIBS})

add_test(Buggy gtest-cell)
