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
include CMakeFiles/manacher.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/manacher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/manacher.dir/flags.make

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o: CMakeFiles/manacher.dir/flags.make
CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o: ../Algorithm\ Templates/Manacher's\ Algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o" -c "/home/shamiul93/Documents/Problem Solving Online Judges/Algorithm Templates/Manacher's Algorithm.cpp"

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/Algorithm Templates/Manacher's Algorithm.cpp" > "CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.i"

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/Algorithm Templates/Manacher's Algorithm.cpp" -o "CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.s"

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.requires:

.PHONY : CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.requires

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.provides: CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/manacher.dir/build.make "CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.provides.build"
.PHONY : CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.provides

CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.provides.build: CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o


# Object files for target manacher
manacher_OBJECTS = \
"CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o"

# External object files for target manacher
manacher_EXTERNAL_OBJECTS =

manacher: CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o
manacher: CMakeFiles/manacher.dir/build.make
manacher: CMakeFiles/manacher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable manacher"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/manacher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/manacher.dir/build: manacher

.PHONY : CMakeFiles/manacher.dir/build

CMakeFiles/manacher.dir/requires: CMakeFiles/manacher.dir/Algorithm_Templates/Manacher's_Algorithm.cpp.o.requires

.PHONY : CMakeFiles/manacher.dir/requires

CMakeFiles/manacher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/manacher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/manacher.dir/clean

CMakeFiles/manacher.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/manacher.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/manacher.dir/depend
