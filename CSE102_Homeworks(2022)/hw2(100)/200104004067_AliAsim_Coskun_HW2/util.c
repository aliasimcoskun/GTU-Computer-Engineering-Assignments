#include <stdio.h>
#include <math.h>
#include "util.h"

/* Example decision tree */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

char dt1a(float pl, float pw, float sl, float sw)
{/* The first decision tree for P1: */
	char x = 'i'; /* 'i' means Virginica */
	/* We equate x to 'i' so that if it does NOT enter any "if" state, we can return 'i'. */
	if (pl<2.45) x = 's'; /* 's' means Setosa */
	else if (pl<4.95 && pw<1.65) x = 'e'; /* 'e' means Versicolor */
	/* we write equality according to the given table */
	return x;
}
char dt1b(float pl, float pw, float sl, float sw)
{/* The second decision tree for P1: */
	char x = 'i'; /* 'i' means Virginica */
	/* We equate x to 'i' so that if it does NOT enter any "if" state, we can return 'i'. */
	if (pl<(float)2.55) x = 's'; /* 's' means Setosa */
	else if (pw<1.69 && pl<4.85) x = 'e'; /* 'e' means Versicolor */
	/* we write equality according to the given table */
	return x;
}

double dt2a(double x1, double x2, double x3, int x4, int x5)
{/* The first decision trees for P2: */
	double r;
	if(x1<31.5)
	{
		if(x2>-2.5) r = 5.0;
		else if(x2-0.1 <= x1 && x1 <= x2+0.1) r = 2.1;
		else r = -1.1;
	}
	else if(-1 <= x3 && x3 <= 2) r = 1.4;
	else
	{
		if(x4==1 && x5==1) r = -2.23; /* 'x4 and x5' operation */
		else r = 11.0;
	}
	return r;
}
double dt2b(double x1, double x2, double x3, int x4, int x5)
{/* The second decision trees for P2: */
	double r;
	if(12<x1 && x1<22)
	{
		if(x3>(double)5/3) r = -2.0; /* To avoid the error that occurs, we specified that it is a 'double' */
		else if(x1-0.1<=x3 && x3<=x1+0.1) r = 1.01;
		else r = -8;
	}
	else
	{
		if(x4==1 && x5==1) r = -1; /* 'x4 and x5' operation */
		else if(-1<=x2 && x2<=2) r = (double)-1/7; /* To avoid the error that occurs, we specified that it is a 'double' */
		else r = sqrt(2)/3; /* we take the square root of 2 with 'sqrt' */
	}
	return r;
}

double dt3a(int b1, double r1, double r2, int c1, int c2)
{
	double r; /* The variable which we are going to return. */
	double Interest_Rate; /* Interest rate, which varies according to the each bank. */
	if(0<r1 && r1<=9999.99)
	{/* If your monthly income is less than 10000, you cannot take out a loan. */
		return 0;
	}
	else if(10000<=r1 && r1<=49999.99)
	{/* If your monthly income is between 10000 and 50000, you can take a loan, but you must NOT have a criminal record. */
		if(b1==0)
		{/* If you do NOT have a criminal record. */
			if(c1==1)
			{/* If you have chosen the ING: */
				Interest_Rate=1.74/100; /* the interest rate of ING */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==2)
			{/* If you have chosen the Denizbank: */
				Interest_Rate=2.52/100; /* the interest rate of Denizbank */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==3)
			{/* If you have chosen the Yapikredi: */
				Interest_Rate=2.94/100; /* the interest rate of Yapikredi */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==4)
			{/* If you have chosen the QNB: */
				Interest_Rate=1.84/100; /* the interest rate of QNB */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==5)
			{/* If you have chosen the TEB: */
				Interest_Rate=1.85/100; /* the interest rate of TEB */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==6)
			{/* If you have chosen the Garanti: */
				Interest_Rate=2.73/100; /* the interest rate of Garanti */
				if(r2>=500)
				{/* You can't take out a loan for less than 500TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else if(50000<=r1)
	{/* If your monthly income is over 50000, you can take out a loan under any condition. So, there are no variable b1 */
		if(c1==1)
		{/* If you have chosen the ING: */
			Interest_Rate=1.74/100; /* the interest rate of ING */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==2)
		{/* If you have chosen the Denizbank: */
			Interest_Rate=2.52/100; /* the interest rate of Denizbank */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==3)
		{/* If you have chosen the Yapikredi: */
			Interest_Rate=2.94/100; /* the interest rate of Yapikredi */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==4)
		{/* If you have chosen the QNB: */
			Interest_Rate=1.84/100; /* the interest rate of QNB */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==5)
		{/* If you have chosen the TEB: */
			Interest_Rate=1.85/100; /* the interest rate of TEB */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==6)
		{/* If you have chosen the Garanti: */
			Interest_Rate=2.73/100; /* the interest rate of Garanti */
			if(r2>=500)
			{/* You can't take out a loan for less than 500TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;

	return r;
}
double dt3b(int b1, double r1, double r2, int c1, int c2)
{
	double r; /* The variable which we are going to return. */
	double Interest_Rate; /* Interest rate, which varies according to the each bank. */
	if(0<r1 && r1<=19999.99)
	{/* If your monthly income is less than 20000, you cannot take out a loan. */
		return 0;
	}
	else if(20000<=r1 && r1<=99999.99)
	{/* If your monthly income is between 20000 and 100000, you can take a loan, but you must NOT have a criminal record. */
		if(b1==0)
		{/* If you do NOT have a criminal record. */
			if(c1==1)
			{/* If you have chosen the ING: */
				Interest_Rate=1.75/100; /* the interest rate of ING */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==2)
			{/* If you have chosen the Denizbank: */
				Interest_Rate=3.76/100; /* the interest rate of Denizbank */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==3)
			{/* If you have chosen the Yapikredi: */
				Interest_Rate=2.90/100; /* the interest rate of Yapikredi */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==4)
			{/* If you have chosen the QNB: */
				Interest_Rate=1.20/100; /* the interest rate of QNB */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==5)
			{/* If you have chosen the TEB: */
				Interest_Rate=0.93/100; /* the interest rate of TEB */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else if(c1==6)
			{/* If you have chosen the Garanti: */
				Interest_Rate=3.13/100; /* the interest rate of Garanti */
				if(r2>=1000)
				{/* You can't take out a loan for less than 1000TL */
					if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
					if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
					if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
					if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
					if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
					if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else if(100000<=r1)
	{/* If your monthly income is over 100000, you can take out a loan under any condition. So, there are no variable b1 */
		if(c1==1)
		{/* If you have chosen the ING: */
			Interest_Rate=1.75/100; /* the interest rate of ING */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==2)
		{/* If you have chosen the Denizbank: */
			Interest_Rate=3.76/100; /* the interest rate of Denizbank */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==3)
		{/* If you have chosen the Yapikredi: */
			Interest_Rate=2.90/100; /* the interest rate of Yapikredi */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==4)
		{/* If you have chosen the QNB: */
			Interest_Rate=1.20/100; /* the interest rate of QNB */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==5)
		{/* If you have chosen the TEB: */
			Interest_Rate=0.93/100; /* the interest rate of TEB */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else if(c1==6)
		{/* If you have chosen the Garanti: */
			Interest_Rate=3.13/100; /* the interest rate of Garanti */
			if(r2>=1000)
			{/* You can't take out a loan for less than 1000TL */
				if(c2==1) r = (r2 + r2*Interest_Rate)/3; /* We find the installment amount according to 3 months. */
				if(c2==2) r = (r2 + r2*Interest_Rate)/6; /* We find the installment amount according to 6 months. */
				if(c2==3) r = (r2 + r2*Interest_Rate)/9; /* We find the installment amount according to 9 months. */
				if(c2==4) r = (r2 + r2*Interest_Rate)/12; /* We find the installment amount according to 12 months. */
				if(c2==5) r = (r2 + r2*Interest_Rate)/18; /* We find the installment amount according to 18 months. */
				if(c2==6) r = (r2 + r2*Interest_Rate)/24; /* We find the installment amount according to 24 months. */
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
	return r;
}
