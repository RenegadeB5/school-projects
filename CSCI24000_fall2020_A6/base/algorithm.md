Goal: Create a program that takes student data, stores it on the heap, and then generates reports using the data

Input: a file with 50 lines of student data

Output: a file that contains a report with every students data

Steps:

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
			init class DoGrad()
		deconstructor(): delete all heap variables
		build(all student info):
			assign variables to their corresponding values and call set functions for the address class and date classes
		to make this realistic, each private variable will have its own get function, so that someone could get whatever info they need
		make 11 get functions for all 10 variables:
		getFirstName(): return firstName
		getLastName(): return lastName
		getAddress1(): return address.get1()
		getAddress2(): return address.get2()
		getCity(): return city
		getState(): return state
		getZip(): return zip
		getDoB(): return DoB.get()
		getDoGrad(): return DoGrad.get()
		getGPA(): return gpa
		getCredHrs(): return credHrs

in main:
	init student class array with 50 instances on heap
	open input and output files
	define variable run and set to true
	define count variable and set to 0;
	while run is true:
		use getline to grab line from students.dat and store to string variable line
		check for eof(), and if true: close students.dat and set run to false
		initialize 11 strings to hold the 11 items per line in student.dat
		use getline 11 times, stopping at ',', and store them to their corresponding variables defined earlier
		call student[count].build(11 variables)
		add 1 to count
	
	to generate reports:
	iterate through student array:
		for each student, build report using student.get() methods for each piece of information
		append to output file
	when end of file is reached, close output














