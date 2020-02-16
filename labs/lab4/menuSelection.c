/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

/* THIS METHOD WILL RETURN A VALID OPTION */
unsigned int menuSelection() {
	unsigned int option;
	unsigned int fail_counter;

	printf("Please enter an integer between 1 and 12 to select an operation on the data: \n");
	printf("1)  Print Total Revenue\n");
	printf("2)  Print Total WholeSale Cost\n");
	printf("3)  Print Current Grocery Item Investment\n");
	printf("4)  Print Current Profit\n");
	printf("5)  Print Total Number of Grocery Items Sold\n");
	printf("6)  Print Average Profit per Grocery Item\n");
	printf("7)  Print Grocery Items In Stock\n");
	printf("8)  Print Out of Stock Grocery Items\n");
	printf("9)  Print Grocery Items for a Department\n");
	printf("10) Add Grocery Item to Inventory\n");
	printf("11) Delete Grocery Item from Inventory\n");
	printf("12) Exit Program\n\n");
	printf("Option: ");
	/* first attempt */
	scanf("%u", &option);

	/* two attempt, after first invalid attempt */
	fail_counter = 0;
	while (option > 12 && fail_counter < 2) {
		printf("Invalid Option.\n");
		printf("Option: ");
		scanf("%u", &option);
		fail_counter++;
	}
	if (fail_counter > 3) {
		return -1;
	}

	return option;
}