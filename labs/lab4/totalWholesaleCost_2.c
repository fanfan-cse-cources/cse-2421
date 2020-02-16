/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void totalWholesaleCost_2(Node **list_head_ptr) {
	float totalWholesaleCost = 0.0;
    Node *n = *list_head_ptr;

    while (n != NULL) { 
        totalWholesaleCost += (n -> grocery_item.pricing.wholesalePrice) * 
        					  (n -> grocery_item.pricing.wholesaleQuantity);

        n = n -> next;
    }

    setlocale(LC_NUMERIC,"");
    printf("Total wholsesale cost: $%'.2f\n", totalWholesaleCost);
    
}