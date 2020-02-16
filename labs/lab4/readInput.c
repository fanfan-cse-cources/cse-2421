/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

void readInput(char *ip, Node **list_head) {
	FILE *input_file;
	Node *newNodePtr = NULL;
	unsigned int node_counter = 0;

	input_file = fopen(ip, "r");
	if (input_file == NULL) {
		perror(ip);
		exit(EXIT_FAILURE);
	}

	/* 2 - ALLOCATE MEMORY FOR FIRST NODE */
	newNodePtr = calloc(1, sizeof(Node));

	/* populate Nodes from file */
	while (fscanf(input_file, " %[^\n]", &(newNodePtr -> grocery_item.item)) != EOF) {
		fscanf(input_file, " %[^\n]", &(newNodePtr -> grocery_item.department));
		fscanf(input_file, "%i", &(newNodePtr -> grocery_item.stockNumber));
		fscanf(input_file, "%f", &(newNodePtr -> grocery_item.pricing.wholesalePrice));
		fscanf(input_file, "%f", &(newNodePtr -> grocery_item.pricing.retailPrice));
		fscanf(input_file, "%i", &(newNodePtr -> grocery_item.pricing.wholesaleQuantity));
		fscanf(input_file, "%i", &(newNodePtr -> grocery_item.pricing.retailQuantity));
		
		/* insert node function */
		insertNode(list_head, newNodePtr);

		/* 3 - ALLOCATE MEMORY FOR NEXT NODE */
		newNodePtr = calloc(1, sizeof(Node));

		node_counter++;
	}

	printf("Reading inventory from file \"%s\"\n", ip);
	printf("A total of %u grocery items were read in to inventory from %s\n\n", node_counter, ip);

	if (fclose(input_file) != 0) {
        perror(ip);
        exit(EXIT_FAILURE);
    }

    free(newNodePtr);

}