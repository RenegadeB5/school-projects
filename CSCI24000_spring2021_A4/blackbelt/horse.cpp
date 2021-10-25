#include <cstdlib>
#include "horse.h"

// constructor
Horse::Horse() {
	Horse::position = 0;
} // end constructor

// advance
void Horse::advance() {
	// returns either 1 or 0, so just add it to position
	int coin = std::rand() % 2;
	this->position += coin;
} // end advance()

// I misread the instructions so that's why this even exists
void Horse::reset() {
	this->position = 0;
}

// getPosition
int Horse::getPosition() {
	return(this->position);
} // end getPosition()


