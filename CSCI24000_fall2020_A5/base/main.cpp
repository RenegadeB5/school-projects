#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
	bool run = true;
	// prepare stream of input.txt and output.txt
	std::ifstream in;
	in.open("input.txt");
	std::ofstream out;
	out.open("output.txt");
	// keep going until end of file
	while (run) {
		// variables to the sum and 2 lines of input.txt
		std::string numbers;
		std::string word;
		int count = 0;
		// grab lines
		getline(in, numbers);
		getline(in, word);
		// if end of file, close both files and set run to false
		if (in.eof()) {
			in.close();
			out.close();
			run = false;
		} // end if
		else {
			// split numbers by ","
			std::stringstream ss(numbers);
			while (ss.good()) {
				std::string number;
				int i;
				getline(ss, number, ',');
				// convert num to int
				std::stringstream num(number);
				num >> i;
				// add to count
				count += i;
			} // end while
			// append to output.txt
			for (int i = 0; i < count; i++) {
				// doing this to remove comma at end
				if (i == count-1) {
					out << word;
				} // end if
				else {
					out << word << ", ";
				} // end else
			} // end for
			// end line
			out << std::endl;
		} // end else
	} // end while
	return(0);
} // end main()
