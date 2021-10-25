#include <string>
#include <sstream>
#include <cstdlib>
#include "student.h"
#include "date.h"
#include "address.h"
// constrcutor
Student::Student() {
	// initialize heap variables
	Student::firstName = new std::string;
	Student::lastName = new std::string;
	Student::address = new Address();
	Student::city = new std::string;
	Student::state = new std::string;
	Student::zip = new std::string;
	Student::DoB = new Date();
	Student::DoGrad = new Date();
	Student::gpa = new double;
	Student::credHrs = new int;
} // end constructor

Student::Student(std::string line) {
	// initialize heap variables and define strings to hold individual student data
	Student::firstName = new std::string;
	Student::lastName = new std::string;
	Student::address = new Address();
	Student::city = new std::string;
	Student::state = new std::string;
	Student::zip = new std::string;
	Student::DoB = new Date();
	Student::DoGrad = new Date();
	Student::gpa = new double;
	Student::credHrs = new int;
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
	*Student::firstName = firstName;
	*Student::lastName = lastName;
	*Student::address = Address(address1, address2);
	*Student::city = city;
	*Student::state = state;
	*Student::zip = zip;
	*Student::DoB = Date(DoB);
	*Student::DoGrad = Date(DoGrad);
	*Student::gpa = gpa;
	*Student::credHrs = credHrs;
} // end constructor

// deconstructor
Student::~Student() {
	// delete heap variables
	delete Student::firstName;
	delete Student::lastName;
	delete Student::address;
        delete Student::city;
        delete Student::state;
        delete Student::zip;
        delete Student::DoB;
        delete Student::DoGrad;
        delete Student::gpa;
        delete Student::credHrs;
} // end deconstructor

// get first name
std::string Student::getFirstName() {	
	return(*Student::firstName);
} // end getFirstName()

// get last name
std::string Student::getLastName() {
	return(*Student::lastName);
} // end getLastName()

// get address 1
std::string Student::getAddress1() {
	return(Student::address->get1());
} // end getAddress1()

// get address 2
std::string Student::getAddress2() {
        return(Student::address->get2());
} // end getAddress2()

// get city
std::string Student::getCity() {
	return(*Student::city);
} // end getCity()

// get state
std::string Student::getState() {
	return(*Student::state);
} // end getState()

// get zip
std::string Student::getZip() {
	return(*Student::zip);
} // end getZip()

// get DoB
std::string Student::getDoB() {
	return(Student::DoB->get());
} // end getDoB()

// get date of grad
std::string Student::getDoGrad() {
	return(Student::DoGrad->get());
} // end get getDoGrad()

// get GPA
double Student::getGPA() {
	return(*Student::gpa);
} // end getGPA()

// get credit hours
int Student::getCredHrs() {
	return(*Student::credHrs);
} // getCredHrs()























