
#include "tmod.h"
#include "ledmod.h"
#include "printf.h"

int print_translation(const char* string) {
    //TODO format output
    return 0;
}

char alph[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";


char transl[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----" };


uint32_t getIndex(find){
	for (uint32_t i = 0; i < 36; i++){
		if (alph[i] == find){
			return i;
		}		
	}
	
}

int translate(input) {
	//0 for success, 1 for failure
	char ret[1000];
	int pos = 0;
	int k;
	int n = 5;
	
	for (k=0; k < n; k++) {
		pos += sprintf(&ret[pos], ", val%d", k);
	}
	
	
}
