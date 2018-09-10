
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int top=0;
double stack[MAXSTACK];

void stack_clear() 
{
  top = 0;
}

double stack_pop()
{
	// Add implementation here
	return stack[top--];
}

void stack_push(double val)
{
	// Add implementation here
	top++;
	stack[top] = val;
}

void stack_print()
{
	printf("Stack:\n");
	if(top == 0){
		printf("Stack is empty");
	}
	else{
       	  for(int i = 1; i < top+1; i++){
                 printf("%d: %f\n", i- 1, stack[i]);
  	}
}
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
	if(top > 0){
	return 0;
	}
	else
	return 1;
}


