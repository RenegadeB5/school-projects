main: main.o student.o date.o address.o
	g++ main.o student.o date.o address.o -o main

date.o: date.h date.cpp
	g++ -c date.cpp

address.o: address.h address.cpp
	g++ -c address.cpp

student.o: address.h date.h student.h student.cpp
	g++ -c student.cpp

main.o: student.h main.cpp
	g++ -c main.cpp
valgrind:
	valgrind ./main

clean:
	rm -f *.o
	rm main
	rm fullReport.txt
	rm shortReport.txt
	clear

run: 
	./main
