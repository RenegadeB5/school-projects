import java.io.*;
// User
public class User implements Serializable {
	// variables for user members
	protected String id;
	protected String pin;
	protected String type;
	protected Checking checking;
	protected Savings savings;
	// default constrcutor
	public User() {
		// set default values
                this.id = "0";
                this.pin = "0";
                this.type = "user";
		this.checking = new Checking();
                this.savings = new Savings();
	} // end default constrcutor
	// constrcutor
	public User(String id, String pin, String type, double check, double save) {
		this.id = id;
		this.pin = pin;
		this.type = type;
		this.checking = new Checking(check);
		this.savings = new Savings(save);
	} // end constrcutor
	// check pin
	public boolean authenticate(String pin) {
		// returns bool for if pin matches
		if (this.pin.equals(Integer.toString(pin.hashCode()))) {
			return true;
		} // end if
		else {
			return false;
		} // end else
	} // end authenticate
	// get account number
	public String getID() {
		return this.id;
	} // end getID
	// get Checking balance
	public double getCheckingBal() {
		// call checking getter
		return this.checking.getBalance();
	} // end getCheckingBal
	// checking deposit
	public void checkingDeposit(double amount) {
		this.checking.deposit(amount);
	} // end checkingDeposit
	// checking withdraw
	public void checkingWithdraw(double amount) {
		this.checking.withdraw(amount);
	} // end checkingWithdraw
	// savings bal getter
	public double getSavingsBal() {
		return this.savings.getBalance();
	} // end getSavingsBal
	// savings deposit
	public void savingsDeposit(double amount) {
		this.savings.deposit(amount);
	} // end savingsDeposit
	// savings withdraw
	public void savingsWithdraw(double amount) {
		this.savings.withdraw(amount);
	} // end savingsWithdraw
	// get type
	public String getType() {
		return this.type;
	} // end getType
	// interest method
	public void compound(int p, double r) {
		// call compound method with parameters
		this.savings.compound(p, r);
	} // end compound
	// my dumb version of serializing
	public String getData() {
		// separator
		String s = "|";
		// return string in format
		return this.id + s + this.pin + s + this.type + s + this.checking.getBalance() + s + this.savings.getBalance();
	} // end getData
} // end User






















