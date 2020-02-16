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

void totalProfit_4(Node **list_head_ptr) {
	float totalProfit = 0.0;
    Node *n = *list_head_ptr;

    while (n != NULL) {
        /* 
          RECALCULATED PROFIT
          totalProfit = retailQuantity * (retailPrice - wholesalePrice)
         */
        totalProfit += (n -> grocery_item.pricing.retailQuantity) * 
        			   ((n -> grocery_item.pricing.retailPrice) - 
        			   (n -> grocery_item.pricing.wholesalePrice));

        n = n -> next;
    }

    setlocale(LC_NUMERIC,"");
    printf("Total profit: $%'.2f\n", totalProfit);
    
}