#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	char *delChars(const char *s1, const char *s2)
 *
 *  Arguments:
 *		const char *s1 -- a pointer to a string
 *      const char *s2 -- a pointer to a string
 *
 *  Function return:
 *      char * -- a pointer to a string that contains the characters in "s1 that are
 *		 not in "s2".
 *
 *  Description:
 *		The function creates a new string with the characters from “s1” that
 *		 ignores any character that is contained in “s2”.
 *
 *	Example:
 *		delChars("Hello World", "Said George");  // returns "HllWl"
 */

char *delChars(const char *s1, const char *s2){
	int length = 0;
	int index = 0;
	int check;
	for(int i = 0; s1[i] != '\0'; i++){
		length++;
	}
	char* result = (char*)malloc(length * sizeof(char));
	
	for(int i = 0; s1[i] != '\0'; i++){
		check = 0;
		for(int j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				check = check + 1;
			}							
		}
		if(check == 0){
			result[index] = s1[i];
			index++;
		}
	}
	return result;
}
