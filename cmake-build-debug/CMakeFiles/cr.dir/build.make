# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/shamiul93/Documents/Softwares/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/shamiul93/Documents/Softwares/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/cr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cr.dir/flags.make

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o: CMakeFiles/cr.dir/flags.make
CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o: ../LightOJ/1307-Counting\ Triangles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1307-Counting Triangles.cpp"

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1307-Counting Triangles.cpp" > CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.i

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1307-Counting Triangles.cpp" -o CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.s

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.requires:

.PHONY : CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.requires

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.provides: CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.requires
	$(MAKE) -f CMakeFiles/cr.dir/build.make CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.provides.build
.PHONY : CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.provides

CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.provides.build: CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o


# Object files for target cr
cr_OBJECTS = \
"CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o"

# External object files for target cr
cr_EXTERNAL_OBJECTS =

cr: CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o
cr: CMakeFiles/cr.dir/build.make
cr: CMakeFiles/cr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cr.dir/build: cr

.PHONY : CMakeFiles/cr.dir/build

CMakeFiles/cr.dir/requires: CMakeFiles/cr.dir/LightOJ/1307-Counting_Triangles.cpp.o.requires

.PHONY : CMakeFiles/cr.dir/requires

CMakeFiles/cr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cr.dir/clean

CMakeFiles/cr.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/cr.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/cr.dir/depend

