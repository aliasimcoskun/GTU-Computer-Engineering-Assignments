#include <stdio.h>

void x_star_display(int height){
    int i, j;
    int count;
	if(height%2==1){
	    count=height;
	    for(i=1; i<=count; i++)
	    {
	        for(j=1; j<=count; j++)
	        {
	            if(j==i || (j==count - i + 1))
	            {
	                printf("*");
	            }
	            else
	            {
	                printf(" ");
	            }
	        }
	        printf("\n");
	    }
	}
	else printf("you did NOT enter an odd number.");
}

void diamond_star_display(int n){
   int i, j, mid;
   if(n%2==1)
   {
		if(n%2==1)
		{ 
			n++;
		}
		mid=(n/2);
		for(i=1; i<= mid; i++) {
			for(j=1; j<=(mid-i); j++){ 
				printf(" ");
			}
			if(i == 1) {
				printf("*");
			}
			else {
				printf("*");
				for(j=1; j<=2*i-3; j++){
					printf(" ");
				}
			printf("*");
		    }
		printf("\n");
		}
		for(i=mid+1; i<n; i++) {
			for(j=1; j<=i-mid; j++) {
				printf(" ");
			}
			if(i == n-1) {
				printf("*");
			}
			else {
				printf("*");
				for(j=1; j<=2*(n-i)-3; j++) {
				printf(" ");
				}
			printf("*");
			}
		printf("\n");
		}
	}
	else printf("PLEASE ENTER ODD NUMBER!\n");
}

void multiplication_table_display(int size){
	int i, j;
	int x=1, y=1;
	
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(y<=size)
			{
				printf("\t%d", y);
				y++;
			}
		}
		if(x==1) printf("\n------------------------------------\n");
		printf("%d*", x);
		x++;
		for(j=1;j<=size;j++)
		{
			printf("\t%d", i*j);
		}
		printf("\n");
	}
}

void is_palindrome_integer(int n){
	int r,sum=0,temp;   
    temp=n;    
    
    while(n>0)    
    {    
        r=n%10;    
        sum=(sum*10)+r;
        n=n/10;    
    }    

    if(temp==sum)    
        printf("%d is a palindrome.\n", temp);    
    else    
    printf("%d is NOT a palindrome.\n", temp);   
    
}

int main(){
int op,height,size,n;
int flag=1;
do{
	printf("\n\n1 => x_star_display\n2 => diamond_star_display\n3 => multiplication_table_display\n4 => palindrome check number\n0 => exit!\n");
	scanf("%d",&op);
	switch(op){
		case 1: 
		    printf("Enter an odd integer as the height: ");
    		scanf("%d", &height);
    		x_star_display(height);
			break;
		case 2:
		    printf("Enter an odd integer as the height: ");
    		scanf("%d", &height);
    		diamond_star_display(height);
			break;
		case 3:
			printf("Enter an integer as the size: ");
			scanf("%d",&size);
			multiplication_table_display(size);
			break;
		case 4:
			printf("Enter an integer as the palindrome: ");
			scanf("%d",&n);
			is_palindrome_integer(n);
			break;
		case 0:
			printf("You want to exit, bye!\n");
			flag=0;
			break;
		default:
			printf("you entered a wrong choice, please try again!\n");
			break;
	}
}while(flag);
	return 0;
}