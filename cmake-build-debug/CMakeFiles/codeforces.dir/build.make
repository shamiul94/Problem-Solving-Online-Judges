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
CMAKE_COMMAND = "/media/shamiul93/Software-and-Media/Necessary Softwares/Linux Softwares/clion-2018.1.5/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/media/shamiul93/Software-and-Media/Necessary Softwares/Linux Softwares/clion-2018.1.5/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/codeforces.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codeforces.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codeforces.dir/flags.make

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o: CMakeFiles/codeforces.dir/flags.make
CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o: ../Codeforces/1266-E.\ Spaceship\ Solitaire.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/Codeforces/1266-E. Spaceship Solitaire.cpp"

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/Codeforces/1266-E. Spaceship Solitaire.cpp" > CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.i

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/Codeforces/1266-E. Spaceship Solitaire.cpp" -o CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.s

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.requires:

.PHONY : CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.requires

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.provides: CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.requires
	$(MAKE) -f CMakeFiles/codeforces.dir/build.make CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.provides.build
.PHONY : CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.provides

CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.provides.build: CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o


# Object files for target codeforces
codeforces_OBJECTS = \
"CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o"

# External object files for target codeforces
codeforces_EXTERNAL_OBJECTS =

codeforces: CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o
codeforces: CMakeFiles/codeforces.dir/build.make
codeforces: CMakeFiles/codeforces.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codeforces"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codeforces.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codeforces.dir/build: codeforces

.PHONY : CMakeFiles/codeforces.dir/build

CMakeFiles/codeforces.dir/requires: CMakeFiles/codeforces.dir/Codeforces/1266-E._Spaceship_Solitaire.cpp.o.requires

.PHONY : CMakeFiles/codeforces.dir/requires

CMakeFiles/codeforces.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codeforces.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codeforces.dir/clean

CMakeFiles/codeforces.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/codeforces.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/codeforces.dir/depend

