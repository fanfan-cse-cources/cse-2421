/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

/* THIS METHED DOES NOT CHECK REDUNDANCY */
void insertNode(Node **list_head_ptr, Node *newNodePtr) {
	Node *current;

	if (*list_head_ptr == NULL || (*list_head_ptr) -> grocery_item.stockNumber >= newNodePtr -> grocery_item.stockNumber) {
		*list_head_ptr = newNodePtr;
		
		newNodePtr -> next = NULL;
	} else {
		current = *list_head_ptr;
		while (current -> next != NULL && current -> next -> grocery_item.stockNumber < newNodePtr -> grocery_item.stockNumber) { 
            current = current -> next; 
        }

        newNodePtr -> next = current->next; 
        current -> next = newNodePtr;
	}
	
}