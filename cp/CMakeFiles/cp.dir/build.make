# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fisben/OS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fisben/OS

# Include any dependencies generated for this target.
include cp/CMakeFiles/cp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cp/CMakeFiles/cp.dir/compiler_depend.make

# Include the progress variables for this target.
include cp/CMakeFiles/cp.dir/progress.make

# Include the compile flags for this target's objects.
include cp/CMakeFiles/cp.dir/flags.make

cp/CMakeFiles/cp.dir/main.cpp.o: cp/CMakeFiles/cp.dir/flags.make
cp/CMakeFiles/cp.dir/main.cpp.o: cp/main.cpp
cp/CMakeFiles/cp.dir/main.cpp.o: cp/CMakeFiles/cp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fisben/OS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cp/CMakeFiles/cp.dir/main.cpp.o"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cp/CMakeFiles/cp.dir/main.cpp.o -MF CMakeFiles/cp.dir/main.cpp.o.d -o CMakeFiles/cp.dir/main.cpp.o -c /home/fisben/OS/cp/main.cpp

cp/CMakeFiles/cp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cp.dir/main.cpp.i"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fisben/OS/cp/main.cpp > CMakeFiles/cp.dir/main.cpp.i

cp/CMakeFiles/cp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cp.dir/main.cpp.s"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fisben/OS/cp/main.cpp -o CMakeFiles/cp.dir/main.cpp.s

cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o: cp/CMakeFiles/cp.dir/flags.make
cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o: cp/src/ListAllocator.cpp
cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o: cp/CMakeFiles/cp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fisben/OS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o -MF CMakeFiles/cp.dir/src/ListAllocator.cpp.o.d -o CMakeFiles/cp.dir/src/ListAllocator.cpp.o -c /home/fisben/OS/cp/src/ListAllocator.cpp

cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cp.dir/src/ListAllocator.cpp.i"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fisben/OS/cp/src/ListAllocator.cpp > CMakeFiles/cp.dir/src/ListAllocator.cpp.i

cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cp.dir/src/ListAllocator.cpp.s"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fisben/OS/cp/src/ListAllocator.cpp -o CMakeFiles/cp.dir/src/ListAllocator.cpp.s

cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o: cp/CMakeFiles/cp.dir/flags.make
cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o: cp/src/N2Allocator.cpp
cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o: cp/CMakeFiles/cp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fisben/OS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o -MF CMakeFiles/cp.dir/src/N2Allocator.cpp.o.d -o CMakeFiles/cp.dir/src/N2Allocator.cpp.o -c /home/fisben/OS/cp/src/N2Allocator.cpp

cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cp.dir/src/N2Allocator.cpp.i"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fisben/OS/cp/src/N2Allocator.cpp > CMakeFiles/cp.dir/src/N2Allocator.cpp.i

cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cp.dir/src/N2Allocator.cpp.s"
	cd /home/fisben/OS/cp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fisben/OS/cp/src/N2Allocator.cpp -o CMakeFiles/cp.dir/src/N2Allocator.cpp.s

# Object files for target cp
cp_OBJECTS = \
"CMakeFiles/cp.dir/main.cpp.o" \
"CMakeFiles/cp.dir/src/ListAllocator.cpp.o" \
"CMakeFiles/cp.dir/src/N2Allocator.cpp.o"

# External object files for target cp
cp_EXTERNAL_OBJECTS =

cp/cp: cp/CMakeFiles/cp.dir/main.cpp.o
cp/cp: cp/CMakeFiles/cp.dir/src/ListAllocator.cpp.o
cp/cp: cp/CMakeFiles/cp.dir/src/N2Allocator.cpp.o
cp/cp: cp/CMakeFiles/cp.dir/build.make
cp/cp: cp/CMakeFiles/cp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fisben/OS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cp"
	cd /home/fisben/OS/cp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cp/CMakeFiles/cp.dir/build: cp/cp
.PHONY : cp/CMakeFiles/cp.dir/build

cp/CMakeFiles/cp.dir/clean:
	cd /home/fisben/OS/cp && $(CMAKE_COMMAND) -P CMakeFiles/cp.dir/cmake_clean.cmake
.PHONY : cp/CMakeFiles/cp.dir/clean

cp/CMakeFiles/cp.dir/depend:
	cd /home/fisben/OS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fisben/OS /home/fisben/OS/cp /home/fisben/OS /home/fisben/OS/cp /home/fisben/OS/cp/CMakeFiles/cp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cp/CMakeFiles/cp.dir/depend
