/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab3.h"

int savedata(char fileName[255], unsigned int numOfBooks, char **bookList, unsigned int numOfFavBooks, char ***favBooks) {
	FILE *output_file;
	int i;

	/* open file output stream */
	output_file = fopen(fileName, "w");
	if(output_file == NULL) {
		perror("ERROR with fopen");
		exit(EXIT_FAILURE);
	}

	/* output result as a file */
	fprintf(output_file, "Books I\'ve read: \n");
	for(i = 0; i < numOfBooks; i++) {
		fprintf(output_file, "%s\n", *(bookList + i));
	}

	fprintf(output_file, "\n\n");

	fprintf(output_file, "My Favorites are: \n");
	for(i = 0; i < numOfFavBooks; i++) {
		fprintf(output_file, "%s\n" , **(favBooks + i));
	}

	/* close file output stream */
	if(fclose(output_file) != 0) {
		perror("ERROR with fclose");
		exit(EXIT_FAILURE);
	}

	return 0;
}
