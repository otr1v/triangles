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
CMAKE_SOURCE_DIR = /home/vanya/triangles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vanya/triangles

# Include any dependencies generated for this target.
include CMakeFiles/triangle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/triangle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/triangle.dir/flags.make

CMakeFiles/triangle.dir/main.cpp.o: CMakeFiles/triangle.dir/flags.make
CMakeFiles/triangle.dir/main.cpp.o: main.cpp
CMakeFiles/triangle.dir/main.cpp.o: CMakeFiles/triangle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vanya/triangles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/triangle.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/triangle.dir/main.cpp.o -MF CMakeFiles/triangle.dir/main.cpp.o.d -o CMakeFiles/triangle.dir/main.cpp.o -c /home/vanya/triangles/main.cpp

CMakeFiles/triangle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/triangle.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vanya/triangles/main.cpp > CMakeFiles/triangle.dir/main.cpp.i

CMakeFiles/triangle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/triangle.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vanya/triangles/main.cpp -o CMakeFiles/triangle.dir/main.cpp.s

# Object files for target triangle
triangle_OBJECTS = \
"CMakeFiles/triangle.dir/main.cpp.o"

# External object files for target triangle
triangle_EXTERNAL_OBJECTS =

triangle: CMakeFiles/triangle.dir/main.cpp.o
triangle: CMakeFiles/triangle.dir/build.make
triangle: CMakeFiles/triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vanya/triangles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/triangle.dir/build: triangle
.PHONY : CMakeFiles/triangle.dir/build

CMakeFiles/triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/triangle.dir/clean

CMakeFiles/triangle.dir/depend:
	cd /home/vanya/triangles && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vanya/triangles /home/vanya/triangles /home/vanya/triangles /home/vanya/triangles /home/vanya/triangles/CMakeFiles/triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/triangle.dir/depend

