cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_STANDARD 11)

project(Bug_World)

add_subdirectory(src)

file(GLOB buggy
	"./src/assembler/bug.buggy"
)

file(COPY ${buggy} DESTINATION "./src/assembler")

enable_testing()
