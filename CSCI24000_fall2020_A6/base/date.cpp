#include "date.h"
#include <string>
#include <sstream>

// constrcutor
Date::Date() {
	// set defualt values
	Date::month = 1;
	Date::day = 1;
	Date::year = 1999;
} // end constructor

// set function
void Date::set(std::string date) {
	// create string and int variables for month, day, and year
	std::string m;
	std::string d;
	std::string y;
	int month;
	int day;
	int year;
	// use getline to grab month, day, and year from string parameter
	std::stringstream ss(date);
	getline(ss, m, '/');
	getline(ss, d, '/');
	getline(ss, y);
	// use stringstream to switch them to int
	std::stringstream intM(m);
	std::stringstream intD(d);
	std::stringstream intY(y);
	intM >> month;
	intD >> day;
	intY >> year;
	// set class variables
	Date::month = month;
	Date::day = day;
	Date::year = year;
} // end set()

// get
std::string Date::get() {
	// create string and use stingstream to format into m/d/y format
	std::string date = "";
	std::stringstream ss(date);
	ss << Date::month << "/" << Date::day << "/" << Date::year;
	// return result
	return(ss.str());
} // end get()





