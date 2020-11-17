OBJS := character.o characterMaker.o JSONParser.o main.o player.o
CGFLAGS := -Wall
CC := g++
UNIT1 := units/test_unit_1.json
UNIT2 := units/test_unit_2.json
UNIT3 := units/test_unit_3.json

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
	rm -rf *.o *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 units/test_unit_1.json units/test_unit_2.json

battle:
	touch "program_outputs.txt"
	> program_outputs.txt
	./mosze_01 $(UNIT1) $(UNIT2) >> program_outputs.txt
	./mosze_01 $(UNIT1) $(UNIT3) >> program_outputs.txt
	./mosze_01 $(UNIT2) $(UNIT1) >> program_outputs.txt
	./mosze_01 $(UNIT2) $(UNIT3) >> program_outputs.txt
	./mosze_01 $(UNIT3) $(UNIT2) >> program_outputs.txt
	./mosze_01 $(UNIT3) $(UNIT1) >> program_outputs.txt

battle_diff: battle
	diff program_outputs.txt good_outputs.txt

unit_test:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cmake unit-testing/CMakeLists.txt
	xd unit-testing && make && ./runTests

documentation:
	doxygen doxconf