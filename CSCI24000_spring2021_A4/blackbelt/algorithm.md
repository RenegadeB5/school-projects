Goals: Simulate a 5-horse race using OOP in c++ 
Input: A number to seed the random number generator
Output: The results of each turn followed by the winner
Steps:

Create class Horse():
	contruct with int position = 0
	the methods will be:

	advance():
		generate random number between 1 and 0, and add it to position to simulate a coin flip
	getPosition():
		returns the current position of the horse from this class
	reset():
		set position back to zero

Create class Race:
	construct with:
		h: an array of 5 instances of horse class 
		length l: length of track
		lb: array of 5 zeros, will hold score for horses
	methods:
		printLane(lane #):
			inserts horse # at h.getPosition() in a string of 14 "."s
		win():
			for item in h:
				if h.getPosition = 14, announce horse has won
				announce horse and add one point to corresponding spot in lb
				call menu()
		menu():
			state menu: 1 = run race, 2 = view leaderboard, 3 = exit
			ask for input
			if 1:
				call race.start()
			if 2:
				iterate through lb and print horse num and value
				call menu()
			if 3:
				exit program
			else:
				alert user that command doesnt exist and call menu()
			
		start():
			get input from user for random number
			put number in srand
			define run as true
			while run is true:
				define win as false
				for each item in h:
					define horse as h[i]
					call horse.advance()
					call printLane(i)
					if h.getPosition = 14:
						set win to true
				if win = true:
					call win() function
in main function:
	call race.menu()

