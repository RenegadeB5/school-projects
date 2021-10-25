Goal: Create a program that takes student data, stores it on the heap, and then generates reports using the data

Input: a file with 50 lines of student data

Output: a file that contains a report with every students data

Steps:

prototype viewReports(): void

define class Address():
	private:
		string address1 and address2
	methods:
		constructor sets defualt values
		set (addr1 and addr2):
			set address1 to string1
			do same with address2 and string2
		get1: return address1
		get2: return address2

define class Date():
	private:
		int month, day, year
	methods:
		constructor sets defualt values
		set (string with format "month/day/year"):
			parse string and extract integer values
			set month to int1
			set day to int2
			set year to int3
		get(): return string date in month/day/year format with stringstream

define class Student():
	private:
		string firstName
		string lastName
		class Address
		string city
		string state
		string zip
		class DoB (Date of Birth)
		class DoGrad (Date of Graduation)
		double gpa
		int credHrs
	methods:
		consrtcutor():
			initialize all heap variables
			init class Address()
			init class DoB()
			init class DoGrad()e
			initialize 11 strings to hold the 11 items per line in student.dat
			use getline 11 times, stopping at ',', and store them to their corresponding variables defined earlier
			assign variables to their corresponding values and initialize the address class and date classes with their parameters
		deconstructor(): delete all heap variables
		to make this realistic, each private variable will have its own get function, so that someone could get whatever info they need
		define 11 get functions for all 10 variables:
		getFirstName(): return firstName string
		getLastName(): return lastName string
		getAddress1(): return address.get1() string
		getAddress2(): return address.get2() string
		getCity(): return city string
		getState(): return state string
		getZip(): return zip string
		getDoB(): return DoB.get() string
		getDoGrad(): return DoGrad.get() string
		getGPA(): return gpa double
		getCredHrs(): return credHrs int

def main:
	init student class array with 50 instances on heap
	open input and output files
	define variable run and set to true
	define count variable and set to 0;
	while run is true:
		check for eof(), and if true: close students.dat and set run to false
		use getline to grab line from students.dat and store to string variable line
		initialize student[count] with string as parameter
		add 1 to count 
	to generate reports:
	define empty string vector
	iterate through student array:
		for each student, build report using student.get() methods for each piece of information
		append to string
		append string to fullReport
		grab first and last name and store to variable
		append to shortReport and to vector
		if i = 49:
			call sort method of vector
			iterate through vector and append to alphaReport
	when end of file is reached, close output
	call viewReports()
def viewReports():
	repeat this process 3 times:
	open file
	print instructions
	pause
	iterate through file:
		if end of file, set run to false and close file
		get line and print











