OBJS := JSON.o Monster.o Hero.o Game.o Map.o main.o
CGFLAGS := -std=c++17 -Wall
CC := g++-9
SCENARIO1 := scenarios/scenario1.json
SCENARIO2 := scenarios/scenario2.json

mosze_01: $(OBJS)
	$(CC) $(CGFLAGS) -o mosze_01 $(OBJS)

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CGFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h
	$(CC) $(CGFLAGS) -c Hero.cpp

JSON.o: JSON.cpp JSON.h Monster.h
	$(CC) $(CGFLAGS) -c JSON.cpp
	
Map.o: Map.h Map.cpp
	$(CC) $(CGFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h Map.h Hero.h Monster.h
	$(CC) $(CGFLAGS) -c Game.cpp
	
main.o: main.cpp Monster.h Hero.h JSON.h Map.h Game.h
	$(CC) $(CGFLAGS) -c main.cpp

clean:
	rm -rf *.o mosze_01 *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 cat input1.txt | ./mosze_01 scenarios/scenario1.json
	valgrind --leak-check=yes --error-exitcode=1 cat input2.txt | ./mosze_01 scenarios/scenario2.json
battle:
	touch program_outputs.txt
	> program_outputs.txt
		cat input1.txt | ./mosze_01 $(SCENARIO1) >> program_outputs.txt; \
	touch program_outputs2.txt
	> program_outputs2.txt
		cat input2.txt | ./mosze_01 $(SCENARIO2) >> program_outputs2.txt; \
	
battle_diff: battle
	diff program_outputs.txt good_outputs.txt
	diff program_outputs2.txt good_outputs2.txt
unit_test :
	cd /usr/src/gtest && cmake CMakeLists.txt && make
	ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cmake ./CMakeLists.txt
	make && ./unit-test
documentation:
	doxygen documentations/doxconf