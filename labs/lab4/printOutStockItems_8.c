/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void printOutStockItems_8(Node **list_head_ptr) {
    unsigned int flag = 0;
    Node *n = *list_head_ptr;

    printf("Out of Stock Grocery Item List: \n");

    while (n != NULL) {
        if ((n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity) == 0) {
            if (flag == 0) {
                printf("Stock#\tQuantity\tDepartment\tItem\n");
            }
            printf("%u\t%u\t\t%s\t\t%s\n", 
                n -> grocery_item.stockNumber, 
                (n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity), 
                n -> grocery_item.department, 
                n -> grocery_item.item);
            flag++;
        }
        
        n = n -> next;
    }
    
    if (flag == 0) {
        printf("\tThere are currently no Out of Stock Grocery Items\n");
    }
    printf("\n\n");

}