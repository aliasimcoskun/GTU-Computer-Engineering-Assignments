#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Person{/* this union keeps the personal informations. */
	char name[50];
	char address[50];
	int phone;
};
union Loan{/* this union keeps 3 different value which is given below. */
/*	array[0] -> amount;
	array[1] -> interestRate;
	array[2] -> period;	*/
	float array[3];
};
struct BankAccount{/* this struct keeps the unions which are given above. */
	union Person Customer;
	union Loan Loans[3];
};

/*
 * Function: calculateLoan
 *
 * It does: with recursion, it calculates the loan with the formula given in the pdf.
 *
 *
 *
 * amount: the amount of money to be loaned.
 *
 * period: payback period(in months).
 *
 * interestRate: the interest rate required to calculate the price to be repaid.
 *
 * return: we return the loan amount to be repaid.
 *
 */
float calculateLoan(float amount, int period, float interestRate){//recursive
	if(period!=0) return (1+interestRate) * calculateLoan(amount, period-1, interestRate);
	else return amount;
}

/*
 * Function: total_loan
 *
 * It does: Calculates the sum of the loans taken by the customer.
 *
 *
 *
 * BankAccount *bank: the struct containing unions that keeping loans and personal informations.
 *
 *
 *
 * i: 1 more than the ID of the customer whose total loans we calculated(id=i-1).
 *
 * return: we don't return anything.
 *
 */
void total_loan(struct BankAccount *bank, int i){
	float loan_formula[10], total=0;
	int k=0, t;
	while((bank[i-1].Loans[k].array[0])!='\0'){
		if(k==3) break;
		loan_formula[k]=calculateLoan(bank[i-1].Loans[k].array[0], bank[i-1].Loans[k].array[2], bank[i-1].Loans[k].array[1]);
		total=total+loan_formula[k];
		k++;
	}
	if(k==0){
		printf("%s hasn't taken a loan yet!\n\n", bank[i-1].Customer.name);
		return;
	}
	printf("Loans = [");
	for(t=0;t<k;t++){
		if(t==k-1) printf("%.2f", loan_formula[t]);
		else printf("%.2f + ", loan_formula[t]);
	}
	printf("] => %.2f\n\n", total);
}

/*
 * Function: listCustomer
 *
 * It does: it lists the names and loan informations of the customers in the local.
 *
 *
 *
 * BankAccount *bank: the struct containing unions that keeping loans and personal informations.
 *
 *
 *
 * *counter: it counts the number of customers added to the system.
 *
 * return: we don't return anything.
 *
 */
void listCustomers(struct BankAccount *bank, int *counter){
	if(*counter==0){
		printf("There is no local variable!\n");
		printf("Returning to the MENU...\n");
		return;
	}
	int i;
	for(i=1;i<=*counter;i++){
		printf("Customer ID = %d\n", i);
		printf("Customer Name = %s\n", bank[i-1].Customer.name);
		total_loan(bank, i);
	}
}

/*
 * Function: addCustomer
 *
 * It does: it adds customers to the system (name, address and phone informations).
 *
 *
 *
 * BankAccount *bank: the struct containing unions that keeping loans and personal informations.
 *
 *
 *
 * *counter: it counts the number of customers added to the system.
 *
 * return: we don't return anything.
 *
 */
void addCustomer(struct BankAccount *bank, int *counter){
	char temp_name[50];
	FILE *fp;
	fp=fopen("customers.txt","a+");

	printf("Please enter your name: ");
	fflush(stdin);
	scanf(" %[^\n]s", bank[*counter].Customer.name);
	fprintf(fp, "%s\n", bank[*counter].Customer.name);
	strcpy(temp_name,bank[*counter].Customer.name); // ----->1

	printf("Please enter your phone number: ");
	scanf("%d", &bank[*counter].Customer.phone);
	fprintf(fp, "%d\n", bank[*counter].Customer.phone);

	printf("Please enter your address: ");
	fflush(stdin);
	scanf(" %[^\n]%*c", bank[*counter].Customer.address);
	fprintf(fp, "%s\n", bank[*counter].Customer.address);

	strcpy(bank[*counter].Customer.name,temp_name); // ----->2
	(*counter)++;

	fclose(fp);
}

/*
 * Function: newLoan
 *
 * It does: it take out loans to customers added in the system.
 *
 *
 *
 * BankAccount *bank: the struct containing unions that keeping loans and personal informations.
 *
 *
 *
 * return: we don't return anything.
 *
 */
void newLoan(struct BankAccount *bank){
	int id, k;
	float amount, interestRate, loan_formula;
	int period;
	char check_name[50], number[50], check_address[50];
	FILE *fp2;
	fp2=fopen("loan.txt","a+");
	printf("Enter the ID of the user you want to loan(ID Number): ");
	scanf("%d", &id);
	do{
		k=0;
		while(id<1 || 50<id || !('a'<=bank[id-1].Customer.name[0] && bank[id-1].Customer.name[0]<='z')){
			printf("Wrong ID! Please try again(If you want to return to the menu, enter -1): ");
			scanf("%d", &id);
			if(id==-1){
				fclose(fp2);
				return;
			}
		}
		printf("Choosen name: %s\n", bank[id-1].Customer.name);
		while(fgets(check_name, 50, fp2) != NULL){
			fgets(number, 50, fp2); //to skip a line
			fgets(check_address, 50, fp2); //to skip a line
			check_name[strlen(check_name)-1]='\0';
			if(strcmp(bank[id-1].Customer.name,check_name)==0) k++;
		}
		rewind(fp2);
		if(k>=3){
			printf("ERROR! Each customer can only have 3 loans. Please enter another ID: ");
			scanf("%d", &id);
		}
	}while(k>=3);
	printf("How much loan do you want to take out(Amount): ");
	scanf("%f", &bank[id-1].Loans[k].array[0]);
	while(bank[id-1].Loans[k].array[0]<=0){
		printf("Wrong input! Please try again: ");
		scanf("%f", &bank[id-1].Loans[k].array[0]);
	}
	printf("How many months would you like to pay back(Period): ");
	scanf("%f", &bank[id-1].Loans[k].array[2]);
	while(bank[id-1].Loans[k].array[2]<=0){
		printf("Wrong input! Please try again: ");
		scanf("%f", &bank[id-1].Loans[k].array[2]);
	}
	printf("Enter the interest rate of your loan(Interest Rate)(between 0-1): ");
	scanf("%f", &bank[id-1].Loans[k].array[1]);
	while(bank[id-1].Loans[k].array[1]<=0){
		printf("Wrong input! Please try again: ");
		scanf("%f", &bank[id-1].Loans[k].array[1]);
	}
	loan_formula=calculateLoan(bank[id-1].Loans[k].array[0], bank[id-1].Loans[k].array[2], bank[id-1].Loans[k].array[1]);
	printf("Loan Formula = %lf\n", loan_formula);
	fprintf(fp2, "%s\n", bank[id-1].Customer.name);
	fprintf(fp2, "%lf\n", loan_formula);
	fprintf(fp2, "%f\n", bank[id-1].Loans[k].array[2]);
	fclose(fp2);
}

/*
 * Function: getReport
 *
 * It does: it reports the lists of customers and their loans in the system separately.
 *
 *
 *
 * *counter: it counts the number of customers added to the system.
 *
 * return: we don't return anything.
 *
 */
void getReport(int *counter){
	int flag=1, operator, i;
	char name_report[50], number[50], address_report[50];
	int integer_num;
	char name_check[50], loan_report[50], period_report[50];
	int loan_check, k, controller, t;
	float float_loan, float_period;
	FILE *fp;
	FILE *fp2;
	fp=fopen("customers.txt","a+");
	fp2=fopen("loan.txt","a+");
	do{
		i=0;
		k=0;
		controller=0;
		printf("\n");
		printf("===========\n"); //11
		printf("REPORT MENU\n");
		printf("===========\n"); //11
		printf("\t1. Customer List\n");
		printf("\t2. Loan Detail\n");
		printf("\t3. EXIT REPORT MENU\n");
		scanf("%d", &operator);
		switch(operator){
			case 1:
				rewind(fp);
				while(fgets(name_report, 50, fp) != NULL){
					fgets(number, 50, fp);
					integer_num=atoi(number);
					fgets(address_report, 50, fp);
					name_report[strlen(name_report)-1]='\0';
					address_report[strlen(address_report)-1]='\0';
					printf("\nCustomer ID = %d\n", i+1);
					printf("Customer Name = %s\n", name_report);
					printf("Customer Phone = %d\n", integer_num);
					printf("Customer Address = %s\n", address_report);				
					i++;
				}
				break;
			case 2:
				if(*counter==0){
					printf("There is no local variable!\n");
					printf("Returning to the MENU...\n");
					fclose(fp);
					fclose(fp2);
					return;
				}
				rewind(fp2);
				printf("Please enter the user's name and which loan you want to see?\n");
				printf("enter name: ");
				fflush(stdin);
				scanf(" %[^\n]%*c", name_check);
				printf("enter loan number: ");
				scanf("%d", &loan_check);
				while(fgets(name_report, 50, fp2) != NULL){
					fgets(loan_report, 50, fp2);
					float_loan=atof(loan_report); //loan
					fgets(period_report, 50, fp2);
					float_period=atof(period_report); //period
					name_report[strlen(name_report)-1]='\0';

					if(strcmp(name_report,name_check)==0) k++;
					if(k==loan_check){
						printf("Customer Name = %s\n", name_check);
						printf("Total Credit Value = %f\n", float_loan);
						for(t=0;t<float_period;t++){
							printf("%d. Month Installment = %f\n", t+1, float_loan/float_period);
						}
						controller=1;
						break;
					}
				}
				if(controller==0) printf("Wrong input, please try again!\n");
				break;
			case 3:
				flag=0;
				printf("Returning to the MENU...\n");
				break;
			default:
				printf("Wrong input, please try again!\n");
		}
	}while(flag);
	fclose(fp);
	fclose(fp2);
}

int main(){
	struct BankAccount bank[100];
	int flag=1, operator, counter=0;
	do{
		printf("\n");
		printf("=====================================\n"); //30
		printf("Welcome to the Bank Management System\n");
		printf("=====================================\n");
		printf("\t1. List All Customers\n");
		printf("\t2. Add New Customer\n");
		printf("\t3. New Loan Application\n");
		printf("\t4. Report Menu\n");
		printf("\t5. Exit System\n");
		scanf("%d", &operator);
		switch(operator){
			case 1:
				listCustomers(bank, &counter);
				break;
			case 2:
				if(counter==50) printf("You cannot add new customer! Limit is 50!\n");
				else addCustomer(bank, &counter);
				break;
			case 3:
				newLoan(bank);
				break;
			case 4:
				getReport(&counter);
				break;
			case 5:
				printf("\nLogged out! Take care!\n");
				flag=0;
				break;
			default:
				printf("Wrong input, please try again!\n");
		}
	}while(flag);
	return 0;
}