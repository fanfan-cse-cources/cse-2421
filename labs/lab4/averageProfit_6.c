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

void averageProfit_6(Node **list_head_ptr) {
  float averageProfit = 0.0;
	float totalProfit = 0.0;
	int totalGroceryItemsSold = 0;
  Node *n = *list_head_ptr;

    while (n != NULL) { 
        /* 
          RECALCULATED PROFIT
          totalProfit = retailQuantity * (retailPrice - wholesalePrice)
         */
        totalProfit += (n -> grocery_item.pricing.retailQuantity) * 
                       ((n -> grocery_item.pricing.retailPrice) - 
                       (n -> grocery_item.pricing.wholesalePrice));
        totalGroceryItemsSold += (n -> grocery_item.pricing.retailQuantity);
        
        n = n -> next;
    }

  averageProfit = totalProfit / totalGroceryItemsSold;
  setlocale(LC_NUMERIC,"");
  printf("Average Profit: $%'.2f\n", averageProfit);
  
}