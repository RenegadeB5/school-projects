import java.util.*;

public class Main {
	// database
	protected Database db;
	// main
	public static void main(String[] args) {
		// call menu function
		Main main = new Main();
		main.menu();
	} // end main
	// constrcutor
	public Main() {
		// init database
		this.db = new Database();
	} // end constrcutor
	// menu
	public void menu() {
		// ask for account number and store
		System.out.println("Please enter your account number: ");
		Scanner input = new Scanner(System.in);
		String id = input.nextLine();
		// this is for testing, does a hard reset of db
		if (id.equals("admin:reset")) {this.db.reset(); System.exit(0);} // end if
		// grab user object from database
		List<User> users = this.db.get(id);
		// if it doesn't exist
		if (users.size() == 0) {
			// inform user and call menu again
			System.out.println("That account doesn't exist!");
			this.menu();
		} // end if
		else {
			// account exists, ask for pin
			User user = users.get(0);
			System.out.println("Please enter your pin: ");
			String pin = input.nextLine();
			// see if pin matches
			boolean status = user.authenticate(pin);
			// if status is false, pin doesn't match
			if (!status) {
				// inform and exit
				System.out.println("Wrong pin!");
				System.exit(0);
			} // end if
			// check type of user, and call the corresponding menu function
			if (user.getType().equals("user")) {
				this.userMenu(user);
			} // end if
			else if (user.getType().equals("admin")) {
				this.adminMenu();
			} // end else if
			else {
				System.exit(0);
			} // end else
		} // end else
	} // end menu
	// user menu
	public void userMenu(User user) {
		System.out.println();
		// display menu and get user input
		Scanner input = new Scanner(System.in);
		// doing it like this to not have annoying line
		StringBuilder s = new StringBuilder();
		s.append("What would you like to do?\n\n");
		s.append("1) Get Checking balance\n");
		s.append("2) Deposit into Checking\n");
		s.append("3) Withdraw from Checking\n");
		s.append("4) Get Savings balance\n");
		s.append("5) Deposit into Savings\n");
		s.append("6) Withdraw from Savings\n");
		s.append("7) Exit\n\n");
		s.append("Please type a number: ");
		System.out.println(s.toString());
		// convert to int and switch
		String choice = input.nextLine();
		switch (choice) {
			// get checking bal
			case "1":
				System.out.println("\nBalance: " + user.getCheckingBal());
				break;
			// checking desposit
			case "2": {
				// get amount and call method
				System.out.println("\nPlease enter an amount: ");
				double amount = Double.parseDouble(input.nextLine());
				user.checkingDeposit(amount);
				break;
			} // end case 2
			// checking withdraw
			case "3": {
				// get amount and call method
                                System.out.println("\nPlease enter an amount: ");
				double amount = Double.parseDouble(input.nextLine());
                                user.checkingWithdraw(amount);
				break;
			} // end case 3
			// get savings bal
			case "4":
				System.out.println("\nBalance: " + user.getSavingsBal());
				break;
			// savings deposit
			case "5": {
				// get amount and call method
				System.out.println("\nPlease enter an amount: ");
				double amount = Double.parseDouble(input.nextLine());
				user.savingsDeposit(amount);
				break;
			} // end case 5
			// savings withdraw
			case "6": {
				// get amount and call method
                                System.out.println("\nPlease enter an amount: ");
				double amount = Double.parseDouble(input.nextLine());
                                user.savingsWithdraw(amount);
				break;
			} // end case 6
			// exit
			case "7":
				// save database and exit
				this.db.write();
				System.exit(0);
			// if criteria wasn't met
			default:
				// if nothing matches
				System.out.println("Sorry but that isn't an option.");
				this.userMenu(user);
				break;
		} // end switch
		//System.out.println();
		this.userMenu(user);
	} // end userMenu
	// admin menu
	public void adminMenu() {
		System.out.println();
		// print menu and get input
		Scanner input = new Scanner(System.in);
		StringBuilder s = new StringBuilder();
		s.append("What would you like to do?\n\n");
		s.append("1) Create a user\n");
		s.append("2) Delete a user\n");
		s.append("3) List all users\n");
		s.append("4) Apply interest to all savings accounts\n");
		s.append("5) Exit\n");
		s.append("Please type a number: ");
		System.out.println(s.toString());
		String choice = input.nextLine();
		// switch
		switch (choice) {
			// create account
			case "1": {
				// ask for new account number
				System.out.println("Please create a 5-digit account number: ");
				String id = input.nextLine();
				// check if account already exists
				if (this.db.get(id).size() > 0) {
					System.out.println("This account number already exists!");
					this.adminMenu();
				} // end if
				// make sure it is right length
				else if (id.length() != 5) {
					System.out.println("Account number must be 5 digits!");
					this.adminMenu();
				} // end else if
				else {
					// ask for new pin
					System.out.println("Please create a 5-digit pin: ");
					String pin = input.nextLine();
					// make sure it is right length
					if (pin.length() != 5) {
						System.out.println("Pin must be 5 digits!");
						this.adminMenu();
					} // end if
					else {
						// create new account
						this.db.create(id, pin, "user", 0.0, 0.0);
						System.out.println("Done!\n");
					} // end else
				} // end else
				break;
			} // end case 1
			// delete account
			case "2": {
				// ask for id
				System.out.println("\nPlease enter the account number of the user: ");
				String id = input.nextLine();
				// make sure account exists
				if (this.db.get(id).size() == 0) {
					System.out.println("Account doesn't exist!");
					this.adminMenu();
				} // end if
				else {
					// delete account
					this.db.delete(id);
					System.out.println("Done!");
				} // end else
				break;
			} // end case 2
			// list users
			case "3": {
				try {
					// get array of accounts
					System.out.println();
					List<User> users = this.db.getAll();
					System.out.println("Current users: \n");
					// iterate through array and print user details
					for (User user: users) {
						System.out.println("Account number: " + user.getID());
						System.out.println("Type: " + user.getType());
						System.out.println("Checking bal: " + user.getCheckingBal());
						System.out.println("Savings bal: " + user.getSavingsBal() + "\n\n");
					} // end for
					// pause system
					System.out.println("Press \"Enter\" to continue...");
					System.in.read();
				} // end try
				catch (Exception err) {
					System.out.println(err.getMessage());
				} // end catch
				break;
			} // end case 3
			// apply interest to all accounts
			case "4": {
				// ask for period in months
				System.out.println("\nPlease type the period in months: ");
				int p = Integer.parseInt(input.nextLine());
				// ask for rate in decimal
				System.out.println("\nPlease enter the rate as a decimal: ");
				double r = Double.parseDouble(input.nextLine());
				// call compound method
				this.db.compound(p, r);
				break;
			} // end case 4
			// exit
			case "5":
				// save database and exit
				this.db.write();
				System.exit(0);
			// if option doesn't exist
			defualt:
				System.out.println("Sorry but that isn't an option.");	
				break;
		} // end switch
		System.out.println();
		this.adminMenu();
	} // end adminMenu
} // end Main











