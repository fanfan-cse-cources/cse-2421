/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void printByDepartment_9(Node **list_head_ptr) {
	char department[30];
    unsigned int flag = 0;
    Node *n = *list_head_ptr;

	printf("Print items by department: ");
	scanf(" %[^\n]", &department);

	printf("\nGrocery Item for %s: \n\n", department);

    while (n != NULL) {
        if (strcasestr(n -> grocery_item.department, department)) {
        	if (flag == 0) {
                printf("Stock#\tQuantity\tDepartment\tItem\n");
            }
            printf("%u\t%u\t\t%-10s\t%-10s\n", 
                n -> grocery_item.stockNumber, 
                (n -> grocery_item.pricing.wholesaleQuantity) - (n -> grocery_item.pricing.retailQuantity), 
                n -> grocery_item.department, 
                n -> grocery_item.item);
            flag++;
        }
        
        n = n -> next;
    }

    if (flag == 0) {
        printf("\tThere are no Grocery Items for %s\n", department);
    }
    
}