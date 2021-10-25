#include "race.h"
#include "horse.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>

// defualt constructor
Race::Race() : lb{0,0,0,0,0} {
	Horse h[5];
	Race::length = 14;
} // end constructor

// if one chooses to have the race be a specific length
Race::Race(int x) : lb{0,0,0,0,0} {
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
		std::cout << lane << ".*" << std::endl;
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
			this->lb[i] += 1;
		} // end if
		// reset position after we check the value
		this->h[i].reset();
		// give point to horse on leaderboard
	} // end for
	// call menu()
	this->menu();
} // end win()

// start race
void Race::start() {
	// seed the race here vs in main
	std::string seed = "";
        std::cout << "Please enter a random seed: " << std::endl;
        // gets user input
        getline(std::cin, seed);
        // turning string to int
        std::stringstream num(seed);
        int r = 0;
        num >> r;
        // seed the random generator
        std::srand(r);
        // start race
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

void Race::menu() {
	// get user input
	std::cout << "\nWhat would you like to do?\n(1) Simulate race\n(2) View leaderboard\n(3) Exit\nPlease choose a number: " << std::endl;
	std::string c = "";
	getline(std::cin, c);
	if (c == "1") {
		this->start();
	} // end if
	else if (c == "2") {
		// iterate through lb and print
		for (int i = 0; i < 5; i++) {
			std::cout << "Horse " << i+1 << ": " << Race::lb[i] << std::endl;
		} // end for
		this->menu();
	} // end elif
	else if (c == "3") {
		//exit
		std::exit;
	} // end elif
	else {
		std::cout << "Sorry, but that isn't an option." << std::endl;
		this->menu();
	} // end else
} // end menu()





