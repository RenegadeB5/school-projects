main: main.o horse.o race.o
	g++ main.o horse.o race.o -o main

horse.o: horse.cpp horse.h
	g++ -c horse.cpp

race.o: race.cpp race.h horse.h
	g++ -c race.cpp

main.o: main.cpp horse.h race.h
	g++ -c main.cpp

clean:
	rm -f *.o
	rm main

run:
	./main

