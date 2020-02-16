/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

/* THIS METHOD DOES NOT CHECK EXISTENCE */
void deleteNode(Node **list_head_ptr, int stockNumber) {
	/* Node **traversePtr = &(*list_head_ptr) -> next; */
	Node *currentNode = *list_head_ptr;
	Node *priorNode;

    if (currentNode != NULL && currentNode -> grocery_item.stockNumber == stockNumber) { 
        *list_head_ptr = currentNode -> next;
        /* 2 - FREE MEMORIES */
        free(currentNode);
        return; 
    } 
  
    while (currentNode != NULL && currentNode -> grocery_item.stockNumber != stockNumber) { 
        priorNode = currentNode; 
        currentNode = currentNode -> next; 
    } 
  
    if (currentNode == NULL) {
    	printf("\nUnable to DELETE this Node: Stock# does not exist\n");
    	return;
    }
  
    priorNode -> next = currentNode -> next; 
    /* 2 - FREE MEMORIES */
    free(currentNode);
    
}