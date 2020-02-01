/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdlib.h>
#include <stdio.h>
/* Author: Yifan Yao.740 */
#include "lab3.h"

char *readtitles(void) {
	char *titles;
	
	titles = calloc(61, sizeof(char));
	scanf(" %[^\n]", titles);

	return (titles);
}
