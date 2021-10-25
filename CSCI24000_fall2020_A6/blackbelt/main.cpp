#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "student.h"

// for viewing the reports easily
void viewReports();

int main() {
	// saying this for ease of use
	std::cout << "running program..." << std::endl;
	// initialize array
	Student** students = new Student*[50];
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
			// initialize with line as parameter
			students[count] = new Student(line);	
			// increase count by 1
			count += 1;	
		} // end if
	} // end while
	// open 2 output files for full and short report
	std::ofstream fullOut;
	std::ofstream shortOut;
	std::ofstream alphaOut;
	fullOut.open("fullReport.txt");
	shortOut.open("shortReport.txt");
	alphaOut.open("alphaReport.txt");
	std::vector<std::string> alpha;
	// iterare through student array
	for (int i = 0; i < 50; i++) {
		// define string to hold output, doing it like this so it looks better
		std::string out = "";
		std::stringstream ss(out);
		// doing this to make changing separator easier
		std::string s = "|";
		// append student data to string
		ss << "FirstName: " << students[i]->getFirstName() << s; 
		ss << "LastName: " << students[i]->getLastName() << s; 
		ss << "Address1: " << students[i]->getAddress1() << s; 
		ss << "Address2: " << students[i]->getAddress2() << s; 
		ss << "City: " << students[i]->getCity() << s; 
		ss << "State: " << students[i]->getState() << s; 
		ss << "Zip: " << students[i]->getZip() << s;
		ss << "DateOfBirth: " << students[i]->getDoB() << s;
		ss << "GraduationDate: " << students[i]->getDoGrad() << s; 
		ss << "GPA: " << students[i]->getGPA() << s; 
		ss << "CreditHours: " << students[i]->getCredHrs() << std::endl;
		// write to fullReport
		fullOut << ss.str();
		// write last and first name to shortReport and store in string for alpha report
		shortOut << students[i]->getLastName() << ", " << students[i]->getFirstName() << std::endl;
		std::string al = "";
		std::stringstream alph(al);
		alph << students[i]->getLastName() << ", " << students[i]->getFirstName();
		// push to vector
		alpha.push_back(alph.str());
		// when at end of loop
		if (i == 49) {
			// call sort method
			std::sort(alpha.begin(), alpha.end());
			// iterate through and append to alphaReport
			for (std::vector<std::string>::iterator it = alpha.begin(); it != alpha.end(); it++) {
				alphaOut << *it << std::endl;
			} // end for
		} // end if
	} // end for
	// close both output files
	fullOut.close();
	shortOut.close();
	alphaOut.close();
	// delete heap array
	for (int i = 0; i < 50; i++) {
		delete students[i];
	}
	delete[] students;
	// saying this for ease of use
	std::cout << "finished!" << std::endl << std::endl << std::endl;
	viewReports();
	return(0);
} // end main()

void viewReports() {
	// instrcutions
	std::cout << "press \"enter\" to view the full report..." << std::endl;
	// open file 1 and pause
	std::cin.get();
	std::ifstream in1;
	in1.open("fullReport.txt");
	// iterate through and print line
	bool run = true;
	while (run) {
		std::string line;
		getline(in1, line);
		if (in1.eof()) {
			in1.close();
			run = false;
		}
		else {
			std::cout << line << std::endl;
		} // end if
	} // end while
	// instrcutions and pause
	std::cout << std::endl << "press \"enter\" to view the short report..." << std::endl;
	std::cin.get();
	// open file 2
	std::ifstream in2;
	in2.open("shortReport.txt");
	// set run back to true and iterate through file and print
	run = true;
	while (run) {
		std::string line;
		getline(in2, line);
		if (in2.eof()) {
			in2.close();
			run = false;
		}
		else {
			std::cout << line << std::endl;
		} // end if
	} // end while
	// imstrcutions and pause for final time
	std::cout << std::endl << "press \"enter\" to view the alphabetical report..." << std::endl;
	std::cin.get();
	// open file 3
	std::ifstream in3;
	in3.open("alphaReport.txt");
	// set run back to true and iterate through file to print
	run = true;
	while (run) {
		std::string line;
		getline(in3, line);
		if (in3.eof()) {
			in3.close();
			run = false;
		}
		else {
			std::cout << line << std::endl;
		} // end if
	} // while
} // end viewReports()


























