/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void totalGroceryItemsSold_5(Node **list_head_ptr) {
	int totalGroceryItemsSold = 0;
    Node *n = *list_head_ptr;

    while (n != NULL) { 
        totalGroceryItemsSold += (n -> grocery_item.pricing.retailQuantity);
        
        n = n -> next;
    }

    printf("Total number of grocery items sold: %i\n", totalGroceryItemsSold);

}