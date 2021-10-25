Goals: write an ATM program in java that has all the functions of an atm

Input: menu inputs: along with amounts

Output: all data saved to database.dat

Steps:

Define classes:

class Checking:
	private: balance as double
	public methods:
		constructor(double):
			set balance to parameter 
		getBalance():
			return balance
		deposit(double):
			add parameter to balance
		withdraw(double):
			subtract parameter from balance

class Savings:
	inherit from Checking class
	add one more method: compound(int, double): (calculates interest)
		set balance to balance * (1 + (int * double))

class User:
	private:
		Object checking
		Object savings
		string id - account number
		string pin - pin
		string type - type "admin" or "user"
	public methods:
		constrcutor #1(): default constrcutor, sets all values to default
		constrcutor #2(string id, string pin):
			set id and pin to parameters, we call this when admin makes new account, they provide # and pin
		constructor #3(double check, double save, string id, string pin, string type):
			set private variables to corresponding parameters, we call this when making array from users.dat
			init checking and savings class with check and save as parameters
		public methods:
			void authenticate(string pin):
				if pin = this pin, return true, otherwise return false
			string getID():
				return id
			double getCheckingBal():
				return checking.getBalance()
			void checkingDeposit(double amount):
				call checking.deposit(amount)
			void checkingWithdraw(double amount):
				call checking.withdraw(amount)
			double getSavingsBalance():
				return savings.getBalance()
			void savingsDeposit(double amount):
				call savings.deposit(amount)
			void savingsWithdraw(double amount):
				call savings.withdraw(amount)
			void getType():
				return type variable
			void compound(int p, double r):
				call savings.compound(p, r)
			string getData():
				return serialization of all data stored in class. Will return "id|pin|type|checking bal|savings bal"

class Database()
	private: users - list of user objects
	public methods:
		constructor():
			use try catch to open "users.dat" using IO
			for each line:
				use object serialization reader to grab array list from users.dat
				set user array to data
		Object get(int id):
			return user class from array that matches id (or reference to class)
		void create(string id, string pin, string type, double check, double save):
			create new user class with info from parameters
			push class to array
		void delete(int id):
			find user in users and store to variable
			create map array of all user ids from users
			if both balances for user are 0:
				find index of id provided in map of ids
				delete object from users at that index
		void compound(int p, double r):
			for each user: call user.compound(p, r)
		array getAll():
			return users
		void write():
			Use object serializaion and write to users.dat

in main:
	private variable db for database
	constrcutor:
		set db to new Database
	main:
		call menu()
	function menu():
		prompt user for account number
		use database.get(id) to get list of user objects that match id provided by user
		if length of list is zero: print "invalid pin", and call menu() again
		call database.authenticate(input) and store to variable status
		if status is false: print "wrong pin" and exit program
		if user.getType = "user":
			call userMenu(user object)
		if type is admin:
			call adminMenu()
		admin and user menu have their own functions

	function userMenu(User user):
		Print menu and ask for user input, they will choose number 1-7
		1) Get Checking balance
		2) Deposit into Checking
		3) Withdraw from Checking
		4) Get Savings balance
		5) Deposit into Savings
		6) Withdraw from Savings
		7) Exit
		store input to variable
		use switch:
			case 1: print checking balance from user
			case 2: ask for checking deposit amount, call user checking deposit method with parameter
			case 3: ask for checking withdraw amount, call user checking withdraw method with parameter
			case 4: print savings balance from user
			case 5: ask for savings deposit amount, call user savings deposit method with parameter
			case 6: ask for savings withdraw amount, call user savings withdraw method with parameter
			case 7: exit program
			otherwise: print "that's not an option" and call this.userMenu(user)
		call this.userMenu()

	function adminMenu():
		Print menu and ask for user input, they will choose number 1-5
		1) Create a user
		2) Delete a user
		3) List all users
		4) Apply interest to all savings accounts
		5) Exit
		store input to variable
		use switch:
			case 1: ask for input for new users id and pin, while making sure they meet length requirement of 5. If account already exists, call adminMenu again
				call database.create() with id and pin choses as parameters
			case 2: ask for account id, and check if it exists. 
				If so, call database.delete with id as parameter, otherwise notify user account doesnt exist and call adminMenu()
			case 3: call database.getAll and store to variable
				for each user in list, print id, type, checking balance, and savings balance
			case 4: ask for input on period in months and rate as a decimal. call database.compound with period and rate as parameters
			case 5: exit program
			otherwise: print "that's not an option" and call this.adminMenu()
		
			




























