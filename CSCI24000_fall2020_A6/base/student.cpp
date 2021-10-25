#include <string>
#include <sstream>
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

// set function aka build
void Student::build(std::string fName, std::string lName, std::string add1, std::string add2, std::string city, std::string state, std::string zip, std::string bDate, std::string gDate, double gpa, int crdHrs) {
	// set class variables
	*Student::firstName = fName;
        *Student::lastName = lName;
        Student::address->set(add1, add2);
        *Student::city = city;
        *Student::state = state;
        *Student::zip = zip;
        Student::DoB->set(bDate);
        Student::DoGrad->set(gDate);
        *Student::gpa = gpa;
        *Student::credHrs = crdHrs;
} // end build()

// get first name
std::string Student::getFirstName() {
	return(Student::firstName->c_str());
} // end getFirstName()

// get last name
std::string Student::getLastName() {
	return(Student::lastName->c_str());
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
	return(Student::city->c_str());
} // end getCity()

// get state
std::string Student::getState() {
	return(Student::state->c_str());
} // end getState()

// get zip
std::string Student::getZip() {
	return(Student::zip->c_str());
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























