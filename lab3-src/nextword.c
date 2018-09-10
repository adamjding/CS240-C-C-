
#include <stdio.h>
#include <stdlib.h>

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

// It returns the next word from fd.
// If there are no more more words it returns NULL. 
char * nextword(FILE * fd) {
  	int c;
	
	// While it is not EOF read char
		// While it is not EOF and it is a non-space char
		// store character in word.
		// if char is not in word return word so far.
		//
	// Return null if there are no more words

	for(int i =0; i < 200;i++){
		word[i] = '\0';
	}

	char* word = (char*)malloc(sizeof(char) * MAXWORD);
	wordLength = 0;
	while((c = fgetc(fd)) != -1){
		if(((c != '\r') && (c != '\n') && (c != '\t') && (c != ' '))){
			//word[wordLength] = c;
                        //wordLength++;
			if(c == '\0'){
			}
			else{
				word[wordLength] = c;
				wordLength++;
			}
			
		}
		else if (wordLength > 0){
			word[wordLength] = '\0';
			return word;
		}
	}
	if(wordLength > 0){
		return word;
	}
	
 	return NULL;
}

