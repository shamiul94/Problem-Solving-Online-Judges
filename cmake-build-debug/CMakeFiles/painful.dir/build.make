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
CMAKE_COMMAND = "/media/shamiul93/Software and Media/Necessary Softwares/Softwares/clion-2018.1.5/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/media/shamiul93/Software and Media/Necessary Softwares/Softwares/clion-2018.1.5/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/painful.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/painful.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/painful.dir/flags.make

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o: CMakeFiles/painful.dir/flags.make
CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o: ../LightOJ/1021\ -\ Painful\ Bases.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1021 - Painful Bases.cpp"

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1021 - Painful Bases.cpp" > CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.i

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1021 - Painful Bases.cpp" -o CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.s

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.requires:

.PHONY : CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.requires

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.provides: CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.requires
	$(MAKE) -f CMakeFiles/painful.dir/build.make CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.provides.build
.PHONY : CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.provides

CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.provides.build: CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o


# Object files for target painful
painful_OBJECTS = \
"CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o"

# External object files for target painful
painful_EXTERNAL_OBJECTS =

painful: CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o
painful: CMakeFiles/painful.dir/build.make
painful: CMakeFiles/painful.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable painful"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/painful.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/painful.dir/build: painful

.PHONY : CMakeFiles/painful.dir/build

CMakeFiles/painful.dir/requires: CMakeFiles/painful.dir/LightOJ/1021_-_Painful_Bases.cpp.o.requires

.PHONY : CMakeFiles/painful.dir/requires

CMakeFiles/painful.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/painful.dir/cmake_clean.cmake
.PHONY : CMakeFiles/painful.dir/clean

CMakeFiles/painful.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/painful.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/painful.dir/depend
