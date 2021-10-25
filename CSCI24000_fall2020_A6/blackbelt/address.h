#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string>

class Address {
	private:
		std::string add1;
		std::string add2;
	public:
		Address();
		Address(std::string, std::string);
		std::string get1();
		std::string get2();
};

#endif
