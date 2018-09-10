
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include "MyString.h"

// My own implementation of strlen
int
MyString::slength(const char *s) const
{
  // Add implementation here
	int length = 0;
	while(s[length] != '\0'){
		length++;
	}
	return length;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
  // Add implementation here
  // Allocate memory for _s.
	int length = slength(s);
	_s  = new char[length];
  // Copy s into _s
	for(int i = 0; i < length; i++){
		_s[i] = s[i];
	}
	
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  _s = new char[1];
  *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
  if (this != &other) // protect against invalid self-assignment
  {
    // deallocate old memory
    delete [] _s;

    // Initialize _s with the "other" object.
    initialize(other._s);

    // by convention, always return *this
    return *this;
  }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
  // Add implementation here
  // Make sure that i is not beyond the end of string
  // Allocate memory for substring
  // Copy characters of substring
  // Return substring
	if(i > slength(_s)){
		return " ";
	}
	char result[n];
	for(int j = i; j < i+n; j++){
		result[j-i] = _s[j];
	}
	result[n] = '\0';
	return result;
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{
  // Add implementation here
  // If i is beyond the end of string return
  // If i+n is beyond the end trunc string
  // Remove characters
	if(n > slength(_s)){
		return;
	}
	int j = 0;
	for(j = i; j < i + n || j + n < slength(_s); j++){
		_s[j] = _s[j+n];
	}
	_s[j] = '\0';
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
	int i = 0;
	while(this->_s[i] != NULL){
		if(this->_s[i] != s._s[i]){
			return false;
		}
		i++;
	}
  	return true;
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
	int index = 0;
	while(this->_s[index] != NULL){
		if(this->_s[index] != s._s[index]){
			return true;
		}
		index++;
	}
  return false;
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
	int size1 = 0;
	int size2 = 0;
	
	int i = 0;
	while(this->_s[i] != '\0'){
		size1 += this->_s[i];
		i++;
	}
	i = 0;
	while(s._s[i] != '\0'){
		size2 += s._s[i];
		i++;
	}

	if(size1 <= size2){
		return true;
	}
	return false;
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
  // Add implementation here
	int size1 = 0;
	int size2 = 0;
	
	int i = 0;
 	while(this->_s[i] != '\0'){
		size1 += this->_s[i];
		i++;
	}
	i = 0;
	while(s._s[i] != '\0'){
		size2 += s._s[i];
		i++;
	}
	if(size1 <= size2){
		return false;
	}
  return true;
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
  // Add implementation here
	if(i > slength(_s)){
		return '\0';
	}
	return _s[i];
}

// Return C representation of string
const char *
MyString::cStr()
{
  // Add implementation here
  return _s;
}

// Get string length of this string.
int
MyString::length() const
{
  // Add implementation here
  return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  // Add implementation here
  delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  // Add implementation here
  // Allocate memory for the concatenated string
  // Add s1
  // Add s2
	int length = s1.slength(s1._s) + s2.slength(s2._s);
	MyString result;
	result._s = new char[length];
	int index = 0;
	for(int i = 0; i < s1.slength(s1._s); i++){
		result._s[i] = s1._s[i];
		index++;	
	}
	for(int i = 0; i < s2.slength(s2._s); i++){
		result._s[index] = s2._s[i];
		index++;
	}
	result._s[index] = '\0';
	return result;
}

