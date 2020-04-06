/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdio.h>

void encode(unsigned char *clear, unsigned char *cipher, int count);

/* Author: Yifan Yao.740 */
int main(void)
{
	/* Variables */
	unsigned char cleartext_in[201];
	unsigned char ciphertext[201];
	int getchar_return_value = 0;
	int count = 0;
	int i = 0;

	printf("enter cleartext: "); /* prompt user input */
	scanf("%u", &cleartext_in); /* get text */

	/* convert text into char array */
	while(getchar_return_value != '\n')
	{
		getchar_return_value = getchar();
		cleartext_in[count] = getchar_return_value;
		count++;
	}
	/* remove the extra 1 from counter */
	count--;

	printf("Text entered is: %s", cleartext_in);
	printf("Hex encoding is: \n");

	while(i < count) 
	{
		printf("%02X ", cleartext_in[i]);
		i++;
		/* start a new line when 10 value printed */
		if(i % 10 == 0) 
		{
			printf("\n");
		}
	}
	printf("\n");

	encode(cleartext_in, ciphertext, count);

	/* print result */
	printf("hex ciphertext: \n");
	i = 0;
	while(i < count) 
	{
		printf("%02X ", ciphertext[i]);
		i++;
		if(i % 10 == 0) 
		{
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
