#include <stdio.h>

enum products
{
	Harddisk, Monitor, Keyboard, Mouse
};

enum days
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

enum selections
{
	buy=1, orders, prices, exit
};

enum currencies
{
	dolar=4, euro=5, pound=9, peso=10
};

enum product_prices
{
	harddisk=2*dolar, monitor=5*euro, keyboard=3*pound, mouse=10*peso
};

void print_days(int day)
{
	if(day==0) printf("Day: Sunday\n");
	else if(day==1) printf("Day: Monday\n");
	else if(day==2) printf("Day: Tuesday\n");
	else if(day==3) printf("Day: Wednesday\n");
	else if(day==4) printf("Day: Thursday\n");
	else if(day==5) printf("Day: Friday\n");
	else if(day==6) printf("Day: Saturday\n");
}

void readOrderFile(void *print_days(int day)) //void mi belli degil
{
	int id, day;
	FILE *fp;
	fp=fopen("orders.txt","r");
	while(fscanf(fp,"%d %d ", &id, &day)!=EOF)
	{
		printf("Product ID: %d, ", id);
		*print_days(day);
		multi(id);
	}
	//fscanf(fp,"%d %d ", &id, &day);
	fclose(fp);
}

int add(int x, int sum)
{
	sum=sum+x;
	return sum;
}

int multi(int id, int x)
{
	if(id==0) x=2*dolar; //harddisk
	else if(id==1) x=5*euro; //monitor
	else if(id==2) x=3*pound; //keyboard
	else if(id==3) x=10*peso; //mouse
	//printf("price: %d\n", x);
	return x;
}

/*
int multi(int id, int product_prices)
{
	int x=0;
	//enum product_prices;
	if(id==0) x=x+harddisk;
	else if(id==1) x=x+monitor;
	else if(id==2) x=x+keyboard;
	else if(id==3) x=x+mouse;
	printf("toplam: %d\n", x);
	return x;
}
*/
void part4(int add(), int multi(), void *print_days()) //void mi belli degil
{
	int id, day;
	int sum=0;
	int x=0;
	int deneme=0;
	FILE *fp;
	fp=fopen("orders.txt","r");
	while(fscanf(fp,"%d %d ", &id, &day)!=EOF)
	{
		if(id==0) printf("Product: Harddisk,");
		else if(id==1) printf("Product: Monitor,");
		else if(id==2) printf("Product: Keyboard,");
		else if(id==3) printf("Product: Mouse,");
		//printf("Product ID: %d, ", id);
		*print_days(day);
		deneme=deneme+add(multi(id, x),sum);
	}
	//fscanf(fp,"%d %d ", &id, &day);
	fclose(fp);

	
/*
	if(id==0) x=multi(2, dolar); //harddisk
	else if(id==1) x=multi(5, euro); //monitor
	else if(id==2) x=multi(3, pound); //keyboard
	else if(id==3) x=multi(10, peso); //mouse
	printf("x: %d", x);
*/

	//int b = add(x, sum);

	printf("Total prices: %d TL\n", deneme);
}

int main()
{
	/*
	enum product_prices deneme;
	deneme=keyboard;
	printf("KEY: %dTL", deneme);
	*/
	int op, product;
	int day;
	//fprintf(fp, "%d ", number);
	//fclose(fp);
	int flag=1;
	do
	{
		printf("\n1. Buy Product\n");
		printf("2. Orders\n");
		printf("3. All Orders Prices\n");
		printf("4. EXIT\n");
		printf("-----------------------------\n");
		scanf("%d", &op);

		switch(op)
		{
			case buy:
			{
				FILE *fp;
				fp=fopen("orders.txt","a+");
				enum products urun;
				printf("Select your product:\n0. Harddisk\n1. Monitor\n2. Keyboard\n3. Mouse\n4. GO TO MAIN MENU\n");
				printf("-----------------------------\n");
				scanf("%d", &urun);
				if(product==4) break;
				//urun=product; //sayi degerini tutuyor.
				fprintf(fp, "%d ", urun);
				enum days gun;
				printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n");
				printf("-----------------------------\n");
				scanf("%d", &gun);
				fprintf(fp, "%d\n", gun);
				fclose(fp);
				break;
			}
			case orders:
				readOrderFile(*print_days);
				break;
			case prices:
				part4(add,multi,*print_days);
				break;
			case exit:
				flag=0;
				break;
			default:
				
				break;
		}
	}while(flag);
	return 0;
}
