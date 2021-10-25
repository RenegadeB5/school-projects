#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

// prototypes
void printTrack(int track[5]);
void won(int track[5]);

int main() {
	// put track array inside of main function, and will just pass it to all functions called
	int track[5] = {0,0,0,0,0};
	// use this to stop the loop
	bool run = true;
	// holds the seed we will turn into an int
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
	// main body of race
	while (run) {
		// Ill explain why I did it this way lower down where I use this variable
		bool win = false;
		for (int i = 0; i < 5; i++) {
			// variable to hold random number between 1 and 2
			int coin = rand() % 2; // 0 or 1
			// add coin to track, can get away with this since coin will only ever be 0 or 1
			track[i] = track[i] + coin;
			//check if someone won
			if (track[i] == 15) {
				// ends main loop
				run = false;
				// set win to true
				win = true;
			} // end if (track)
		} // end for (i)
		printTrack(track); // print track and put a space between each "round"
                std::cout << "\n" << std::endl;
		// put this outside of for loop so that a tie can be detected and registered, though unlikely
		if (win) {
			// call winning function
			won(track);
		} // end if (win)
	} // end while (run)
	return(0);
} // end main()

void printTrack(int track[5]) {
	// to print all tracks
	for (int i = 0; i < 5; i++) {
		// doing this to make sure output matches example shown
		if (track[i] == 15) {
			std::cout << "...............*" << std::endl;
		}
		else {
			// grab distance from current track
			int d = track[i];
			// empty track
			std::string t = "..............";
			// turn i+1 into a string so I can use it to identify each horse
			std::stringstream s;
			s << i+1;
			t.insert(d, s.str());
			// prints track with the horse number inserted at the distance
			std::cout << t << std::endl;
		} // end if track
	} // end for (i)
} // end printTrack()

void won(int track[5]) {
	// checks for winners and prints them, I have it iterate so it can print however many winners there are
	for (int i = 0; i < 5; i++) {
		if (track[i] == 15) {
			std::cout << "Horse " << i+1 << " wins!" << std::endl;
		} // end if (track)
	} // end for (i)
} // end won()

