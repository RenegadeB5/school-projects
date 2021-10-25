#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include <string>
#include "address.h"
#include "date.h"

class Student {
	private:
		std::string* firstName;
		std::string* lastName;
		Address* address;
		std::string* city;
		std::string* state;
		std::string* zip;
		Date* DoB;
		Date* DoGrad;
		double* gpa;
		int* credHrs;
	public:
		Student();
		Student(std::string);
		~Student();
		std::string getFirstName();
		std::string getLastName();
		std::string getAddress1();
		std::string getAddress2();
		std::string getCity();
		std::string getState();
		std::string getZip();
		std::string getDoB();
		std::string getDoGrad();
		double getGPA();
		int getCredHrs();
};

#endif
