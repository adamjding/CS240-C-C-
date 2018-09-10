#include <stdio.h>

int main() {
  char string[32];
  char upper[32] = {0};
  int i = 0;

  INPUT_STRING(string);

  for (i = 0; string[i] != 0; i++) {
	if((97 <= string[i]) && (string[i] <= 122)){
 		  upper[i] = string[i] - 'a' + 'A';
	}
	else{
		upper[i] = string[i];
	}
  }

  printf("Toupper: %s\n", upper);
  return 0;
}
