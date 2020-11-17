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
	rm -rf *.o mosze_01 *.out ./docs 

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
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cmake ./CMakeLists.txt
	make && ./runTests

documentation:
	doxygen doxconf