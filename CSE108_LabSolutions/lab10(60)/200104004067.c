#include <stdio.h>

struct number{ /* the struct which is given */
	char number_as_str[100];
	int integer;
};

struct combination{ /* the struct which is given */
	struct number r;
	struct number n;
	float result;
};

int factorial(int n){/* calculates the sum of the product of numbers from 1 to the entered number */
	if (n>=1) return n*factorial(n-1);
    else return 1;  
}

int is_number(char *number_as_str, int length_of_str){/* determines whether the input entered by the user is a number */
	int i;
	for(i=0;i<length_of_str;i++){
		if('0'<=number_as_str[i] && number_as_str[i]<='9');
		else return 0;
	}
	return 1;
}

int parse_to_int(char *number_as_str, int length_of_str){/* converts the entered char array to integer */
	int i;
	int temp1[100];
	char temp;
	int result=0;
	for(i=0;i<length_of_str;i++){
		temp=number_as_str[i];
        temp1[i]=temp-48;
	}
	
	int k=1;
	for(i=length_of_str-1;i>=0;i--){
		result=result+(k*temp1[i]);
		k=k*10;
	}
	return result;
}

int str_len(char *str){/* calculates the length of the entered string */
	if (*str == '\0')
        return 0;
    else
        return 1 + str_len(str + 1);
}

int base_converter(int decimal_number,int base){ /* the function converts the number to another number in entered base */
	int i;
    if(decimal_number == 0 || base==10) return decimal_number; /* if decimal number is 0 or base is 10, it is not needed to convert it */
	else{
		i= (decimal_number % base) + 10*base_converter(decimal_number / base, base); /* it finds the converted number by recursion */
		return i;
	}
}

int main(){
	struct combination convert;
	int number_or_not;
	int number_or_not1;
	do{
		printf("r: ");
		scanf("%s", convert.r.number_as_str);

		int length_of_str=0;
		length_of_str=str_len(convert.r.number_as_str);
		convert.r.integer=parse_to_int(convert.r.number_as_str, length_of_str);

		printf("n: ");
		scanf("%s", convert.n.number_as_str);

		int length_of_str1=0;
	 	length_of_str1=str_len(convert.n.number_as_str);
	 	convert.n.integer=parse_to_int(convert.n.number_as_str, length_of_str1);

		number_or_not=is_number(convert.r.number_as_str, length_of_str);
		if(number_or_not==0) printf("\n\nInputs are not valid. Please try again\n\n");

		number_or_not1=is_number(convert.n.number_as_str, length_of_str1);
		if(number_or_not1==0) printf("\n\nInputs are not valid. Please try again\n\n");

	}while(number_or_not==0 || number_or_not1==0);

	convert.result=((factorial(convert.r.integer))/(factorial(convert.n.integer)*factorial(convert.r.integer-convert.n.integer)));
	printf("Combination (%d,%d) = %f",convert.r.integer, convert.n.integer, convert.result);

	int decimal_number, base;
	printf("\n\nDecimal number: ");
	scanf("%d",&decimal_number);
	printf("Base: ");
	scanf("%d",&base);
	printf("%d in base %d is: %d\n",decimal_number,base,base_converter(decimal_number,base)); /*it prints the number converted by base_converter fn*/
}