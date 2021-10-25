import java.io.*;

public class Checking implements Serializable {
	// store balance
	protected double balance;
	// default constrcutor
	public Checking() {
		// set to 0
		this.balance = 0;
	} // end default constrcutor
	// constrcutor
	public Checking(double bal) {
		this.balance = bal;
	} // end constrcutor
	// get balance
	public double getBalance() {
		return this.balance;
	} // end getBalance
	// deposit
	public void deposit(double amount) {
		this.balance += amount;
	} // end deposit
	// withdraw
	public void withdraw(double amount) {
		// if new balance amount will be below 0, nothing will happen
		if ((this.balance - amount) >= 0) {
			this.balance -= amount;
		} // end if
	} // end withdraw
} // end Checking
