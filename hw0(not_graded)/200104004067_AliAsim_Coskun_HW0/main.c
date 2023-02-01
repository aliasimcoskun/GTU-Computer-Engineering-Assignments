#include <stdio.h>
#include "util.h"


int main() {
	
	/* A fractional number: 13/7 */
	int num1 = 13, den1 = 7;
	/* A fractional number: 13/7 */
	int num2 = 30, den2 = 11;
	/* An unitilized fractional number */
	int num3, den3;

	printf("First number: ");
	fraction_print(num1, den1);
	printf("\n");

	printf("Second number: ");
	fraction_print(num2, den2);
	printf("\n");

	printf("Addition: ");
	fraction_add(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Subtraction: ");
	fraction_sub(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Multiplication: ");
	fraction_mul(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Division: ");
	fraction_div(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	/* We reset the numbers for the next example. */

	printf("\nHi! You need to enter two fractional numbers.\n");
	printf("\nfirst number's numerator: ");
	scanf("%d", &num1);
	printf("\nfirst number's denominator: ");
	scanf("%d", &den1);
	printf("\nsecond number's numerator: ");
	scanf("%d", &num2);
	printf("\nsecond number's denominator: ");
	scanf("%d", &den2);

	/* A denominator cannot be zero. So, choose another number.*/
	while((den1 == 0) || (den2 == 0))
	{
		if(den1 == 0)
		{
			printf("\nfirst number is undefined. please enter another number for 1st denominator: ");
			scanf("%d", &den1);
		}
		if(den2 == 0)
		{
			printf("\nsecond number is undefined. please enter another number for 2nd denominator: ");
			scanf("%d", &den2);
		}
	}

	/* These are the results */
	printf("First number: ");
	fraction_print(num1, den1);
	printf("\n");

	printf("Second number: ");
	fraction_print(num2, den2);
	printf("\n");

	printf("Addition: ");
	fraction_add(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Subtraction: ");
	fraction_sub(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Multiplication: ");
	fraction_mul(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Division: ");
	fraction_div(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	return(0);
}
