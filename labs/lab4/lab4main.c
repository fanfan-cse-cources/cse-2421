 /*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab4.h"

int main(int argc, char *argv[]) {
	int i;
	unsigned int selection;
	Node **list_head = NULL;
	Node *n = NULL;
	void (*fun_array[])(Node **) = {totalRevenue_1, totalWholesaleCost_2, 
								totalWholesaleInvestment_3, totalProfit_4,
								totalGroceryItemsSold_5, averageProfit_6,
								printInStockItems_7, printOutStockItems_8,
								printByDepartment_9, addGroceryItem_10,
								deleteGroceryItem_11
							};

	if (argc != 3) {
		printf("%s: invalid option\n", argv[0]);
		printf("Useage: %s [filename1] [filename2]\n", argv[0]);
		printf("\tfilename1: data file that contains current inventory information to read in\n");
		printf("\tfilename2: data file that output inventory\n");

		return 0;
	}

	/* 1 - ALLOCATE MEMORY FOR POINTER */
	list_head = calloc(1, sizeof(Node *));
	readInput(argv[1], list_head);

	/* menuSelection() WILL RETURN A VALID OPTION */
	selection = menuSelection();
	/* option 1 to 12 */
	while (selection < 13) {
		/* when calling fun_array, -1 is required since our array started from 0 */
		if (selection < 12) {
			fun_array[selection - 1](list_head);
			printf("\n");
		}
		/* other options */
		switch (selection) {
			/* exit value after user ran out of 3 attempts */
			case -1:
				return 0;
			case 12:
				fileOutput_12(argv[2], list_head);
				return 0;
		}

		/* UNTIL selection == 12 or selection == -1 */
		selection = menuSelection();
	}

	return 0;
}