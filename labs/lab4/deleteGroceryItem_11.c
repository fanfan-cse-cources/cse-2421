/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void deleteGroceryItem_11(Node **list_head_ptr) {
	int removeStock;
	Node *n = *list_head_ptr;

    /* print all Nodes for user reference */
    printf("Grocery Item List: \n\n");
    printf("Stock#\tQuantity\tDepartment\tItem\n");

    while (n != NULL) {
        printf("%u\t%u\t\t%-10s\t%-10s\n", 
            n -> grocery_item.stockNumber, 
            (n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity), 
            n -> grocery_item.department, 
            n -> grocery_item.item);
        
            n = n -> next;
    }

    /* promote user enter stock#, if the linked list is not empty */
    if (*list_head_ptr != NULL) {
        printf("DELETE Grocery Item (Stock#): ");
        scanf("%i", &removeStock);

        deleteNode(list_head_ptr, removeStock);
    } else {
        printf("\nUnable to delete this Node: Empty List\n");
    }
    
}