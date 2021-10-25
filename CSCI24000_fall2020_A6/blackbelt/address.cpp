#include "address.h"
#include <string>
#include <sstream>

// constrcutor
Address::Address() {
	// set defualt values
	Address::add1 = "N/A";
	Address::add2 = "N/A";
} // end constrcutor

// setter
Address::Address(std::string add1, std::string add2) {
	// set class variables
	Address::add1 = add1;
	Address::add2 = add2;
} // end set()

// get address 1
std::string Address::get1() {
	return(this->add1);
} // end get1()

// get address 2
std::string Address::get2() {
	return(this->add2);
} // end get2()
