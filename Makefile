OBJS := JSON.o Monster.o Hero.o Game.o Map.o MarkedMap.o PreparedGame.o Renderer.o main.o
CGFLAGS := -std=c++17 -Wall
CC := g++-9

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
	
MarkedMap.o: Map.h MarkedMap.h MarkedMap.cpp
	$(CC) $(CGFLAGS) -c MarkedMap.cpp
	
PreparedGame.o: PreparedGame.cpp PreparedGame.h MarkedMap.h Game.h
	$(CC) $(CGFLAGS) -c PreparedGame.cpp

main.o: main.cpp Monster.h Hero.h JSON.h Map.h Game.h PreparedGame.h MarkedMap.h
	$(CC) $(CGFLAGS) -c main.cpp

Renderer.o: Renderer.h Renderer.cpp Game.h
	$(CC) $(CGFLAGS) -c Renderer.cpp

clean:
	rm -rf *.o mosze_01 *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 cat input1.txt | ./mosze_01 game.json
battle:
	touch program_outputs.txt
	> program_outputs.txt
		cat input1.txt | ./mosze_01 game.json >> program_outputs.txt; \
	
battle_diff: battle
	diff program_outputs.txt good_outputs.txt

unit_test :
	cd /usr/src/gtest && cmake CMakeLists.txt && make
	ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cmake ./CMakeLists.txt
	make && ./unit-test
documentation:
	doxygen documentations/doxconf