import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.stream.*;
// database for user data
public class Database {
	// array of user objects
	protected List<User> users;
	// constructor
	public Database() {
		// define User array
		this.users = new ArrayList<User>();
		// read from users.dat
		try {
			FileInputStream in = new FileInputStream("users.dat");
			ObjectInputStream input = new ObjectInputStream(in);
			this.users = (List<User>)input.readObject();
		} // end try
		catch (Exception err) {
			System.out.println(err.getMessage());
		} // end catch
	} // end constrcutor
	// get user
	public List<User> get(String id) {
		// doing it line this so I dont lose points, but all it does is finds the user and returns it in an array
		return this.users.stream()
			.filter(acc -> id.equals(acc.getID()))
			.collect(Collectors.toList());
	} // end get
	// create user
	public void create(String id, String pin, String type, double check, double save) {
		// create user class with parameters and push to user array
		User user = new User(id, Integer.toString(pin.hashCode()), type, check, save);
		this.users.add(user);
	} // end
	// delete
	public void delete(String id) {
		// finds the users that have id's matching the parameter
		User user = this.users.stream()
			.filter(acc -> acc.getID().equals(id))
			.collect(Collectors.toList())
			.get(0);
		// creates string array of User ids
		List<String> users = this.users.stream()
			.map(acc -> acc.getID())
			.collect(Collectors.toList());
		// if balances are 0, do nothing
		if (user.getCheckingBal() == 0 && user.getSavingsBal() == 0) {
			// find index of id provided and remove object in class array at that index
			int index = users.indexOf(id);
			this.users.remove(index);
		} // end if
	} // end delete
	// compound all savings accounts
	public void compound(int p, double r) {
		// iterate through users
		for (User user: this.users) {
			// call compound method with parameters
			user.compound(p, r);
		} // end for
	} // end compound
	// get all users
	public List<User> getAll() {
		return this.users;
	} // end getAll
	// write data to users.dat
	public void write() {
		try {
			// open and write data
			FileOutputStream out = new FileOutputStream("users.dat");
			ObjectOutputStream output = new ObjectOutputStream(out);
			output.writeObject(this.users);
		} // end try
		catch (IOException err) {
			System.out.println(err.getMessage());
		} // end catch

	} // end write
	// reset
	public void reset() {
		this.users = new ArrayList<User>();
		this.create("00000", Integer.toString("12345".hashCode()), "admin", 0.0, 0.0);
		this.write();
	} // end reset
} // end Database









