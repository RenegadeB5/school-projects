#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "student.h"

int main() {
	// initialize array
	Student *students = new Student[50];
	// set run to true
	bool run = true;
	// open students.dat
	std::ifstream in;
	in.open("students.dat");
	// iterator to build each student
	int count = 0;
	// while run is true
	while (run) {
		// define string to hold line
		std::string line;
		// get line from students.dat
		getline(in, line);
		// if end of file, close students.dat and set run to false to end loop
		if (in.eof()) {
			in.close();
			run = false;
		}
		else {
			// define strings to hold individual student data
			std::string firstName;
			std::string lastName;
			std::string address1;
			std::string address2;
			std::string city;
			std::string state;
			std::string zip;
			std::string DoB;
			std::string DoGrad;
			std::string s_gpa;
			std::string s_credHrs;
			std::stringstream ss(line);
			// grab data from line, stopping at each ",", and put in variable
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, address1, ',');
			getline(ss, address2, ',');
			getline(ss, city, ',');
			getline(ss, state, ',');
			getline(ss, zip, ',');
			getline(ss, DoB, ',');
			getline(ss, DoGrad, ',');
			getline(ss, s_gpa, ',');
			getline(ss, s_credHrs, ',');
			// convert gpa to double, and convert credit hours to int
			double gpa = atof(s_gpa.c_str());
			int credHrs;
			std::stringstream credIn(s_credHrs);
			credIn >> credHrs;
			// call build function with srting variables as parameters
			students[count].build(firstName, lastName, address1, address2, city, state, zip, DoB, DoGrad, gpa, credHrs);
			// increase count by 1
			count += 1;	
		} // end if
	} // end while
	// open 2 output files for full and short report
	std::ofstream fullOut;
	std::ofstream shortOut;
	fullOut.open("fullReport.txt");
	shortOut.open("shortReport.txt");
	// iterare through student array
	for (int i = 0; i < 50; i++) {
		// define string to hold output, doing it like this so it looks better
		std::string out = "";
		std::stringstream ss(out);
		// doing this to make changing separator easier
		std::string s = "|";
		// append student data to string
		ss << students[i].getFirstName() << s; 
		ss << students[i].getLastName() << s; 
		ss << students[i].getAddress1() << s; 
		ss << students[i].getAddress2() << s; 
		ss << students[i].getCity() << s; 
		ss << students[i].getState() << s; 
		ss << students[i].getZip() << s;
		ss << students[i].getDoB() << s;
		ss << students[i].getDoGrad() << s; 
		ss << students[i].getGPA() << s; 
		ss << students[i].getCredHrs() << std::endl;
		// write to fullReport
		fullOut << ss.str();
		// write last and first name to shortReport
		shortOut << students[i].getLastName() << ", " << students[i].getFirstName() << std::endl;
	} // end for
	// close both output files
	fullOut.close();
	shortOut.close();
	// delete heap array
	delete[] students;
	return(0);
} // end main()





























