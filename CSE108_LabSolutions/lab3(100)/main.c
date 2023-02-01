#include <stdio.h>

void x_star_display(int height)
{
	int i, j;
	int count;

	if(height%2==1)
	{
		count = height;
		for(i=1; i<=count; i++)
		{
			for(j=1; j<=count; j++)
			{
				if(j==i || (j==count - i + 1)) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	else printf("PLEASE ENTER ODD NUMBER.\n\n");
}

void diamond_star_display(int n)
{
	int i, j, mid;
	if(n%2==1) //TEK Mİ DİYE KONTROL EDİYO
	{
		if(n%2 == 1) n++; //when n is odd, increase it by 1 to make it even
		mid = (n/2);

		for(i=1; i<= mid; i++) //ELMAS'IN ÜST KISMI
		{
			for(j=1; j<=(mid-i); j++) printf(" "); //yıldızdan önceki boşluklar
			if(i == 1) printf("*"); //THE FIRST LINE.
			else {
				printf("*"); //HER SATIRDAKİ İLK YILDIZ
				for(j=1; j<=2*i-3; j++) printf(" "); //elmasın içini boşaltmak için
				printf("*"); //HER SATIRDAKİ SON YILDIZ
			}
		printf("\n");
		}
		for(i=mid+1; i<n; i++) //ELMAS'IN ALT KISMI
		{
			for(j=1; j<=i-mid; j++) { //yıldızdan önceki boşluklar
				printf(" ");
			}
			if(i == n-1) {
				printf("*"); //THE LAST LINE.
			}
			else {
				printf("*"); //HER SATIRDAKİ İLK YILDIZ
				for(j=1; j<=2*(n - i)-3; j++) printf(" "); //elmasın içini boşaltmak için
				printf("*"); //HER SATIRDAKİ SON YILDIZ
			}
		printf("\n");
		}
	}
	else printf("PLEASE ENTER ODD NUMBER!\n\n");
}

void multiplication_table_display(int n)
{
	int i, j;
	int x=1, y=1;
	
	printf("  "); //en üst satırı kaydırmak için koydum
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(y<=n)
			{
				printf("%5d", y);
				y++;
			}
		}
		if(x==1)
		{
			printf("\n");
			for(j=1;j<=n;j++)
			{
				printf("-------");
			}
			printf("\n");
			//printf("\n------------------------------------\n");
		}
		printf("%d*", x);
		x++;
		for(j=1;j<=n;j++)
		{
			
			printf("%5d", i*j);
		}
		printf("\n");
	}
}

void is_palindrome_integer(int n)
{
	int r, sum=0, temp;
	temp=n;

	while(n>0)
	{
		r=n%10;
		sum=(sum*10)+r;
		n=n/10;
	}
	if(temp==sum) printf("%d is a palindrome.\n", temp);
	else printf("%d is NOT a palindrome.\n", temp);
}

int main()
{
	int op, height, size, n;
	do
	{
		printf("\n====================================\n");
		printf("Enter option 1 to x_star_display\nEnter option 2 to diamond_star_display\nEnter option 3 to multiplication_table_display\nEnter option 4 to palindrome check number\nEnter option -1 to exit!\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: 
				printf("Enter an odd integer as the height:");
				scanf("%d", &height);
				x_star_display(height);
				break;
			case 2:
				printf("Enter an odd integer as the height:");
				scanf("%d", &height);
				diamond_star_display(height);
				break;
			case 3:
				printf("Enter an integer as the size:");
				scanf("%d", &size);
				multiplication_table_display(size);
				break;
			case 4:
				printf("Enter an integer as the palindrome:");
				scanf("%d", &n);
				is_palindrome_integer(n);
				break;
			default:
				if(op!=-1) printf("PLEASE ENTER CORRECT INPUT!\n");
		}
	}while(op!=-1);
	return 0;
}