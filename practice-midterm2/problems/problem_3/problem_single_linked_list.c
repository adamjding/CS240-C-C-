#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Initialize the linked list

{
        list->head = NULL;


// Prints the linked list

        
        ListNode * e;

        if (list->head == NULL) {
                printf("{EMPTY}\n");

        }



        e = list->head;

                printf("%d", e->value);
                e = e->next;

                        printf(", ");
                }

        printf("}\n");
}

// Problem ( 1/4 ) 
/******************************************************************************

 *
 * Parameters: list -- find the number of elements contained in this single

 *
 * Return: the number of elements 

 * Return Type: integer
 *****************************************************************************/

    // Write Your Code Here
	int elements = 0;

	while(p != NULL){
		elements++;

	}
	return elements;


// Problem ( 2/4 ) 

 /** TODO: Create a new ListNode and add it to the end of the single linked
 * 	 list. There is no check if the value exists in the list. 

 * Parameters: list -- The single linked list to which you will insert the new
 * 		       ListNode to the end of.

 *
 * Return: void

 * Return Type: void
 *****************************************************************************/

    // Write Your Code Here
	ListNode *n = (ListNode*)malloc(sizeof(ListNode));

	ListNode *p = list->head;
	

		n->next = list->head;
		list->head = n;

	}
	while(p->next != NULL){

	}
	p->next = n;


// Problem ( 3/4 )

/* * TODO: Remove the ith entry from the single linked list.   	 
 * 

 * 		       the listNode from.
 * 	       ith -- The index where you will remove the listNode from the

 *
 * Return: Return 1 if the ListNode is removed.
 * 	   Return 0 if the ith entry does not exist in the list or the list is
 * 	   empty.


 *****************************************************************************/
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode *p = list->head;
	ListNode *prev = NULL;
	int counter = 0;
	while(p != NULL){
		if(counter == ith){
			break;
		}
		counter++;
		prev = p;
		p = p->next;

	}
	if(p == NULL)
		return 0;
	if(prev == NULL)	
		list->head = p->next;
	else
		prev->next = p->next;
	free(p);
	return 1;
}


/******************************************************************************
 * TODO: Iterate through list1 and list2. Check if any values intersect between

 *       to list3. Use the function llist_add(LinkedList * list, int value)
 *       to add a value to the list.

 * Parameters: list1 -- singled linked list, find values that intersect with
 *                      list2

 *                      list1
 *             list3 -- store the intersection of list1 and list2 in this list

 * Return: void 
 *

 *****************************************************************************/
void llist_intersection(LinkedList * list1, LinkedList * list2, LinkedList *list3){

    // Write Your Code Here
	ListNode *p = list1->head;
	ListNode *q = list2->head;
	ListNode *n = (ListNode*)malloc(sizeof(ListNode));
	int length = llist_number_elements(list1);
	int pvals[length];
	int i = 0;
	while(p != NULL){
		pvals[i] = p->value;
		i++;			
		p = p->next;
	}
	while(q != NULL){
		for(int j = 0; j < length; j++){
			if(q->value == pvals[j]){
				llist_add(list3, pvals[j]);
			}
		}
		q = q->next;
	}
	
}
