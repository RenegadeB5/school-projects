#include "race.h"
#include "horse.h"
#include <sstream>
#include <string>
#include <iostream>

// defualt constructor
Race::Race() {
	Horse h[5];
	Race::length = 14;
} // end constructor

// if one chooses to have the race be a specific length
Race::Race(int x) {
	Horse h[5];
	Race::length = x;
} // end constrcutor

void Race::printLane(int x) {
	// fetch position
	int d = this->h[x].getPosition();
	// create empty track using length
	std::string lane(this->length, '.');
	// doing this to make sure output matches example
	if (d == this->length) {
		std::cout << lane << "." << std::endl;
	} // end if length
	else {
		// turn horse num into int and insert into track
		std::stringstream s;
		s << x+1;
		lane.insert(d, s.str());
		std::cout << lane << std::endl;
	} // end else
} // end printLane()

void Race::win() {
	// iterate through tracks
	for (int i = 0; i < 5; i++) {
		// if position matches track length, horse is announced
		if (this->h[i].getPosition() == this->length) {
			// print
			std::cout << "Horse " << i+1 << " wins!" << std::endl;
		} // end if
		// reset position after we check the value
		this->h[i].reset();
	} // end for
} // end win()

// start race
void Race::start() {
	// set true
	bool run = true;
	while (run) {
		// do this to detect ties
		bool win = false;
		// iterate through horses
		for (int i = 0; i < 5; i++) {
			// advance
			this->h[i].advance();
			// print the track
			this->printLane(i);
			// detect win
			if (this->h[i].getPosition() == this->length) {
				// detect win and end loop
				win = true;
				run = false;
			} // end if
		} // end for
		// separate tracks
		std::cout << "\n" << std::endl;
		if (win) {
			// call win function
			this->win();
		} // end if
	} // end while
} // end start()
