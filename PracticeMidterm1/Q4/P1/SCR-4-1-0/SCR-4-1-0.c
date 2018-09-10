#include <stdlib.h>
#include <stdio.h>


void printNums(){
	int size = 0;	//used to keep track of elements in file
	char c;
	char* result = (char*)malloc(sizeof(char) * 200);
	while((c = getchar()) != EOF){
			
		result[size] = c;
		size++;
	}
	result[size] = '\0';
	
	if(size == 0)
		printf("No integers were provided.\n");
	else{
		printf("{");
		for(int i = 0; result[i] != '\n'; i++){
			if(result[i] == ' '){
				printf(" ");
			}
			else if(result[i+1] != ' '){
				printf("%c%c", result[i], result[i+1]);
				i++;
				if(result[i+1] != '\n')
					printf(",");
			}
			else
				printf("%c,", result[i]);
			
		}	
		printf("}");
		printf("\n");
	}
}
