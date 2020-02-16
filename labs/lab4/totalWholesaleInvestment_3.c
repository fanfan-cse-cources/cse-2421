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

void totalWholesaleInvestment_3(Node **list_head_ptr) {
	float totalWholesaleInvestment = 0.0;
    Node *n = *list_head_ptr;

    while (n != NULL) { 
        totalWholesaleInvestment += (n -> grocery_item.pricing.wholesalePrice) * 
        							((n -> grocery_item.pricing.wholesaleQuantity) - 
        							(n -> grocery_item.pricing.retailQuantity));

        n = n -> next;
    }

    setlocale(LC_NUMERIC,"");
    printf("Total profit: $%'.2f\n", totalWholesaleInvestment);
    
}