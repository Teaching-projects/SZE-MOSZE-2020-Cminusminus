OBJS := JSON.o Monster.o Hero.o main.o 
CGFLAGS := -std=c++17 -Wall
CC := g++-9
FOLDER := units/scenario1.json units/scenario2.json

mosze_01: $(OBJS)
	$(CC) $(CGFLAGS) -o mosze_01 $(OBJS)

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CGFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h
	$(CC) $(CGFLAGS) -c Hero.cpp

JSON.o: JSON.cpp JSON.h Monster.h
	$(CC) $(CGFLAGS) -c JSON.cpp

main.o: main.cpp Monster.h Hero.h JSON.h
	$(CC) $(CGFLAGS) -c main.cpp

clean:
	rm -rf *.o mosze_01 *.out ./docs 

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt
	cppcheck *.cpp --enable=performance,style --output-file=cppcheck_performance.txt

check_memoryleak:
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 units/scenario1.json
	valgrind --leak-check=yes --error-exitcode=1 ./mosze_01 units/scenario2.json

battle:
	touch program_outputs.txt
	> program_outputs.txt

	for f1 in $(FOLDER); do \
		./mosze_01 $$f1 >> program_outputs.txt; \
	done
	
battle_diff: battle
	diff program_outputs.txt good_outputs.txt
unit:
documentation:
	doxygen doxconf