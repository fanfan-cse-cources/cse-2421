/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

int checkDuplicateStock(Node **list_head_ptr, Node *newNodePtr) {
	Node *n = *list_head_ptr;

	while (n != NULL) {
		/* IF THERE EXIST A DUPLICATED STOCK NUMBER, flag++ */
		if ((n -> grocery_item.stockNumber) == (newNodePtr -> grocery_item.stockNumber)) {
    	    return -1;
    	}

        n = n -> next;
    }

    return 0;
}