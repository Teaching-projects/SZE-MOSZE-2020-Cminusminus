# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ricsi/egyetem/SZE-MOSZE-2020-Cminusminus/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named unit-test

# Build rule for target.
unit-test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 unit-test
.PHONY : unit-test

# fast build rule for target.
unit-test/fast:
	$(MAKE) -f CMakeFiles/unit-test.dir/build.make CMakeFiles/unit-test.dir/build
.PHONY : unit-test/fast

#=============================================================================
# Target rules for targets named codeToTest

# Build rule for target.
codeToTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 codeToTest
.PHONY : codeToTest

# fast build rule for target.
codeToTest/fast:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/build
.PHONY : codeToTest/fast

#=============================================================================
# Target rules for targets named mosze

# Build rule for target.
mosze: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 mosze
.PHONY : mosze

# fast build rule for target.
mosze/fast:
	$(MAKE) -f CMakeFiles/mosze.dir/build.make CMakeFiles/mosze.dir/build
.PHONY : mosze/fast

JSONParser.o: JSONParser.cpp.o

.PHONY : JSONParser.o

# target to build an object file
JSONParser.cpp.o:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/JSONParser.cpp.o
.PHONY : JSONParser.cpp.o

JSONParser.i: JSONParser.cpp.i

.PHONY : JSONParser.i

# target to preprocess a source file
JSONParser.cpp.i:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/JSONParser.cpp.i
.PHONY : JSONParser.cpp.i

JSONParser.s: JSONParser.cpp.s

.PHONY : JSONParser.s

# target to generate assembly for a file
JSONParser.cpp.s:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/JSONParser.cpp.s
.PHONY : JSONParser.cpp.s

character.o: character.cpp.o

.PHONY : character.o

# target to build an object file
character.cpp.o:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/character.cpp.o
.PHONY : character.cpp.o

character.i: character.cpp.i

.PHONY : character.i

# target to preprocess a source file
character.cpp.i:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/character.cpp.i
.PHONY : character.cpp.i

character.s: character.cpp.s

.PHONY : character.s

# target to generate assembly for a file
character.cpp.s:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/character.cpp.s
.PHONY : character.cpp.s

characterMaker.o: characterMaker.cpp.o

.PHONY : characterMaker.o

# target to build an object file
characterMaker.cpp.o:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/characterMaker.cpp.o
.PHONY : characterMaker.cpp.o

characterMaker.i: characterMaker.cpp.i

.PHONY : characterMaker.i

# target to preprocess a source file
characterMaker.cpp.i:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/characterMaker.cpp.i
.PHONY : characterMaker.cpp.i

characterMaker.s: characterMaker.cpp.s

.PHONY : characterMaker.s

# target to generate assembly for a file
characterMaker.cpp.s:
	$(MAKE) -f CMakeFiles/codeToTest.dir/build.make CMakeFiles/codeToTest.dir/characterMaker.cpp.s
.PHONY : characterMaker.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/mosze.dir/build.make CMakeFiles/mosze.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/mosze.dir/build.make CMakeFiles/mosze.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/mosze.dir/build.make CMakeFiles/mosze.dir/main.cpp.s
.PHONY : main.cpp.s

main_test.o: main_test.cpp.o

.PHONY : main_test.o

# target to build an object file
main_test.cpp.o:
	$(MAKE) -f CMakeFiles/unit-test.dir/build.make CMakeFiles/unit-test.dir/main_test.cpp.o
.PHONY : main_test.cpp.o

main_test.i: main_test.cpp.i

.PHONY : main_test.i

# target to preprocess a source file
main_test.cpp.i:
	$(MAKE) -f CMakeFiles/unit-test.dir/build.make CMakeFiles/unit-test.dir/main_test.cpp.i
.PHONY : main_test.cpp.i

main_test.s: main_test.cpp.s

.PHONY : main_test.s

# target to generate assembly for a file
main_test.cpp.s:
	$(MAKE) -f CMakeFiles/unit-test.dir/build.make CMakeFiles/unit-test.dir/main_test.cpp.s
.PHONY : main_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... unit-test"
	@echo "... codeToTest"
	@echo "... edit_cache"
	@echo "... mosze"
	@echo "... JSONParser.o"
	@echo "... JSONParser.i"
	@echo "... JSONParser.s"
	@echo "... character.o"
	@echo "... character.i"
	@echo "... character.s"
	@echo "... characterMaker.o"
	@echo "... characterMaker.i"
	@echo "... characterMaker.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... main_test.o"
	@echo "... main_test.i"
	@echo "... main_test.s"
.PHONY : help

OBJS := character.o characterMaker.o JSONParser.o main.o player.o
CGFLAGS := -Wall
CC := g++
FOLDER := units/test_unit_1.json units/test_unit_2.json units/test_unit_3.json

mosze_01: $(OBJS)
	$(CC) $(CGFLAGS) -o mosze_01 $(OBJS)

character.o: character.cpp character.h
	$(CC) $(CGFLAGS) -c character.cpp
	
characterMaker.o: characterMaker.cpp characterMaker.h character.h
	$(CC) $(CGFLAGS) -c characterMaker.cpp

JSONParser.o: JSONParser.cpp JSONParser.h character.h characterMaker.h
	$(CC) $(CGFLAGS) -c JSONParser.cpp

main.o: main.cpp character.h player.h JSONParser.h characterMaker.h
	$(CC) $(CGFLAGS) -c main.cpp

clean:
	rm -rf *.o mosze_01 ./docs

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 units/test_unit_1.json units/test_unit_2.json

battle:
	touch program_outputs.txt
	> program_outputs.txt

	for f1 in $(FOLDER); do \
		for f2 in $(FOLDER); do \
			if [ $$f1 != $$f2 ]; then \
				./mosze_01 $$f1 $$f2 >> program_outputs.txt; \
			fi; \
		done; \
	done

battle_diff: battle
	diff program_outputs.txt good_outputs.txt

unit_test:
	./unit-test

documentation:
	doxygen doxconf