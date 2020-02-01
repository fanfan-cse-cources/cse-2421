/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
/* Author: Yifan Yao.740 */
#include "lab3.h"

int getfavorites(unsigned int numOfFavBooks, char ***favBooks) {
	int i;
	
	for(i = 0; i < numOfFavBooks; i++) {
		printf("%i. %s\n", i + 1, **(favBooks + i));
	}

	return 0;
}
