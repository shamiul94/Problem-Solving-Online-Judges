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
include CMakeFiles/tsttrr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsttrr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsttrr.dir/flags.make

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o: CMakeFiles/tsttrr.dir/flags.make
CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o: ../Testing/testin2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o -c "/home/shamiul93/Documents/Problem Solving Online Judges/Testing/testin2.cpp"

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsttrr.dir/Testing/testin2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shamiul93/Documents/Problem Solving Online Judges/Testing/testin2.cpp" > CMakeFiles/tsttrr.dir/Testing/testin2.cpp.i

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsttrr.dir/Testing/testin2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shamiul93/Documents/Problem Solving Online Judges/Testing/testin2.cpp" -o CMakeFiles/tsttrr.dir/Testing/testin2.cpp.s

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.requires:

.PHONY : CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.requires

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.provides: CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.requires
	$(MAKE) -f CMakeFiles/tsttrr.dir/build.make CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.provides.build
.PHONY : CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.provides

CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.provides.build: CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o


# Object files for target tsttrr
tsttrr_OBJECTS = \
"CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o"

# External object files for target tsttrr
tsttrr_EXTERNAL_OBJECTS =

tsttrr: CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o
tsttrr: CMakeFiles/tsttrr.dir/build.make
tsttrr: CMakeFiles/tsttrr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsttrr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tsttrr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsttrr.dir/build: tsttrr

.PHONY : CMakeFiles/tsttrr.dir/build

CMakeFiles/tsttrr.dir/requires: CMakeFiles/tsttrr.dir/Testing/testin2.cpp.o.requires

.PHONY : CMakeFiles/tsttrr.dir/requires

CMakeFiles/tsttrr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tsttrr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tsttrr.dir/clean

CMakeFiles/tsttrr.dir/depend:
	cd "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug" "/home/shamiul93/Documents/Problem Solving Online Judges/cmake-build-debug/CMakeFiles/tsttrr.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tsttrr.dir/depend
