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
include CMakeFiles/Lucky.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lucky.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lucky.dir/flags.make

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o: CMakeFiles/Lucky.dir/flags.make
CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o: ../LightOJ/1276\ -\ Very\ Lucky\ Numbers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1276 - Very Lucky Numbers.cpp"

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1276 - Very Lucky Numbers.cpp" > CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.i

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/LightOJ/1276 - Very Lucky Numbers.cpp" -o CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.s

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.requires:

.PHONY : CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.requires

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.provides: CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lucky.dir/build.make CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.provides.build
.PHONY : CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.provides

CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.provides.build: CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o


# Object files for target Lucky
Lucky_OBJECTS = \
"CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o"

# External object files for target Lucky
Lucky_EXTERNAL_OBJECTS =

Lucky: CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o
Lucky: CMakeFiles/Lucky.dir/build.make
Lucky: CMakeFiles/Lucky.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lucky"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lucky.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lucky.dir/build: Lucky

.PHONY : CMakeFiles/Lucky.dir/build

CMakeFiles/Lucky.dir/requires: CMakeFiles/Lucky.dir/LightOJ/1276_-_Very_Lucky_Numbers.cpp.o.requires

.PHONY : CMakeFiles/Lucky.dir/requires

CMakeFiles/Lucky.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lucky.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lucky.dir/clean

CMakeFiles/Lucky.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/Lucky.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lucky.dir/depend

