# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Tison/Documents/GitHub/Bug_World_Phase5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Tison/Documents/GitHub/Bug_World_Phase5/build

# Include any dependencies generated for this target.
include src/CMakeFiles/auxbug.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/auxbug.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/auxbug.dir/flags.make

src/CMakeFiles/auxbug.dir/auxbug.cc.o: src/CMakeFiles/auxbug.dir/flags.make
src/CMakeFiles/auxbug.dir/auxbug.cc.o: ../src/auxbug.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Tison/Documents/GitHub/Bug_World_Phase5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/auxbug.dir/auxbug.cc.o"
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/auxbug.dir/auxbug.cc.o -c /Users/Tison/Documents/GitHub/Bug_World_Phase5/src/auxbug.cc

src/CMakeFiles/auxbug.dir/auxbug.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/auxbug.dir/auxbug.cc.i"
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Tison/Documents/GitHub/Bug_World_Phase5/src/auxbug.cc > CMakeFiles/auxbug.dir/auxbug.cc.i

src/CMakeFiles/auxbug.dir/auxbug.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/auxbug.dir/auxbug.cc.s"
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Tison/Documents/GitHub/Bug_World_Phase5/src/auxbug.cc -o CMakeFiles/auxbug.dir/auxbug.cc.s

src/CMakeFiles/auxbug.dir/auxbug.cc.o.requires:

.PHONY : src/CMakeFiles/auxbug.dir/auxbug.cc.o.requires

src/CMakeFiles/auxbug.dir/auxbug.cc.o.provides: src/CMakeFiles/auxbug.dir/auxbug.cc.o.requires
	$(MAKE) -f src/CMakeFiles/auxbug.dir/build.make src/CMakeFiles/auxbug.dir/auxbug.cc.o.provides.build
.PHONY : src/CMakeFiles/auxbug.dir/auxbug.cc.o.provides

src/CMakeFiles/auxbug.dir/auxbug.cc.o.provides.build: src/CMakeFiles/auxbug.dir/auxbug.cc.o


# Object files for target auxbug
auxbug_OBJECTS = \
"CMakeFiles/auxbug.dir/auxbug.cc.o"

# External object files for target auxbug
auxbug_EXTERNAL_OBJECTS =

src/libauxbug.a: src/CMakeFiles/auxbug.dir/auxbug.cc.o
src/libauxbug.a: src/CMakeFiles/auxbug.dir/build.make
src/libauxbug.a: src/CMakeFiles/auxbug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Tison/Documents/GitHub/Bug_World_Phase5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libauxbug.a"
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && $(CMAKE_COMMAND) -P CMakeFiles/auxbug.dir/cmake_clean_target.cmake
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/auxbug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/auxbug.dir/build: src/libauxbug.a

.PHONY : src/CMakeFiles/auxbug.dir/build

src/CMakeFiles/auxbug.dir/requires: src/CMakeFiles/auxbug.dir/auxbug.cc.o.requires

.PHONY : src/CMakeFiles/auxbug.dir/requires

src/CMakeFiles/auxbug.dir/clean:
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src && $(CMAKE_COMMAND) -P CMakeFiles/auxbug.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/auxbug.dir/clean

src/CMakeFiles/auxbug.dir/depend:
	cd /Users/Tison/Documents/GitHub/Bug_World_Phase5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Tison/Documents/GitHub/Bug_World_Phase5 /Users/Tison/Documents/GitHub/Bug_World_Phase5/src /Users/Tison/Documents/GitHub/Bug_World_Phase5/build /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src /Users/Tison/Documents/GitHub/Bug_World_Phase5/build/src/CMakeFiles/auxbug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/auxbug.dir/depend

