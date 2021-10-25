#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS
#include "horse.h"

// prototype
class Race {
	private:
		Horse h[5];
		int length;
		int lb[5];
	public:
		Race();
		Race(int length);
		void printLane(int x);
		void win();
		void start();
		void menu();
}; // end class def

#endif
