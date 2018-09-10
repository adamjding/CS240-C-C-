
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;

 	// Add your implementation here
	int check = '\n';
	printf("Program that counts lines.\n");
	char* fileName = argv[1];
	FILE* fd = fopen(fileName, "r");

	if(fd == NULL){
	printf("Could not open file %s\n", fileName);
	exit(1);
	}

	//iterate over all lines in file
	while((c = fgetc(fd))!= -1){
	if(c == check){
	lines++;
	 }
	}

	fclose(fd);	
	printf("Total lines: %d\n", lines);		
	exit(0);
}
