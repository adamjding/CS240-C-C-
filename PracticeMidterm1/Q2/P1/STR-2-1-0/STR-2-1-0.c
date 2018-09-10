#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	int mystrcmp(const char *s1, const char *s2)
 *
 *  Arguments:
 *		const char *s1 -- a pointer to a string
 *		const char *s2 -- a pointer to a string
 *
 *  Returns:
 *		int -- (-1) if "s1" < "s2", (0) if "s1" == "s2", and (1) if "s1" > "s2"
 *
 *  Description:
 *		The function compares the string pointed to by “s1” to the string pointed
 *		 to by “s2” and returns (-1) if the char at where the two strings differ is
 *		 smaller in “s1”, (1) if the char at where they differ is greater in “s1”,
 *		 and (0) if the two strings are equal.
 *
 *	Example:
 *		mystrcmp("Hello", "World");  // returns -1
 *		mystrcmp("World", "Hello");  // returns 1
 *		mystrcmp("Hello", "Hello");  // returns 0
 *		mystrcmp("Hello", "Hello World");  // returns -1
 */

int mystrcmp(const char *s1, const char *s2)
{
	int len1 = 0;
	int len2 = 0;
	
	for(int i = 0; s1[i] != '\0'; i++)
		len1 = len1 + s1[i];
	
	for(int i = 0; s2[i] != '\0'; i++)
		len2 = len2 + s2[i];
	
	if(len1 < len2)
		return -1;
	else if(len1 > len2)
		return 1;
	else
		return 0;
}
