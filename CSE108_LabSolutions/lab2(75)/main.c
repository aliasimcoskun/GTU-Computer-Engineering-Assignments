#include <stdio.h>
#include <math.h>

void write_file(FILE *pt, int result)
{
        pt = fopen("result.txt","a+");
        fprintf(pt, "%d ", result);
}

int gcd_cal(int a, int b)
{
        int result;
        int big,small;

        if (a >= b)
        {
                big = a;
                small = b;
        }
        else if (b >= a)
        {
                big = b;
                small = a;
        }
        if (big % small == 0)
        {
                result = small;
                return (result);
        }
        int i = small;

        while (i > 0)
        {
                if (big % i == 0 && small % i == 0)
                {
                        result = i;
                        return (result);
                }
                i--;
        }

        return (result);
}

int lcm_cal(int a, int b, int gcd)
{
        int result;
        int i = 1;
        int keep_reading = 1;
        while (keep_reading)
        {
                if (a == 0 || b == 0) //if the input is zero, break the loop.
                        keep_reading = 0;
                if (i * gcd == a*b)
                {
                        result = i;
                        return (i);
                }
        i++;
        }
        return (result);
}

float calculate_mean(int *ptr)
{
        int sum = 0;
        int num = 0;
        int i = 0;

        FILE *fp;

        fp = fopen("result.txt","r");

        while(!feof(fp))
        {
                fscanf(fp, "%d ",&num);
                sum = sum + num;
                printf("NUMBER %d IS %d\n",i + 1,num);
                i++;
        }

        fclose(fp);

        sum = (double)sum / i;
        *ptr = i;
        return (sum);
}

float std_cal(int *a, int mean)
{
        float result=0;
        float temp=0;
        int count = *a;
        printf("mean: %d\n", mean);
        int i = 0;

        while (i <= count)
        {
                temp = (i - mean)*(i - mean);
                result = result + temp;
                i++;
        }

        result = result / (float)count;
        result = sqrt(result);
        printf("AAAAA RESULT: %f\n", result);
        return (result);
}

int main()
{
	int choice, num1, num2;
	printf("Enter the calculator type:\n");
	printf(" 1. GCD Calculator\n 2. LCM Calculator via GCD\n 3. Standard Deviation Calculator\n");
	printf("-------------------\n");
	scanf("%d", &choice);

	int result;

	FILE *ptr = fopen("result.txt","a+");

	if(choice == 1)
	{
                printf("Please enter two different number:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
		result = gcd_cal(num1,num2);
		write_file(ptr, result);
	}
	else if (choice == 2)
	{
                printf("Please enter two different number:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
		int gcd = gcd_cal(num1,num2);
		result = lcm_cal(num1, num2,gcd);
		write_file(ptr, result);
	}
	else if (choice == 3)
	{
		int *ptr;
		float mean = calculate_mean(ptr);
		printf("%f : mean\n",mean);
		printf("%d : count\n",*ptr);
		float resultt = std_cal(ptr,mean);
		printf("%.2lf : Standart Deviation",resultt);
	}
        fclose(ptr);
        return (0);
}     