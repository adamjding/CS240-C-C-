
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
	FILE *fd;
	//Open file in fileName it
	//fd = fopen(...)
	fd = fopen(fileName, "r");	

	//char * word
	//while word = nextword(fd)
	char* word;
	//stack_clear();
	while((word = nextword(fd)) != NULL){
		double push = atof(word);
		if(strcmp(word, "x") == 0){
			stack_push(x);
		}
		if(push != 0){
			stack_push(push);
		}
		else if(strcmp(word, "+") == 0){
			if(stack_top() < 2){
 	                 printf("Stack underflow\n");
        	         exit(0);
    			 }
			double x = stack_pop();
			double y = stack_pop();
			x = x + y;
			stack_push(x);
		}
		else if(strcmp(word, "-") == 0){
			if(stack_top() < 2){
  	                 printf("Stack underflow\n");
        	         exit(0);
			 }
			double x = stack_pop();
			double y = stack_pop();
			x = y - x;
			stack_push(x);
		}		
		else if(strcmp(word, "*") == 0){
			if(stack_top() < 2){
	                 printf("Stack underflow\n");
        	         exit(0);
       			  }
			double x = stack_pop();
			double y = stack_pop();
			x = x * y;
			stack_push(x);
		}
		else if(strcmp(word, "/") == 0){
		        if(stack_top() < 2){
	                 printf("Stack underflow\n");
	                 exit(0);
		          }
			double x = stack_pop();
                        double y = stack_pop();
			x = y / x;
		        stack_push(x);
		}
		else if(strcmp(word, "sin") == 0){
			if(stack_top() < 1){
	                 printf("Stack underflow\n");
        	         exit(0);
    			 }
			double x = sin(stack_pop());
			stack_push(x);
		}	
		else if(strcmp(word, "cos") == 0){
			if(stack_top() < 1){
 	                 printf("Stack underflow\n");
        	         exit(0);
       	    	          }
			double x = cos(stack_pop());
			stack_push(x);
		}
		else if(strcmp(word, "pow") == 0){
			if(stack_top() < 1){
	                  printf("Stack underflow\n");
        	          exit(0);
        		  }
			double x = pow(stack_pop(), stack_pop());
			stack_push(x);
		}
		else if(strcmp(word, "log") == 0){
			if(stack_top() < 1){
 	                 printf("Stack underflow\n");
        	         exit(0);
        		 }
			double x = log(stack_pop());
			stack_push(x);
		}
		else if(strcmp(word, "exp") == 0){
			if(stack_top() < 1){
 	                 printf("Stack underflow\n");
        	         exit(0);
        		  }
			double x = exp(stack_pop());
			stack_push(x);
		}
	}
	
	//Check for errors
	//
	if(stack_top() != 1){
		printf("Elements remain in the stack\n");
		exit(0);
	}
	
	//Return result
	double result = stack_pop();
	return result;
}

