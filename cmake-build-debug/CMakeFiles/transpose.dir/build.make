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
include CMakeFiles/transpose.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/transpose.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/transpose.dir/flags.make

CMakeFiles/transpose.dir/Offline/Transposition.cpp.o: CMakeFiles/transpose.dir/flags.make
CMakeFiles/transpose.dir/Offline/Transposition.cpp.o: ../Offline/Transposition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/transpose.dir/Offline/Transposition.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/transpose.dir/Offline/Transposition.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/Offline/Transposition.cpp"

CMakeFiles/transpose.dir/Offline/Transposition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/transpose.dir/Offline/Transposition.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/Offline/Transposition.cpp" > CMakeFiles/transpose.dir/Offline/Transposition.cpp.i

CMakeFiles/transpose.dir/Offline/Transposition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/transpose.dir/Offline/Transposition.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/Offline/Transposition.cpp" -o CMakeFiles/transpose.dir/Offline/Transposition.cpp.s

CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.requires:

.PHONY : CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.requires

CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.provides: CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.requires
	$(MAKE) -f CMakeFiles/transpose.dir/build.make CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.provides.build
.PHONY : CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.provides

CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.provides.build: CMakeFiles/transpose.dir/Offline/Transposition.cpp.o


# Object files for target transpose
transpose_OBJECTS = \
"CMakeFiles/transpose.dir/Offline/Transposition.cpp.o"

# External object files for target transpose
transpose_EXTERNAL_OBJECTS =

transpose: CMakeFiles/transpose.dir/Offline/Transposition.cpp.o
transpose: CMakeFiles/transpose.dir/build.make
transpose: CMakeFiles/transpose.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable transpose"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/transpose.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/transpose.dir/build: transpose

.PHONY : CMakeFiles/transpose.dir/build

CMakeFiles/transpose.dir/requires: CMakeFiles/transpose.dir/Offline/Transposition.cpp.o.requires

.PHONY : CMakeFiles/transpose.dir/requires

CMakeFiles/transpose.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/transpose.dir/cmake_clean.cmake
.PHONY : CMakeFiles/transpose.dir/clean

CMakeFiles/transpose.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/transpose.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/transpose.dir/depend

