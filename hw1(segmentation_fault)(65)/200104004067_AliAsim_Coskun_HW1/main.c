#include <stdio.h>
#include "util.h"

int main()
{
	int x, y, z, f_I, m, n;
	/*  */
	printf("========================PART1========================\n");
	/* x: first integer */
	printf("Enter the first integer: ");
	scanf("%d", &x);
	/* y: second integer */
	printf("Enter the second integer: ");
	scanf("%d", &y);
	/* z: divisor */
	printf("Enter the divisor: ");
	scanf("%d", &z);
	/* f_I: the first Integer between x and y */
	f_I = find_divisible(x, y, z);
	/* we'll use 'm' as a result of this function. */
	m = find_nth_divisible(n, f_I, z);
	/* if first function's return's not equal to -1: */
	if(f_I!=-1)
	{
		printf("The first integer between %d and %d divided by %d is %d", x, y, z, f_I);
		printf("\n");
		/* n: that helps us to show (n+1)th number */
		printf("Enter the number how many text: ");
		scanf("%d", &n);
		/* I opened 4 separate "if-else"s for 'firST', 'secoND' and 'thiRD' cases. */
		if(n==0)
		{/* in this case, it doesn't change.*/
			printf("The result is the same: \nThe first integer between %d and %d divided by %d is %d\n", x, y, z, f_I);
		}
		else if(n==1)
		{/* '2nd' situation */
			m = find_nth_divisible(n, f_I, z);
			if(m<y && m>x)
				printf("The 2nd integer between %d and %d divided by %d is %d\n", x, y, z, m);
			else
				printf("No possible to find 2nd divisible between %d and %d divided by %d\n", x, y, z);
		}
		else if(n==2)
		{/* '3rd' situation */
			m = find_nth_divisible(n, f_I, z);
			if(m<y && m>x)
				printf("The 3rd integer between %d and %d divided by %d is %d\n", x, y, z, m);
			else
				printf("No possible to find 3rd divisible between %d and %d divided by %d\n", x, y, z);
		}
		else
		{/* if 'm' is between first(x) and last integer(y), it works. otherwise "else" works. */
			m = find_nth_divisible(n, f_I, z);
			if(m<y && m>x)
				printf("The %dth integer between %d and %d divided by %d is %d\n", n+1, x, y, z, m);
			else
				printf("No possible to find %dth divisible between %d and %d divided by %d\n", n+1, x, y, z);
		}
	}
	else/* if first function's return's equal to -1: */
		printf("There is NOT any integer between %d and %d can be divided by %d\n", x, y, z);

//------------------------------------------------------------------------
	/* "a, b, c, d" are functions. */
	int a, b=2, password, c, d;
	char identity_number[11];
	float cash_amount;
	printf("\n========================PART2========================\n");
	printf("Enter your TR Identity Numbers: ");
	scanf("%s", identity_number);
	/* THESE ARE THE FUNCTIONS:
	a = validate_identity_number(identity_number);
	b = create_customer(identity_number, password);
	c = check_login(identity_number, password);
	d = withdrawable_amount(cash_amount);
	*/
	a = validate_identity_number(identity_number);
	/* and these are actions that are performed according to their 'return' values(0 and 1). */
	if(a==0)
	{
		printf("INCORRECT!\n");
	}
	if(a==1)
	{
		printf("acceptable!\n");
		printf("Enter the password: ");
		scanf("%d", &password);
		b = create_customer(identity_number, password);
	}

	if(b==0)
	{
		printf("INCORRECT!\n");
	}
	if(b==1)
	{
		printf("thank you!\n");
		printf("\n========================PART3========================\n");
		printf("Enter your identity number: ");
		scanf("%s", identity_number);
		printf("Enter your password: ");
		scanf("%d", &password);
		c = check_login(identity_number, password);
	}

	if(c==0 && a==1 && b==1)
		printf("\"Invalid identity number or password\"\n");
	if(c==1 && a==1 && b==1)
	{
		printf("\"Login Successful\"\n");
		printf("Enter your withdraw amount: ");
		scanf("%f",&cash_amount);
		d = withdrawable_amount(cash_amount);
	}

	if(d==0 && a==1 && b==1 && c==1)
	{
		printf("Sorry, you can't withdraw any money.\n");
	}
	if(d!=0 && c==1 && a==1)
	{
		printf("Withdrawable amount is: %d\n", d);
	}	
	return 0;
}
