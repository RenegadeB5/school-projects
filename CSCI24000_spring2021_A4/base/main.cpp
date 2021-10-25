#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "horse.h"
#include "race.h"

int main() {
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
	Race c;
	c.start();
} // end main


