some_file:  other_file 
	echo "6565656"
	touch some_file

other_file: third second
	echo "3"



second: third
	echo "this is 2"


third:
	echo "this is 1"