#include <stdio.h>
#include <math.h>

int sum(int n1, int n2, int flag)
{/* in this function we only do the addition OPERATIONS. */
	int i, temp, sum=0;
	switch(flag)
	{
		case 0: /* this flag calculates the sum for even numbers. */
			if(n2<n1)
			{/* n2 must be greater than n1, so if n1>n2 I swapped them. */
				temp = n1;
				n1 = n2;
				n2 = temp;
			}
			if(n1<n2)
			{/* n2 must be greater than n1 */
				for(i=n1+1;i<n2;i++)
				{/* from 1 more of the small number to 1 less of the larger number */
					if(i%2==0)
					{/* for EVEN numbers */
						sum=sum+i;
						printf("%d ",i);
						if(i+1==n2 || i+2==n2) break; /* we use break, so that the last part of the equation cannot be '+=' */
						printf("+ "); /* so, we don't use this sign after break */
					}
				}
			}
			break;
		case 1: /* this flag calculates the sum for odd numbers. */
			if(n2<n1)
			{/* n2 must be greater than n1, so if n1>n2 I swapped them. */
				temp = n1;
				n1 = n2;
				n2 = temp;
			}
			if(n1<n2)
			{/* n2 must be greater than n1 */
				for(i=n1+1;i<n2;i++)
				{/* from 1 more of the small number to 1 less of the larger number */
					if((i+1)%2==0)
					{/* for ODD numbers */
						sum=sum+i;
						printf("%d ",i);
						if(i+1==n2 || i+2==n2) break; /* we use break, so that the last part of the equation cannot be '+=' */
						printf("+ "); /* so, we don't use this sign after break */
					}
				}
			}
			break;
		default: /* If flag is not 1 or 0, the function gives an error message. */
			if(sum!=0) printf("Please enter correct input.\n");
	}

	return sum; /* We return the sum of the numbers. */
}

int multi(int n1, int n2, int flag)
{/* in this function we only do the multiplying OPERATIONS. */
	int i, temp, multi=1;
	switch(flag)
	{
		case 0: /* this flag calculates multiplication for even numbers */
			if(n2<n1)
			{/* n2 must be greater than n1, so if n1>n2 I swapped them. */
				temp = n1;
				n1 = n2;
				n2 = temp;
			}
			if(n1<n2)
			{/* n2 must be greater than n1 */
				for(i=n1+1;i<n2;i++)
				{/* from 1 more of the small number to 1 less of the larger number */
					if(i%2==0)
					{/* for EVEN numbers */
						multi=multi*i;
						printf("%d ",i);
						if(i+1==n2 || i+2==n2) break; /* we use break, so that the last part of the equation cannot be '*=' */
						printf("* "); /* so, we don't use this sign after break */
					}
				}
			}
			break;
		case 1: /* this flag calculates multiplication for odd numbers */
			if(n2<n1)
			{/* n2 must be greater than n1, so if n1>n2 I swapped them. */
				temp = n1;
				n1 = n2;
				n2 = temp;
			}
			if(n1<n2)
			{/* n2 must be greater than n1 */
				for(i=n1+1;i<n2;i++)
				{/* from 1 more of the small number to 1 less of the larger number */
					if((i+1)%2==0)
					{/* for ODD numbers */
						multi=multi*i;
						printf("%d ",i);
						if(i+1==n2 || i+2==n2) break; /* we use break, so that the last part of the equation cannot be '*=' */
						printf("* "); /* so, we don't use this sign after break */
					}
				}
			}
			break;
		default: /* If flag is not 1 or 0, the function gives an error message. */
			if(multi!=1) printf("Please enter correct input.\n"); 
	}
	
	return multi; /* we return the product of numbers */
}

void write_file(int number)
{/* this function writes the number to the results.txt file */
	FILE *fp;
	fp = fopen("results.txt", "a+");
	fprintf(fp, "%d ", number);
	fclose(fp);
}

void sum_calculator()
{/* in this function we only get INPUT/OUTPUTS for addition operations. */
	int num1, num2, result, flag;
	/* Using the flag we choose whether it is odd or even */
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers:\n");
	scanf("%d", &flag);
	
	printf("Please enter two different number: \n");
	printf("Number 1: ");
	scanf("%d", &num1);
	printf("Number 2: ");
	scanf("%d", &num2);
	if(num1<0 || num2<0) 
	{/*if n1 or n2 is negative, function gives an error message.*/
		printf("Please enter correct input.\n");
	}
	else
	{/* if it is not negative, then do the operations. */
		printf("Result\n");
		result = sum(num1, num2, flag); /* then we call the SUM function. */
		if(result==0) printf("There is no output.\n");
		else 
		{/* if return is not 0 */
			printf("= %d\n", result);
			write_file(result); /* writes the number to the results.txt file. */
			printf("The result is written to the results.txt file.\n");
		}
	}
}

void multi_calculator()
{/* in this function we only get INPUT/OUTPUTS for multiplying operations. */
	int num1, num2, result, flag;
	/* Using the flag we choose whether it is odd or even */
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers:\n");
	scanf("%d", &flag);
	
	printf("Please enter two different number: \n");
	printf("Number 1: ");
	scanf("%d", &num1);
	printf("Number 2: ");
	scanf("%d", &num2);

	if(num1<0 || num2<0)
	{/*if n1 or n2 is negative, function gives an error message.*/
		printf("Please enter correct input.\n");
	}
	else
	{/* if it is not negative, then do the operations. */
		printf("Result\n");
		result = multi(num1, num2, flag); /* then we call the MULTI function. */
		if(result==1) printf("There is no output.\n");
		else /* if return is not 1 */
		{
			printf("= %d\n", result);
			write_file(result); /* writes the number to the results.txt file. */
			printf("The result is written to the results.txt file.\n");
		}
	}
}

int isprime(int a)
{
	int i, flag=0;
	for(i=2;i<=sqrt(a);i++)
	{/* We set up the loop according to the equation given in the pdf. */
		if(a%i==0) return i; /* If it is a prime number, we return the number that it is divisible by.  */
	}
	return flag; /* If it's a prime number, it doesn't enter the 'if', and we return the flag */
}

void print_file()
{/* this function reads the numbers in the result.txt file and prints them to the terminal. */
	int temp;
	FILE *fp;
	fp = fopen("results.txt","r");
	printf("Result:\n");
	while(fscanf(fp, "%d ",&temp) == 1)
	{
        printf("%d ", temp);
    }
    printf("\n");
    fclose(fp);
}

void txt_to_txt(int m1, int m2, int m3)
{/* this function prints 3 integers to temporary.txt file. */
	FILE *fp2;
	fp2 = fopen("temporary.txt","a+");
	if(m1!=0) fprintf(fp2, "%d ", m1);
	if(m2!=0) fprintf(fp2, "%d ", m2);
	if(m3!=0) fprintf(fp2, "%d ", m3);
	fclose(fp2);
}

void sort_file()
{
	int temp=0, min1=2147483647, min2=2147483647, min3=2147483647;
	int checkagain=0, checkagain1=0;
	int counter=0;
	/* we equate the numbers to the largest 32-bit number 2147483647 */
	FILE *fp;
	FILE *fp2;
	fp = fopen("results.txt","r");
	fp2 = fopen("temporary.txt","a+");

	while (fscanf(fp, "%d", &temp) == 1)
	{/* we find the number of integers in results.txt file with counter */
		counter++;
	}
	
	rewind(fp); /* rewinds the txt. */
	while (fscanf(fp, "%d", &temp) == 1)
	{/* !!! In this while, we find the 3 smallest numbers using 1 loop. */
		if(min1>temp)
		{/* With check_again, we are checking numbers that cannot enter the '2nd if' because it is(the number) equal to min1 */
			checkagain=min1;
			min1=temp;
			if(checkagain!=min1) temp = checkagain;
		}
		if(min2>temp && temp!=min1)
		{/* With check_again1, we are checking numbers that cannot enter the '3nd if' because it is(the number) equal to min2 */
			checkagain1=min2;
			min2=temp;
			if(checkagain1!=min2)
			{
				temp = checkagain1;
			}
			else
			{
				temp = checkagain;
			}
		}
		if(min3>temp && temp!=min1 && temp!=min2)
		{
			min3=temp;
		}
	}
	txt_to_txt(min1,min2,min3); /* we print the smallest 3 numbers to temporary.txt */
	/* !!! We split the upper loop from the lower loop to find 'previous_max.' */
	int previous_max;
	int i=1;
	while (i<(counter/3)) /* For example, if there are 10 integers, the loop returns 3 times. */
	{/* !!! We check the remainder of the division operation in the next while loops. (not this one) */
		previous_max=min3; /* we equate the largest number in each previous loop to this variable */
		min1=2147483647;
		min2=2147483647;
		min3=2147483647;
		checkagain=0;
		checkagain1=0;
		rewind(fp);
		while (fscanf(fp, "%d", &temp) == 1)
		{/* !!! This loop continues until there are 0, 1 or 2 numbers left in the txt. */
			if(temp>previous_max)
			{/* It must be greater than the largest number of the previous loop to enter the 'if'. */
				if(min1>temp)
				{
					checkagain=min1;
					min1=temp;
					if(checkagain!=min1) temp = checkagain;
				}
				if(min2>temp && temp!=min1)
				{
					checkagain1=min2;
					min2=temp;
					if(checkagain1!=min2) temp = checkagain1;
					else temp = checkagain;
				}
				if(min3>temp && temp!=min1 && temp!=min2)
				{
					min3=temp;
				}
			}
		}
		previous_max=min3; /* we equalize this again for the while loops below. */
		txt_to_txt(min1,min2,min3); /* each repetition of the loop we print the smallest 3 numbers to the temporary.txt file */
		i++;
	}

	rewind(fp);
	if(counter%3==1)
	{/* If there is 1 more integer than a multiple of 3 in the txt, it goes into the if and prints the last number to the temporary.txt file. */
		while (fscanf(fp, "%d", &temp) == 1)
		{
			if(temp>previous_max)
			{
				min1=temp;
			}
		}
		txt_to_txt(min1,0,0); /* it prints the last number to the temporary.txt file. */
	}

	min1=2147483647;
	min2=2147483647;
	checkagain=0;
	rewind(fp);
	if(counter%3==2)
	{/* If there are 2 more integers than multiples of 3 in the txt, it goes into the if and prints the last 2 numbers to the temporary.txt file. */
		while (fscanf(fp, "%d", &temp) == 1)
		{
			if(temp>previous_max)
			{
				if(min1>temp)
				{
					checkagain=min1;
					min1=temp;
					if(checkagain!=min1) temp = checkagain;
				}
				if(min2>temp && temp!=min1)
				{
					min2=temp;
				}
			}
		}
		txt_to_txt(min1,min2,0); /* it prints the last 2 numbers to the temporary.txt file. */
	}

	fclose(fp);
	fclose(fp2);
	fp = fopen("results.txt","w"); /* We delete the content for the 'while' below. */
	fp2 = fopen("temporary.txt","r");
	
	while (fscanf(fp2, "%d", &temp) == 1)
	{/* copying from temporary.txt to results.txt file. */
		fprintf(fp, "%d ", temp);
	}
	printf("Sorting is complete.\n");

    fclose(fp);
    fclose(fp2);
    
    print_file(); /* it prints the numbers in the results.txt file to the terminal. */
}

int main()
{
	int selection;
	int operation_flag; /* for the case 1 */
	int N, i, a; /* for the case 2 */
	
	printf("Select operation:\n");
	printf("1. Calculate sum/multiplication between two numbers\n");
	printf("2. Calculate prime numbers\n");
	printf("3. Show number sequence in file\n");
	printf("4. Sort number sequence in file\n");
	printf("-------------------------\n");
	
	scanf("%d", &selection);
	switch(selection)
	{
		case 1:
			printf("Please enter '0' for sum, '1 for multiplication.\n");
			scanf("%d", &operation_flag);
			switch(operation_flag)
			{
				case 0: sum_calculator(); /* !!! In this function, we take the inputs and call the SUM function. */
				break;
				case 1: multi_calculator(); /* /* !!! In this function, we take the inputs and call the MULTI function. */
				break;
				default: printf("Please enter correct input.\n");
			}
			break;
		case 2:
			printf("Please enter an integer: ");
			scanf("%d", &N);
			for(i=2;i<N;i++)
			{/* It checks whether it is prime or not, from 2 to the entered number. */
				a=isprime(i); /* we set it equal to 'a' so, we can print it on 2 bottom lines -> '392' */
				if(isprime(i)==0) printf("%d is a prime number.\n", i); /* if return equals flag */
				else printf("%d is NOT a prime number, it is divisible by %d.\n", i, a);
			}
			break;
		case 3:
			print_file(); /* it prints the numbers in the results.txt file to the terminal. */
			break;
		case 4:
			sort_file(); /* we are sorting numbers in the results.txt file. */
			break;
		default: printf("Please enter correct input.\n");
	}
	
	return 0;
}
