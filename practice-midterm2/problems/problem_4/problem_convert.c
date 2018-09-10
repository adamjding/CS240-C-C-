#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 32

// Problem (1/2)
/*****************************************************************************
 * TODO: convert a number from the given base to decimal
 *
 * Parameters: number -- the number you are converting an integer
 *             base   -- the base of the number you are given
 * 
 * Return: The number as an integer
 *
 * Return Type: int
*****************************************************************************/
int mypow(int base, int exponent){
	int result = 1;
	if(exponent == 0)
		return 1;
	for(int i = 0; i < exponent; i++)
		result *= base;
	return result;
}
int toInteger(char * number, int base) {
// Write Your Code Here
	int baseTen = 0;
	int basefrom = base;
	for(int i = 0; i < strlen(number); i++){
		int temp = 0;
		if(number[i] > '9'){
			temp = number[i] - 'A' + 10;
		}
		else
			temp = number[i] - '0';
		baseTen = baseTen + temp * mypow(basefrom, strlen(number)-i-1);
	}
	return baseTen;
}

// Problem (2/2)
/*****************************************************************************
 * TODO: convert a number from the given base to decimal
 *
 * Parameters: number -- the number you are converting a string
 *             base   -- the base you are converting the numebr to
 * 
 * Return: The number as a string in base "base"
 *
 * Return Type: char *
*****************************************************************************/
char * toBase(int number, int base) {
	int index = 0;
	int remainders[100];
	char *result;
	while(number != 0){
		remainders[index] = number % base;	//gets the remainder
		index++;
		number = number / base;			//sets up for the next iteration
	}
	result = (char*)malloc(sizeof(char) * index);	
	int count = 0;
	for(int i = index-1; i >= 0; i--){
		if(remainders[count] > 9){
			remainders[count] = remainders[count] - 10 + 'A';
			result[i] = remainders[count];
		}
		else
			result[i] = remainders[count] + '0';
		count++;
	}
	result[index] = '\0';
	return result;
}
