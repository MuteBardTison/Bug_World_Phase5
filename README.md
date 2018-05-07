# Bug World

**Software Engineering**
Jacobs University, Spring Semester 2018
Prof. Dr. Peter Baumann

## Contributors

### Phase 5

**Zihan Qi** z.qi@jacobs-university.de 

**Shen Huang** s.huang@jacobs-university.de

## Prerequisites

### Compilation

#### CMake

A CMakeLists.txt is available in the root folder, and compilation is done with CMake. CMake also needs to be installed in the system. Refer to stackexchange.com or google.com for instructions on how to install the framework.

### Framework Testing

#### Google Test

For unit testing, Google Test is the framework of choice. Google Test needs to be installed in the system. Refer to stackexchange.com or google.com for instructions on how to install the framework.

Installation on a Mac: http://hack.limbicmedia.ca/installing-google-test/

#### Running the Google Test

From the project root directory

```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd test
$ ./gtest
```
