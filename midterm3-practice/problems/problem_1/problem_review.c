#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "review.h"

// Problem (1/4)
/******************************************************************************
 * TODO: Return a pointer to the first occurrence of the character 'c' in the 
 * string 's'. Return NULL if the character is not found.
 * 
 * Parameters: s -- string
 *             c -- search for this character in the string 's'
 *
 * Return: pointer to the first occurene of the character c in the string s
 *
 * Return Type: char pointer
 *****************************************************************************/
char *strchr(const char *s, int c) 
{
    // Write Your Code Here
	char *string = s;	//creates pointer to string
	while(*string){		
		if(*string == c){
			return string;
		}
		string++;
	}	//iterates through the pointer
    return NULL;
}

// Problem (2/4)
/******************************************************************************
 * TODO: Return the maximum element in the array
 * 
 * Parameters: array -- an integer array
 *             n -- number of elements in the array
 *
 * Return: the maximum element in the array
 *
 * Return Type: integer
 *****************************************************************************/
int max_array( int * array, int n )
{
    // Write Your Code Here
	int max = array[0];
	for(int i = 1; i < n; i++){
		if(max < array[i]){
			max = array[i];
		}
	}
    return max;
}

// Problem (3/4)
/******************************************************************************
 * TODO: Return the 'ith' bit in 'bitmap' (either 0 or 1)
 * 
 * Parameters: bitmap -- unsigned integer
 *             ith -- index of the bit to be returned
 *
 * Return: the largest element in the array 
 *
 * Return Type: integer
 *****************************************************************************/
int get_bit_at( unsigned int bitmap, int ith )
{
    // Write Your Code Here
	return ((bitmap >> ith) & 1);
}

// Problem (4/4)
/******************************************************************************
 * TODO: Read from the file and store the entries in to a single linked list.
 * Return the list. Use the function llist_add( List * list, int value ) to
 * add entries to the list. 
 *
 * The file format will be:
 * value\n
 * value\n
 * value\n
 * ...
 *
 * Parameters: filename -- the name of the file you will be reading from
 *
 * Return: a singled linked list which contains the values read from the file
 *
 * Return Type: pointer to a single linked list
 *****************************************************************************/
List * llist_read( char * filename ) 
{
    // Write Your Code Here
	List *mylist = (List*)malloc(sizeof(List));
	llist_init(mylist);
	FILE *fd = fopen(filename, "r");
	if(fd == NULL){
		return NULL;
	}
	int i = 0;
	while(!feof(fd)){
		fscanf(fd, "%d", &i);
		if(!feof(fd)){
			llist_add(mylist, i);
		}
	}
	fclose(fd);
	return mylist;
}	
