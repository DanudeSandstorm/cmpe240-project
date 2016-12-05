#include "tmod.h"
#include "global.h"

int translate(char** mcode, char* input, size_t charsGot) {
	//For each character in inputed string
	for (size_t i = 0; i < charsGot; ++i) {
		char ch = input[i];

		//Do lookup here
		char* translation;
		if ((translation = (char*)lookup(ch))[0] == '!') {
			continue;
		}
		
		//Add translated value to "mcode"
		mcode[returnSize] = translation;
		returnSize++;
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
const char* lookup(char ch) {
	if (ch == ' ') return " ";
	
	int input = ch;
	//Numbers
	if ((input >= 48) && (input <= 57)) {
		input -= 48 + 26; //offset plus alphabet size
	}
	//Uppercase
	else if ((input >= 65) && (input <= 90)) {
		input -= 65;
	}
	//Lowercase
	else if ((input >= 97) && (input <= 122)){
		input -= 97;
	}
	else {
		return "!";
	}

	return lookuptable[input];
}

