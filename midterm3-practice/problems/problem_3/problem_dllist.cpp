#include <iostream>
#include <string>
#include "DLList.h"

// Constructor
// DO NOT CHANGE
DLList::DLList() 
{
    head = new ListNode();
    head->next = head;
    head->prev = head;
}

// Prints the list
// DO NOT CHANGE
void DLList::print_list() 
{
    std::cout << "Printing List..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;  
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else 
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Prints the list given a list name
// DO NOT CHANGE
void DLList::print_list( std::string list_name ) 
{
    std::cout << "Printing " << list_name << "..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;  
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else 
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Problem (1/5)
/******************************************************************************
 * TODO: Write the destructor. The destructor should delete all of the 
 * list nodes from the list. 
 *****************************************************************************/
DLList::~DLList()
{
    // Write Your Code Here
	ListNode *d = head->next;
	while(d != head){
		ListNode *temp = d;
		d = d->next;
		delete temp;
	}
	delete head;
}

// Problem (2/5)
/******************************************************************************
 * TODO: Insert a new ListNode to the end of the double linked list. 
 * Remember the list head is a sentinel node, do not change head. 
 * Set the value of the new node to the parameter 'value'.
 * 
 * Parameters: value -- set the value of the node equal to this
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void DLList::insert_last( int value ) 
{
    // Write Your Code Here
	ListNode *d = new ListNode();
	d->value = value;
	
	d->next = head;
	d->prev = head->prev;
	d->next->prev = d;
	d->prev->next = d;
}

// Problem (3/5)
/******************************************************************************
 * TODO: Remove the node from the double linked list whose value equals the 
 * parameter 'value', return true after deleting the node. If the node does not
 * exist in the list or the list is empty, return false;
 * 
 * Parameters: value -- remove the node whose value is equal to this
 *
 * Return: true if the node was removed successfully
 *         false if the value does not exist in the list or the list is empty
 *
 * Return Type: void
 *****************************************************************************/
bool DLList::remove( int value ) 
{
    // Write Your Code Here
	ListNode *d = head->next;
	if(head == NULL){
		printf("EMPTY LIST\n");
		return false;
	}	
	while(d != head){
		if(d->value == value){
			d->prev->next = d->next;
			d->next->prev = d->prev;
			delete d;
			return true;
		}
		d = d->next;
	}
	return false;
}

// Problem (4/5)
/*****************************************************************************
* TODO: Return the ith node inside of the double linked list. If the list is
* empty or has less than 'ith' entries, return NULL.
* 
* Return: the 'ith' node in the list
*         NULL if the node does not exist
*
* Return Type:  
*****************************************************************************/
ListNode * DLList::get_ith( int ith ) 
{
    // Write Your Code Here
	int length = 0;
	ListNode *d = head->next;
	while(d != head){
		length++;
		d = d->next;
	}
	if(ith > length){
		return NULL;
	}
	d = head->next;
	int index = 0;
	while(d != head){
		if(index == ith){
			return d;
		}
		index++;
		d = d->next;
	}
	return NULL;
}

// Problem (5/5)
/*****************************************************************************
* TODO: Overload the operator '==' for comparison. The comparison operator
* should compare the two lists to check if they have the all of the same
* elements. Return true if the two lists are equal, return false otherwise.
*****************************************************************************/
bool DLList::operator == (const DLList & listB) 
{
    // Write Your Code Here
	ListNode *d = head->next;
	int length1 = 0;
	while(d != head){
		length1++;
		d = d->next;
	}
	d = head->next;
	
	ListNode *l = listB.head->next;
	int length2 = 0;
	while(l != listB.head){
		length2++;
		l = l->next;
	}
	l = listB.head->next;

	if(length1 != length2){
		return false;
	}
	while(d != head){
		if(d->value != l->value){
			return false;
		}
		d = d->next;
		l = l->next;
	}
	return true;

}
