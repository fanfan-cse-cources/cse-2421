/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void printInStockItems_7(Node **list_head_ptr) {
    Node *n = *list_head_ptr;

    printf("In Stock Grocery Item List: \n\n");
    printf("Stock#\tQuantity\tDepartment\tItem\n");

    while (n != NULL) {
        if ((n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity) > 0) {
            printf("%u\t%u\t\t%-10s\t%-10s\n", 
                n -> grocery_item.stockNumber, 
                (n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity), 
                n -> grocery_item.department, 
                n -> grocery_item.item);
        }
        
        n = n -> next;
    }
    printf("\n\n");

}