#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Problem (1/4)
/******************************************************************************
 * TODO: Print the array.
 *       The format should be (array index)(colon)(array element)(newline) 
 * 
 * Parameters: n -- the number of elements in the array
 *             array -- a double array
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void printArray(int n, double * array) {
// Write Your Code Here
	double *p = array;
	double *end = p+n;
	int i = 0;
	while(p<end){
		printf("%d:%f\n", i, *p);
		p++;
		i++;
	}
	
}

// Problem (2/4)
/******************************************************************************
 * TODO: Return the minimum element of array 
 * 
 * Parameters: array -- a double array
 *             n -- the number of elements in the array
 *
 * Return: minimum element in array 
 *
 * Return Type: double
 *****************************************************************************/
double minArray(int n, double * array) {
// Write Your Code Here
	double min = array[0];
	for(int i = 1; i < n; i++){
		if(array[i] < min)
			min = array[i];
	}
	return min;
}

// Problem ( 3/4 ) 
/******************************************************************************
 * TODO: Reverse the given string 'str'. 
 * E.g. reverse_str("smile") should return "elims"
 * 
 * Parameters: str -- The given string to be reversed.
 *
 * Return: A pointer to str, str should be reversed 
 *
 * Return Type: char pointer
 *****************************************************************************/
char * reverse_str (char * str ) {
    // Write Your Code Here
	int index = 0;
	char *result = (char*)malloc(sizeof(char) * strlen(str));
	
	for(int i = strlen(str) - 1; i >= 0; i--){
		*(result + index) = *(str + i);
		index++;
	}
	*(result + index) = '\0';
	strcpy(str,result);
	return str;
}

// Problem ( 4/4 ) 
/******************************************************************************
 * TODO: Determine if the string str2 is a permutation of str1. A permutation
 * is the rearranging of characters in a different order. 
 * E.g. the string "act" is a permutation of "cat" 
 *
 * Hint: count the occurences of each letter
 * 
 * Parameters: str1 -- The original string
 *	       str2 -- Determine if this string is a permutation of str1 
 *
 * Return: 1 if str2 is a permutation
 *         0 if str2 is not a permutation
 *
 * Return Type: integer
 *****************************************************************************/
int is_permutation ( char * str1, char * str2 ) {
    // Write Your Code Here
	int alphabet[26];
	for(int i = 0; i < 26; i++)	//initialize array
		alphabet[i] = 0;
	for(int i = 0; i < strlen(str1); i++)	//updates alphabet with occurences of letters of str1
		alphabet[str1[i] - 97]++;
	for(int i = 0; i < strlen(str2); i++)	//updates alphabet with occurences of letters of str2
		alphabet[str2[i] - 97]++;
	for(int i = 0; i < 26; i++){
		if(alphabet[i] % 2 != 0)	//if the letter isnt divisible by two that means both strings didnt have the same value
			return 0;
	}
	return 1;
}
