# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/elk/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/elk/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elk/CLionProjects/polymorphism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elk/CLionProjects/polymorphism/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/polymorphism.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/polymorphism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/polymorphism.dir/flags.make

CMakeFiles/polymorphism.dir/solidtest.cpp.o: CMakeFiles/polymorphism.dir/flags.make
CMakeFiles/polymorphism.dir/solidtest.cpp.o: ../solidtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elk/CLionProjects/polymorphism/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/polymorphism.dir/solidtest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polymorphism.dir/solidtest.cpp.o -c /home/elk/CLionProjects/polymorphism/solidtest.cpp

CMakeFiles/polymorphism.dir/solidtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polymorphism.dir/solidtest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elk/CLionProjects/polymorphism/solidtest.cpp > CMakeFiles/polymorphism.dir/solidtest.cpp.i

CMakeFiles/polymorphism.dir/solidtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polymorphism.dir/solidtest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elk/CLionProjects/polymorphism/solidtest.cpp -o CMakeFiles/polymorphism.dir/solidtest.cpp.s

# Object files for target polymorphism
polymorphism_OBJECTS = \
"CMakeFiles/polymorphism.dir/solidtest.cpp.o"

# External object files for target polymorphism
polymorphism_EXTERNAL_OBJECTS =

polymorphism: CMakeFiles/polymorphism.dir/solidtest.cpp.o
polymorphism: CMakeFiles/polymorphism.dir/build.make
polymorphism: CMakeFiles/polymorphism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elk/CLionProjects/polymorphism/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable polymorphism"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/polymorphism.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/polymorphism.dir/build: polymorphism

.PHONY : CMakeFiles/polymorphism.dir/build

CMakeFiles/polymorphism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/polymorphism.dir/cmake_clean.cmake
.PHONY : CMakeFiles/polymorphism.dir/clean

CMakeFiles/polymorphism.dir/depend:
	cd /home/elk/CLionProjects/polymorphism/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elk/CLionProjects/polymorphism /home/elk/CLionProjects/polymorphism /home/elk/CLionProjects/polymorphism/cmake-build-debug /home/elk/CLionProjects/polymorphism/cmake-build-debug /home/elk/CLionProjects/polymorphism/cmake-build-debug/CMakeFiles/polymorphism.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/polymorphism.dir/depend

