/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>
#include <stdlib.h>
/* Author: Yifan Yao.740 */
#include "lab3.h"

int main(void) {
	int i;
	unsigned int numOfBooks;
	unsigned int numOfFavBooks;
	char fileName[255];
	char **bookList;
	char ***favBooks;

	printf("How many library book titles do you plan to enter? ");
	scanf("%u", &numOfBooks);

	/* (MEMORY ALLOCATED - 1) memories for bookList */
	bookList = calloc(numOfBooks, sizeof(char *));

	printf("Enter the %i book titles one to a line: ", numOfBooks);
	for(i = 0; i < numOfBooks; i++) {
		/* (MEMORY ALLOCATED - 2) memories for each book */
		*(bookList + i) = readtitles();
	}

	/* return each book */
	printf("\nYou’ve entered: \n");
	for(i = 0; i < numOfBooks; i++) {
		printf("%i. %s\n", i + 1, *(bookList + i));
	}

	printf("\nOf those %i books, how many do you plan to put on your favorites list? ", numOfBooks);
	scanf("%u", &numOfFavBooks);

	/* (MEMORY ALLOCATED - 3) memories for favBook */
	favBooks = calloc(numOfFavBooks, sizeof(char *));

	printf("Enter the number next to each book title you want on your favorites list: ");
	for(i = 0; i < numOfFavBooks; i++) {
		int p;

		scanf("%i", &p);
		*(favBooks + i) = bookList + p - 1;
	}

	/* return favorite books */
	printf("\nThe books on your favorites list are: \n");
	getfavorites(numOfFavBooks, favBooks);

	/* promote user to save results as a file */
	printf("\nDo you want to save them (1=yes, 2=no): ");
	scanf("%u", &i);
	if (i == 1) {
		printf("What file name do you want to use? ");
		scanf(" %[^\n]", &fileName);
		savedata(fileName, numOfBooks, bookList, numOfFavBooks, favBooks);
		printf("Your booklist and favorites have been saved to the file %s.\n", fileName);
	} else {
		printf("file not saved\n");
	}

	/**
	 * steps for put my toys back (free the memory):
	 * 1. favBooks (holds address for each favBook)
	 * 2. each thing in the bookList (holds each book address)
	 * 3. bookList (holds address for books)
	**/
	/* (MEMORY FREED - 3) memories for favBooks */
	free(favBooks);

	/* (MEMORY FREED - 2) memories for each book */
	for(i = 0; i < numOfBooks; i++) {
		if(*(bookList + i) != NULL) {
			free(*(bookList + i));
		}
	}

	/* (MEMORY FREED - 1) memories for bookList */
	free(bookList);

	return 0;
}
