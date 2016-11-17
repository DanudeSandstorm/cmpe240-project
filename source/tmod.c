#include "tmod.h"
#include "array.h"

int translate(Array* mcode, char* input, size_t charsGot) {
	//For each character in inputed string
	for (size_t i = 0; i < charsGot; ++i) {
		char ch = buffer[i];

		//Do lookup here
		char* tran;
		if ((tran = lookup(ch)) == "invalid") {
			continue;
		}

		//Add translated value to "mcode"
		insertArray(&mcode, tran);
	}
	
	return 0;
}

/*
Uses a lookup table for a char and 
returns the corresponding morse code.
Returns space for space
Returns invalid if not a morse character
Uses offset for ascii char values to relative position in table
*/
char* lookup(char ch) {
	if (ch == ' ') return " ";
	
	int input = ch;
	//Numbers
	if ((input >= 48)) && (input <= 57)) {
		input -= 48 + 26; //offset plus alphabet size
	}
	//Uppercase
	else if ((input >= 65)) && (input <= 90)) {
		input -= 65;
	}
	//Lowercase
	else if ((input >= 97)) && (input <= 122)){
		input -= 97;
	}
	else {
		return "invalid";
	}

	return lookuptable[input];
}

