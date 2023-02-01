#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {
	/* ask for the problem selection */
	int x;
	do
	{/* It asks again until you choose one out of three. */
		printf("Which problem do you want to choose? (0, 1, 2 or 3): ");
		scanf("%d",&x);
	}while(x!=0 && x!=1 && x!=2 && x!=3);
	
	/* we test dt0 */
	if(x==0)
	{/* variables of part 0: */
		int t,s,w;
		double p,h;
		int a; /* function */
		printf("=========PART 0: dt0=========\n");
		printf("t: ");
		scanf("%d", &t);
		printf("p(double): ");
		scanf("%lf", &p);
		printf("h(double): ");
		scanf("%lf", &h);
		printf("s: ");
		scanf("%d", &s);
		printf("w: ");
		scanf("%d", &w);
		a = dt0(t, p, h, s, w);
		printf("dt0: %d\n", a);
	}
	
	/* we test dt1a & dt1b and compare it */
    if(x==1)
    {/* variables of part 1: */
    	float pl, pw, sl, sw;
    	char y,z; /* functions */
	    printf("=========PART 1: dt1a & dt1b=========\n");
	    printf("PL: ");
	    scanf("%f", &pl);
	    printf("PW: ");
	    scanf("%f", &pw);
	    printf("SL: ");
	    scanf("%f", &sl);
	    printf("SW: ");
	    scanf("%f", &sw);
	    
		y = dt1a(pl,pw,sl,sw);
		z = dt1b(pl,pw,sl,sw);
		
		if(y==z) /* if the values are equal: */
		{
			printf("THE RESULTS ARE THE SAME!:\n");
			if (y=='s') printf("Setosa\n"); /* 's' means Setosa */
			else if (y=='e') printf("Versicolor\n"); /* 'e' means Versicolor */
			else printf("Virginica\n"); /* 'i' means Virginica */
		}
		else /* if the values are different: */
		{
			printf("The results are different:\n");
			if (y=='s') printf("dt1a: Setosa\n"); /* 's' means Setosa */
			else if (y=='e') printf("dt1a: Versicolor\n"); /* 'e' means Versicolor */
			else printf("dt1a: Virginica\n"); /* 'i' means Virginica */
		
			if (z=='s') printf("dt1b: Setosa\n"); /* 's' means Setosa */
			else if (z=='e') printf("dt1b: Versicolor\n"); /* 'e' means Versicolor */
			else printf("dt1b: Virginica\n"); /* 'i' means Virginica */
		}
	}

    /* we test dt2a & dt2b and compare it */
    if(x==2)
    {/* variables of part 2: */
    	float x1, x2, x3;
		int x4, x5;
    	float b,c; /* functions */
		printf("\n=========PART 2: dt2a & dt2b=========\n");
		printf("x1: ");
		scanf("%f", &x1);
		printf("x2: ");
		scanf("%f", &x2);
		printf("x3: ");
		scanf("%f", &x3);
		printf("x4(boolean): ");
		scanf("%d", &x4);
		printf("x5(boolean): ");
		scanf("%d", &x5);
		
		b = dt2a(x1,x2,x3,x4,x5);
		c = dt2b(x1,x2,x3,x4,x5);
		
		if(b==c) printf("THE RESULTS ARE THE SAME! -> %f\n", b); /* if the values are equal: */
		else if (abs((float)(b-c))<=CLOSE_ENOUGH) printf("THE AVERAGE OF THE TWO IS: %f\n", (b+c)/2); /* if it fits to "close_enough", I print the average. */
		else printf("The results are different:\ndt2a: %.2f\ndt2b: %.2f\n", b, c); /* if the values are different: */	
	}
	
	/* I made a tree that tells you whether you can get a loan according to a few information given, and if you can, how much in how many months you will pay. */
    /* we test dt3a & dt3b and compare it */
    if(x==3)
    {/* variables of part 3: */
    	int b1; /* binary */
    	int c1, c2; /* categoricals */
    	double r1, r2; /* reel numbers */
		double d, e; /* functions */
    	printf("=========PART 3: dt3a & dt3b=========\n");
    	printf("How much is your monthly income?(Please answer in \"TL\")\nAnswer(double):");
    	scanf("%lf", &r1); /* it asks monthly income as 'double' */
    	printf("Do you have a criminal record?\n(0 for \"no\"  &  1 for \"yes\")\nAnswer(binary): ");
    	scanf("%d", &b1); /* it asks criminal record status as 'binary' */
    	printf("Which bank you want to take out a loan from?\n1 -> ING\n2 -> Denizbank\n3 -> Yapikredi\n4 -> QNB\n5 -> TEB\n6 -> Garanti\nChoose an option: ");
    	scanf("%d",&c1); /* choose the bank */
    	printf("How much loan do you want to take out?(Please answer in \"TL\")\nAnswer(double): ");
    	scanf("%lf", &r2); /* it asks for loan amount as 'double' */
    	printf("How many months would you like to pay back?\n1 -> 3 months\n2 -> 6 months\n3 -> 9 months\n4 -> 12 months\n5 -> 18 months\n6 -> 24 months\nChoose an option: ");
    	scanf("%d", &c2); /* select the number of months you want to repay */
    	
		d = dt3a(b1,r1,r2,c1,c2);
    	e = dt3b(b1,r1,r2,c1,c2);

		printf("\n\nLoan Amount: %lf\n\n", r2);
		printf("PART 3 - TABLE 1:\n");
    	if(d!=0)
    	{/* These are the outputs. */
    		if(c2==1) printf("Term: 3 Months.\n"); /* c2=1 means that the user chose 3 monthly installments */
    		if(c2==2) printf("Term: 6 Months.\n"); /* c2=2 means that the user chose 6 monthly installments */
    		if(c2==3) printf("Term: 9 Months.\n"); /* c2=3 means that the user chose 9 monthly installments */
    		if(c2==4) printf("Term: 12 Months.\n"); /* c2=4 means that the user chose 12 monthly installments */
    		if(c2==5) printf("Term: 18 Months.\n"); /* c2=5 means that the user chose 18 monthly installments */
    		if(c2==6) printf("Term: 24 Months.\n"); /* c2=6 means that the user chose 24 monthly installments */
    		printf("Installment Amount: %lf\n", d); /* the monthly installment */
    		if(c2==1) printf("Total Repayment Amount: %lf\n", d*3); /* c2=1 means that the user chose 3 monthly installments */
    		if(c2==2) printf("Total Repayment Amount: %lf\n", d*6); /* c2=2 means that the user chose 6 monthly installments */
    		if(c2==3) printf("Total Repayment Amount: %lf\n", d*9); /* c2=3 means that the user chose 9 monthly installments */
    		if(c2==4) printf("Total Repayment Amount: %lf\n", d*12); /* c2=4 means that the user chose 12 monthly installments */
    		if(c2==5) printf("Total Repayment Amount: %lf\n", d*18); /* c2=5 means that the user chose 18 monthly installments */
    		if(c2==6) printf("Total Repayment Amount: %lf\n", d*24); /* c2=6 means that the user chose 24 monthly installments */
		}
		else printf("dt3a: You can't take out a loan.\n"); /* if return equals zero */

		printf("\nPART 3 - TABLE 2:\n");
		if(e!=0)
		{/* These are the outputs. */
    		if(c2==1) printf("Term: 3 Months.\n"); /* c2=1 means that the user chose 3 monthly installments */
    		if(c2==2) printf("Term: 6 Months.\n"); /* c2=2 means that the user chose 6 monthly installments */
    		if(c2==3) printf("Term: 9 Months.\n"); /* c2=3 means that the user chose 9 monthly installments */
    		if(c2==4) printf("Term: 12 Months.\n"); /* c2=4 means that the user chose 12 monthly installments */
    		if(c2==5) printf("Term: 18 Months.\n"); /* c2=5 means that the user chose 18 monthly installments */
    		if(c2==6) printf("Term: 24 Months.\n"); /* c2=6 means that the user chose 24 monthly installments */
			printf("Installment Amount: %lf\n", e); /* the monthly installment */
    		if(c2==1) printf("Total Repayment Amount: %lf\n", e*3); /* c2=1 means that the user chose 3 monthly installments */
    		if(c2==2) printf("Total Repayment Amount: %lf\n", e*6); /* c2=2 means that the user chose 6 monthly installments */
    		if(c2==3) printf("Total Repayment Amount: %lf\n", e*9); /* c2=3 means that the user chose 9 monthly installments */
    		if(c2==4) printf("Total Repayment Amount: %lf\n", e*12); /* c2=4 means that the user chose 12 monthly installments */
    		if(c2==5) printf("Total Repayment Amount: %lf\n", e*18); /* c2=5 means that the user chose 18 monthly installments */
    		if(c2==6) printf("Total Repayment Amount: %lf\n", e*24); /* c2=6 means that the user chose 24 monthly installments */
		}
		else printf("dt3b: You can't take out a loan.\n"); /* if return equals zero */

		if(d==e) printf("\nTHE RESULTS ARE THE SAME!\n"); /* if the values are equal: */
		else if (abs((float)(d-e))<=CLOSE_ENOUGH) printf("\nTHE AVERAGE OF THE TWO IS: %f\n", (d+e)/2); /* if it fits to "close_enough", I print the average. */
		else printf("\nThe results are different.\n"); /* if the values are different: */
	}
    return 0;
}
