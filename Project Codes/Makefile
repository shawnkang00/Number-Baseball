FLAG = -pedantic-errors -std=c++11

functions.o: functions.cpp functions.h
	g++ $(FLAG) -c functions.cpp

playgame.o: playgame.cpp playgame.h
	g++ $(FLAG) -c playgame.cpp

main.cpp: main.cpp playgame.h functions.h
	g++ $(FLAG) -c main.cpp

main: main.o playgame.o functions.o
	g++ $(FLAG) $^ -o $@

clean:
	rm -f main main.o playgame.o functions.o

.PHONY: clean