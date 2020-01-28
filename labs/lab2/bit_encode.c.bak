/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>

/* Author: Yifan Yao.740 */
int main(void) {
	/* Variables */
	int clearText;
	int getchar_return_value;
	char keyboard_value[200];
	int charCounter;
	int i; /* counter for loop */
	const int hexValue[] = {0x88, 0x44, 0x22, 0x11}; /* hex value for 10001000, 01000100, 00100010, 00010001 */
	int internalKeyValue;

#ifdef PROMPT
	printf("enter cleartext: "); /* prompt user input */
#endif
	
	scanf("%u", &clearText); /* get text */

	/* convert text into char array */
	while(getchar_return_value != '\n') {
		getchar_return_value = getchar();
		keyboard_value[charCounter] = getchar_return_value;
		charCounter++;
	}
	/* remove the extra 1 from counter */
	charCounter--;

#ifdef PROMPT
	printf("Text entered is: %s", keyboard_value);

	printf("Hex encoding is: \n");
	i = 0;
	while(i < charCounter) {
		printf("%02X ", keyboard_value[i]);
		i++;
		/* start a new line when 10 value printed */
		if(i % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	printf("enter 4-bit key: ");
#endif

	/* get internal key */
	internalKeyValue = 0;
	for(i = 0; i < 4; i++) {
		getchar_return_value = getchar();
		/* when user input 1, it will convert to a 8-bit key */
		/* for instance, 1100 -> 10001000 | 01000100 = 11001100 */
		if (getchar_return_value != EOF && getchar_return_value == '1') {
			internalKeyValue = internalKeyValue | hexValue[i];
		}
	}

#ifdef PROMPT
	printf("hex ciphertext: \n");
#endif

	/* output final result */
	i = 0;
	while(i < charCounter) {
		printf("%02X ", keyboard_value[i] ^ internalKeyValue);
		i++;

#ifdef PROMPT
		/* start a new line when 10 value printed */
		if(i % 10 == 0) {
			printf("\n");
		}
#endif

	}
	printf("\n");
}
