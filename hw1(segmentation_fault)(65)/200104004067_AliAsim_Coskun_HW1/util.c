#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z)
{
	int i, f_I=0;
	/* y must be greater than x */
	if(x<y)
	{	/* i must be start at 'x+1'. otherwise, f_I can be equal to x. */
		for(i=x+1;i<y;i++)
		{
			if(i%z==0)
			{/* we need to equalize 'the number' to f_I which 'the first number divided by z' */
				f_I=i;
				break;
			}
		}
		if(f_I==0)
		{/* if f_I has not changed: */
			return -1;
		}
	}
	else
	{/* if x greater than y: */
		return -1;
	}
	return f_I;
}

int find_nth_divisible(int n, int f_I, int z)
{
	n = n * z; /* In this line, we calculate the number that need to be added to f_I(first divisible integer). */ 
	n = f_I + n; /* And in this line, we add that number to f_I and we find the result. */
	return n; /* We return the 'result'. */
}

int validate_identity_number(char identity_number [])
{
	int i, odd, even;

	if(identity_number[0]=='0')
	{/* If the first digit of identity number is 0, give an error. */
		return 0;
	}
	for(i=0;i<11;i++)
	{/* If the first 11 digits of the string have any characters except the numbers, give an error. */
		if(!(identity_number[i]<='9' && '0'<=identity_number[i]))
		{
			return 0;
		}
	}
	if(identity_number[11]!='\0')
	{/* If the 12th digit of the string is not 'NULL', give an error. */
		return 0; /* it means that the length of the string must be 11 digits. */
	}
	for(i=0;i<11;i++)
	{/* We extract 48 from all elements of char string and convert them into integers. */
		identity_number[i] = identity_number[i] - 48;
	}
	/* odd: sum of elements 1, 3, 5, 7 and 9 of the string. */
	/* even: sum of elements 2, 4, 6 and 8 of the string. */
	odd = identity_number[0] + identity_number[2] + identity_number[4] + identity_number[6] + identity_number[8];
	even = identity_number[1] + identity_number[3] + identity_number[5] + identity_number[7];
	/* article 4 of the rules */
	if((odd*7 - even) % 10 != identity_number[9])
	{/* if it does not comply with article 4 of the rule, we return 0. */
		return 0;
	}
	else if((odd + even + identity_number[9]) % 10 != identity_number[10])
	{/* article 5 of the rules */
		return 0;/* if it does not comply with article 5 of the rule, we return 0. */
	}
	else
	{/* if it complies with all the rules, we return 1. */
		return 1;
	}
}

int create_customer(char identity_number [], int password)
{
	int i;

	if(password<1000 || 9999<password)
	{ /* if the password is not 4 digits, we return 0. */
		return 0;
	}

	for(i=0;i<11;i++)
	{/* we reconvert the string to its normal state. (integer to char) */
		identity_number[i] = identity_number[i] + 48;
	}
	/* we do "file" operations. */
	FILE *txt;
	/* we open the txt in write mode. So, every time we run the code, it will be deleted and re-created. */
	txt=fopen("customeraccount.txt", "w");
	/* it prints the identity number and password to the customeraccount.txt. */
	fprintf(txt, "%s,%d", identity_number, password);
	fclose(txt); /* it closes the file. */
	
	return 1;
}

int check_login(char identity_number [], int password)
{
	int i;
	/* we create an useless char for comma */
	char comma;
	/* we create a char string to compare with identity number. */
	char check_identity[11];
	/* we create a integer to compare with password. */
	int check_pass;

	FILE *txt;
	if((txt=fopen("customeraccount.txt","r"))!=NULL)
	{
		for(i=0;i<11;i++)
		{/* this loop reads the identity number from the customeraccount.txt and compares it! */
			fscanf(txt,"%c",&check_identity[i]);
			/* It compares the one in the txt with the one received from the user and if it is different, gives an error . */
			if(check_identity[i]!=identity_number[i])
			{
				fclose(txt); /* we close txt. */
				return 0;
			}
		}
		fscanf(txt,"%c",&comma); /* it reads the comma from the customeraccount.txt. */
		fscanf(txt,"%d",&check_pass); /* it reads the password from the customeraccount.txt. */
		if(check_pass!=password) /* it checks the password */
		{
			fclose(txt); /* we close txt. */
			return 0; /* if it is not same as the password in customeraccount.txt, give an error. */
		}
	}
	else
	{/* if the txt does not open. */
		printf("the txt couldn't be found.");
	}
	fclose(txt); /* we close txt. */
	return 1;
}

int withdrawable_amount(float cash_amount)
{
	int i, temp;
	/* if cash_amount less than 10, we report that you can't withdraw money. */
	if(cash_amount<10)
		return 0;
	else
	{/* if greater than 10: */
		for(i=10;i<=cash_amount;i++)
		{/* we start at 10 and we continue until cash_amount. */
			if(i%10==0)
			{/* we save every number divided by 10 to temp. */
				temp = i;
			}
		}
	}/* we return the last number that we saved. */
	return temp;
}
