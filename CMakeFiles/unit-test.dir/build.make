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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus

# Include any dependencies generated for this target.
include CMakeFiles/unit-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit-test.dir/flags.make

CMakeFiles/unit-test.dir/main_test.cpp.o: CMakeFiles/unit-test.dir/flags.make
CMakeFiles/unit-test.dir/main_test.cpp.o: main_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit-test.dir/main_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit-test.dir/main_test.cpp.o -c /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/main_test.cpp

CMakeFiles/unit-test.dir/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit-test.dir/main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/main_test.cpp > CMakeFiles/unit-test.dir/main_test.cpp.i

CMakeFiles/unit-test.dir/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit-test.dir/main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/main_test.cpp -o CMakeFiles/unit-test.dir/main_test.cpp.s

CMakeFiles/unit-test.dir/main_test.cpp.o.requires:

.PHONY : CMakeFiles/unit-test.dir/main_test.cpp.o.requires

CMakeFiles/unit-test.dir/main_test.cpp.o.provides: CMakeFiles/unit-test.dir/main_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit-test.dir/build.make CMakeFiles/unit-test.dir/main_test.cpp.o.provides.build
.PHONY : CMakeFiles/unit-test.dir/main_test.cpp.o.provides

CMakeFiles/unit-test.dir/main_test.cpp.o.provides.build: CMakeFiles/unit-test.dir/main_test.cpp.o


# Object files for target unit-test
unit__test_OBJECTS = \
"CMakeFiles/unit-test.dir/main_test.cpp.o"

# External object files for target unit-test
unit__test_EXTERNAL_OBJECTS =

unit-test: CMakeFiles/unit-test.dir/main_test.cpp.o
unit-test: CMakeFiles/unit-test.dir/build.make
unit-test: libcodeToTest.a
unit-test: CMakeFiles/unit-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit-test.dir/build: unit-test

.PHONY : CMakeFiles/unit-test.dir/build

CMakeFiles/unit-test.dir/requires: CMakeFiles/unit-test.dir/main_test.cpp.o.requires

.PHONY : CMakeFiles/unit-test.dir/requires

CMakeFiles/unit-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit-test.dir/clean

CMakeFiles/unit-test.dir/depend:
	cd /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles/unit-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit-test.dir/depend

