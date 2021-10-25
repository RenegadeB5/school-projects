import java.util.*;
import java.text.*;
import java.io.*;
// inherets from Checking
public class Savings extends Checking implements Serializable {
	// default constrcutor
	public Savings() {
		// user Checking's constrcutor
		super();
	} // end default constrcutor
	// constrcutor
	public Savings(double amount) {
		// use Checking's constrcutor with parameter
		super(amount);
	} // end constructor
	// interest method
	public void compound(int p, double r) {
		// make sure decimal is right length
		DecimalFormat dec = new DecimalFormat("#0.00");
		// intrest calculation
		double newBal = this.balance * (1 + (p * r));
		// set new balance, format returns string so this is a complex line that converts
		this.balance = Double.parseDouble(dec.format(newBal));
	} // end compound
} // end Savings
