#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

void contents();

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
			run = false;
			in.close();
			out.close();
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
				// defence against decimals
				num.precision(1);
				num >> i;
				// defence against negative numbers
				i = std::abs(i);
				// defence against empty
				if (!word.length()) {
					i = 0;
				} // end if
				// defence against big numbers
				if (i > 10) {
					i = 10;
				} // end if
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
	contents();
	return(0);
} // end main()

void contents() {
	// set run to true
	bool run = true;
	// open input and output files
	std::ifstream in;
	in.open("input.txt");
	std::ifstream out;
	out.open("output.txt");
	// so we know what is what
	std::cout << "---------------- contents of input.txt ----------------" << std::endl << std::endl;
	// iterate through lines of input
	while (run) {
		// if end of file
		if (in.eof()) {
			in.close();
			run = false;
		} // end if
		else {
			// grab line and print
			std::string output;
			getline(in, output);
			std::cout << output << std::endl;
		} // end else
	} // end while
	run = true;
	std::cout << std::endl << "---------------- contents of output.txt ----------------" << std::endl << std::endl;
        while (run) {
		// if end of file
		if (out.eof()) {
			out.close();
			run = false;
		} // end if
		else {
			// grab line and print
			std::string output;
        	        getline(out, output);
                	std::cout << output << std::endl;
		} // end else
        } // end while
} // end contents









