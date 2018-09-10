
#include <stdlib.h>
#include "mystring.h"

// Type "man string" to see what every function expects.

int mystrlen(char * s) {
   int length = 0;
   while(s[length] != '\0')
   {
      length++;
   }
   return length;;
}

char * mystrcpy(char * dest, char * src) {
   int index = 0;
   while(src[index] != '\0')
   {
      dest[index] = src[index];
      index++;
   }
   dest[index] = '\0';
   return dest;
}

char * mystrcat(char * dest, char * src) {
    int destlength = mystrlen(dest);
    int i = 0;
    while(src[i] != '\0'){
        dest[destlength + i] = src[i];
        i++;
    }
    dest[destlength + i] = '\0';
    return dest;
}


int mystrcmp(char * s1, char * s2) {
   int length1 = 0;
   int length2 = 0;
   
   for(int i = 0; s1[i] != '\0'; i++)
   {
      length1 = length1 + s1[i];
   }

   for(int i = 0; s2[i] != '\0'; i++)
   { 
      length2 = length2 + s2[i];
   }

   if(length1 < length2)
   {
      return -1;
   }
   else if(length1 > length2)
   {
      return 1;
   }
   else
      return 0;
}

char * mystrstr(char * hay, char * needle) {
    int found = 0;
    int index = 0;
    for(int i = 0; i < mystrlen(hay)- mystrlen(needle); i++){
        
        for(int j = 0; needle[j] != '\0'; j++){
            if(hay[i+j] == needle[j]){
                found++;
            }
        }

        if(found == mystrlen(needle)){
            index = i;
            char* founded = (char*)malloc(sizeof(char) * (mystrlen(hay) - index));
            for(int n = index; hay[n] != '\0'; n++){
            founded[n - index] = hay[n];
             }
             founded[mystrlen(founded)] = '\0';
             return founded;
        }
        found = 0;
    }
    return NULL;
}
char * mystrdup(char * s) {
   char* copied = (char*)malloc(mystrlen(s) * sizeof(char));
   for(int i = 0; s[i] != '\0'; i++)
   {
      copied[i] = s[i];
   }
   copied[mystrlen(s)] = '\0';
   return copied;
}

char * mymemcpy(char * dest, char * src, int n)
{ 
   for(int i = 0; i < n; i++)
   {     
      dest[i] = src[i];
   }
   dest[n] = '\0';
   return dest;
}

