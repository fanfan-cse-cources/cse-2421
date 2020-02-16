/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void fileOutput_12(char *op, Node **list_head_ptr) {
	FILE *output_file;
	unsigned int node_counter;
    unsigned int i = 0;
    Node *n = *list_head_ptr;

	output_file = fopen(op, "w");
	if (output_file == NULL) {
		perror(op);
		exit(EXIT_FAILURE);
	}

    while (n != NULL) {
    	fprintf(output_file, "%s\n", n -> grocery_item.item);
    	fprintf(output_file, "%s\n", n -> grocery_item.department);
    	fprintf(output_file, "%u\n", n -> grocery_item.stockNumber);
    	fprintf(output_file, "%.2f\n", n -> grocery_item.pricing.wholesalePrice);
    	fprintf(output_file, "%.2f\n", n -> grocery_item.pricing.retailPrice);
    	fprintf(output_file, "%u\n", n -> grocery_item.pricing.wholesaleQuantity);
    	fprintf(output_file, "%u\n", n -> grocery_item.pricing.retailQuantity);

        n = n -> next;
        node_counter++;
    }
    
    if (fclose(output_file) != 0) {
        perror(op);
        exit(EXIT_FAILURE);
    }

    /* 2, 3 - FREE MEMORIES */
    n = *list_head_ptr;
    while (n != NULL) {
        free(n);
        n = n -> next;
        i++;
    }
    /* 1 - FREE MEMORIES */
    free(list_head_ptr);

	printf("A total of %u Grocery Item records were written to file %s\n\n", node_counter, op);

}