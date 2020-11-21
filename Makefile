OBJS := JSON.o Monster.o Hero.o main.o 
CGFLAGS := -std=c++17 -Wall
CC := g++-9
SCENARIO1 := scenario1.json
SCENARIO2 := scenario2.json

mosze_01: -Wall $(OBJS)
	g++ -fPIC -std=c++17 -Wall -Wextra -o mosze_01 $(OBJS)

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CGFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h
	$(CC) $(CGFLAGS) -c Hero.cpp

JSON.o: JSON.cpp JSON.h Monster.h
	$(CC) $(CGFLAGS) -c JSON.cpp

main.o: main.cpp Monster.h Hero.h JSON.h
	$(CC) $(CGFLAGS) -c main.cpp

clean:
	rm -rf *.o *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 scenario1.json
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 scenario2.json
battle:
	touch program_outputs.txt
	> program_outputs.txt

		./mosze_01 $(SCENARIO1) >> program_outputs.txt; \
		./mosze_01 $(SCENARIO2) >> program_outputs.txt; \
	
battle_diff: battle
	diff program_outputs.txt good_outputs.txt
unit_test :
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cmake ./CMakeLists.txt
	make && ./unit-test
documentation:
	doxygen doxconf