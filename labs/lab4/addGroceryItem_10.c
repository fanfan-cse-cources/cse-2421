/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void addGroceryItem_10(Node **list_head_ptr) {
    unsigned int fail_counter = 0;
    int duplicate;
    /* 2 - ALLOCATE MEMORY FOR NEXT NODE */
	Node *newNodePtr = calloc(1, sizeof(Node));
    Node *n = *list_head_ptr;

    /* promote user enter data */
    printf("Grocery Item: ");
    scanf(" %[^\n]", &(newNodePtr -> grocery_item.item));
    printf("Grocery Store Department: ");
    scanf(" %[^\n]", &(newNodePtr -> grocery_item.department));
    printf("Stock number: ");
    scanf("%i", &(newNodePtr -> grocery_item.stockNumber));
    printf("Wholesale price of the item in dollars: ");
    scanf("%f", &(newNodePtr -> grocery_item.pricing.wholesalePrice));
    printf("Retail price of the item in dollars: ");
    scanf("%f", &(newNodePtr -> grocery_item.pricing.retailPrice));
    printf("Wholesale quantity purchased by this store: ");
    scanf("%i", &(newNodePtr -> grocery_item.pricing.wholesaleQuantity));
    printf("Retail quantity purchased by customers: ");
    scanf("%i", &(newNodePtr -> grocery_item.pricing.retailQuantity));

    duplicate = checkDuplicateStock(list_head_ptr, newNodePtr);

    while (duplicate == -1 && fail_counter != 3) {
        printf("\nDuplicate Stock number\n");
        printf("Stock number: ");
        scanf("%i", &(newNodePtr -> grocery_item.stockNumber));
        duplicate = checkDuplicateStock(list_head_ptr, newNodePtr);
        if (duplicate == -1) {
            fail_counter++;
        }
    }

    if (duplicate == -1 && fail_counter == 3) {
        printf("\nUnable to add this Node: Duplicate Stock number\n");
        /* 2 - FREE MEMORIES */
        free(newNodePtr);
        newNodePtr = NULL;
    } else {
        /* the insertNode method CAN ADD any duplicate items for flexibility */
        insertNode(list_head_ptr, newNodePtr);
        printf("\nItem \"%s\" added\n", newNodePtr -> grocery_item.item);
    }
    
}