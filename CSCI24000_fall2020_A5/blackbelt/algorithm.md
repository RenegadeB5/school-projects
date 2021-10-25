Goals: Create a program that takes input from a file, "parses" it, and then writes the result in an output file

Input: "input.txt" file that has the structure:
int, int, int
word
(and this repeats)

Output: "output.txt" file that takes the input, adds all the integers, and then repeats the word as many times as the sum of the integers

Steps:
prototype: contents(): void
in main function:

define variable "run" and set to true
open input.txt
open output.txt
while run is true:
	if end of file:
		close input.txt
		close output.txt
		set run to false
	else:
		define variable "numbers" (string)
		define variable "word" (string)
		define variable "count" (int)
		use getline and store contents to numbers
		use getline again and store contents to word
		split numbers by ","
		convert the numbers to ints
		make sure there are no decimals or negatives
		if the word is blank then set count to 0
		add the numbers together
		use for loop with count:
			append word to output.txt
		append end line to output.txt
call contents()
		
function contents():
	define variable run and set to true
	open input.txt and output.txt
	print "contents of input.txt"
	while run is true:
		if end of file:
			close input.txt
			set run to false
		else:
			define string output
			grab line from input.txt and put in output
			print output
	set run to true
	while run is true:
		if end of file:
			close output.txt
			set run to false
		else:
			define string output
			grab line from input.txt and put in output
			print output

