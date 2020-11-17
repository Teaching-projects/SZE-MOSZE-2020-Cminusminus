OBJS := character.o characterMaker.o JSONParser.o main.o player.o
CGFLAGS := -Wall
CC := g++
FOLDER := ./units

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

	for file1 in `ls $(FOLDER)`
	do
		for file2 in `ls $(FOLDER)`
		do
			if [[ $file1 != $file2 ]]
			then
				./$1 $(FOLDER)/$file1 $(FOLDER)/$file2 >> $2
			fi
		done
	done

battle_diff:
	diff program_outputs.txt good_outputs.txt

parser_testing:
	d /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./unit-test

documentation:
	doxygen doxconf