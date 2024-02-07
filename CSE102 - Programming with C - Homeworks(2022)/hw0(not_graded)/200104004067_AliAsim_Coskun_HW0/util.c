#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
	if(denominator == 0 && numerator == 0)
		printf("ERROR! an indefinite number: ");
	else if(denominator == 0)
		printf("ERROR! an undefined number: ");

	printf("%d//%d", numerator, denominator);

	if(numerator == 0 && denominator != 0)
		printf(" equals zero.");
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*d2 + n2*d1;
	*d3 = d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*d2 - n2*d1;
	*d3 = d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*n2;
	*d3 = d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*d2;
	*d3 = d1*n2;
	fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
	int i, gcd, dcounter=0, ncounter=0;
	/* We should randomly value 'specialcase1' and 'speacialcase2'. Otherwise, the program fails. */
	/* On the other hand, the values we give shouldn't be positive. Otherwise, things get messy. */
	int specialcase1=-2, specialcase2=-1;

	/* if the denominator is zero as a result of operation: specialcase1 (explained at '115') */
	if((*d == 0) && (*n != 0))
	{
		gcd = specialcase1;
	}
	/* if the numerator is zero as a result of operation: specialcase2 (explained at '122') */
	else if((*n == 0) && (*d != 0))
	{
		gcd = specialcase2;
	}

	/* I turn the negative number into positive for a while to do the GCD operation. */
	/* I added counter to restore this operation later */
	if(*d<0)
	{
		*d = *d*(-1);
		dcounter++;
	}
	if(*n<0)
	{
		*n = *n*(-1);
		ncounter++;
	}

	/* this is where we start the GCD operation */
	/* starting with the smaller number, we decrease counter(i) and we break the loop at the first divisible number. */
	if(*d>*n)
	{
		for(i=*n;i>0;i--)
		{
			if(*n%i == 0 && *d%i == 0)
			{
				gcd = i;
				break;
			}
		}
	}
	else if(*n>*d)
	{
		for(i=*d;i>0;i--)
		{
			if(*n%i == 0 && *d%i == 0)
			{
				gcd = i;
				break;
			}
		}
	}
	/* if the two numbers are equal to each other, the GCD is equal to itself */
	else
	{
		gcd = *d;
	}/* the end of the GCD operation. */
	
	/* we turn 'the number which we made positive' back to its original state */
	if(ncounter == 1)
		*n = *n * (-1);
	if(dcounter == 1)
		*d = *d * (-1);

	/* We divide the numerator and denominator into the greatest common divisor(GCD) and the simplification process is completed. */
	/* But we have an exception. That's because both numbers are 0(zero). In this case, the gcd 0 is coming out. */
	/* Therefore, we specify that if the gcd is zero, both numbers should be zero. so, we don't need to simplify it. */
	if(gcd == 0)
	{
		*n = 0;
		*d = 0;
	}
	/* specialcase1: if the denominator equals zero, it should be zero and the numerator should be same. */
	/* so, we don't need to simplify it. */
	else if(gcd == specialcase1)
	{
		*d = 0;
		*n = *n;
	}
	/* specialcase2: if the numerator equals zero, it need to be zero and the denominator need to be same. */
	/* so, we don't need to simplify */
	else if(gcd == specialcase2)
	{
		*n = 0;
		*d = *d;
	}
	/* If there is no one of the above 3 special cases, the simplification is done: */
	else
	{
		*n = (*n/gcd);
    		*d = (*d/gcd);		
	}
} /* end fraction_simplify */
