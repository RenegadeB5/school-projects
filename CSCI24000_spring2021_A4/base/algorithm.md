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
	methods:
		printLane(lane #):
			inserts horse # at h.getPosition() in a string of 14 "."s
		win():
			for item in h:
				if h.getPosition = 14, announce horse has won
		start():
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
	get input from user for random number
	put number in srand
	call race class with length as parameter
	call race.start()

