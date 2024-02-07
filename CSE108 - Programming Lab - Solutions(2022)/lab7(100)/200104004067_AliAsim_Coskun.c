#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
/*
 * Function:	concatAlphabeticReverseSort
 * ----------------------
 * It does: This function sorts the entered strings alphabetically in reverse order.
 *
 *
 *
 * n: number of strings to be entered
 *
 * MAX_LEN: maximum number of elements the array can contain
 *
 * arr: this is a 2-dimensional array of strings
 *
 *
 * 
 * catStr: this is the array where we convert the 2-dimensional array(arr) to 1-dimension(catStr).
 *
 *
 *
 * returns: we do not return anything.
 *
 */
void concatAlphabeticReverseSort(char arr[][MAX_LEN], int n, char catStr[]){
	int k,l;
	char temp[MAX_LEN];
	printf("enter the strings...\n");
	for(k=0;k<n;k++){
		scanf("%s",arr[k]);
	}

	printf("\nGiven array is\n");
	for(k=0;k<n;k++){
		printf("%d: %s\n", k, arr[k]);
	}

	for(k=0;k<n;k++){
		for(l=k;l<n;l++){
			if(k==l);
			else if(strcmp(arr[k], arr[l]) < 0){
				strcpy(temp, arr[k]);
				strcpy(arr[k], arr[l]);
				strcpy(arr[l], temp);
			}
		}
	}

	printf("\nSorted array is\n");
	for(k=0;k<n;k++){
		printf("%d: %s\n", k, arr[k]);
	}

	int m;
	for(m=0;m<n;m++){
		strcat(catStr, arr[m]);
	}
}
/*
 * Function:	generateTagParserCustomized
 * ----------------------
 * It does: deletes the first and last letter of the entered string and adds symbols 
 * 			to the beginning and end of the string according to the length of the string.
 *
 * temp: the temporary array where we combine symbols and array
 *
 * arr: one dimensional array we get from user
 *
 *
 *
 * returns: we do not return anything.
 *
 */
void generateTagParserCustomized(char temp[], char arr[]){
int l, i;
	char case1[4]={"<<>>"};
	char case2[2]={"**"};
	char case3[4]={"/++/"};

    for (l = 0; arr[l] != '\0'; ++l); //Length of the string=l;
    
	if(l<5){
		temp[0]=case1[0];
		temp[1]=case1[1];
		for(i=0;i<l-1;i++){
			strcpy(&temp[i+2],&arr[i+1]);
		}
		temp[2+l-2]=case1[2];
		temp[2+l+-1]=case1[3];
		temp[2+l]='\0';
	}
	else if(5<=l && l<=10){
		temp[0]=case2[0];
		for(i=0;i<l-1;i++){
			strcpy(&temp[i+1],&arr[i+1]);
		}
		temp[1+l-2]=case2[1];
		temp[1+l-1]='\0';
	}
	else if(l>10){
		temp[0]=case3[0];
		temp[1]=case3[1];
		for(i=0;i<l-1;i++){
			strcpy(&temp[i+2],&arr[i+1]);
		}
		temp[2+l-2]=case3[2];
		temp[2+l-1]=case3[3];
		temp[2+l]='\0';
	}
	
	for(i=0;i<l+2;i++){
		strcpy(arr,temp);
	}
}

int main(){
	char part1arr[MAX_LEN][MAX_LEN]; //part1
	char catStr[MAX_LEN]; 			 //part1
	int n; 							 //part1
	char part2arr[MAX_LEN]; 	//part2
	char temp[MAX_LEN]; 		//part2

	int operator, flag=1;
	do{
		printf("\n\nChoose the number of part.\n1-Reverse Sort\n2-generateTagParser\n3-EXIT!\n");
		scanf("%d", &operator);
		switch(operator){
			case 1:
				printf("enter the count of how many strings you will enter...\n");
				scanf("%d",&n);
				concatAlphabeticReverseSort(part1arr, n, catStr);
				printf("Result is:\n%s\n", catStr);
				break;
			case 2:
				printf("\nEnter a string: ");
				scanf("%s", part2arr);

				generateTagParserCustomized(temp, part2arr);
				printf("%s", part2arr);
				break;
			case 3:
				flag=0;
				break;
			default:
				printf("wrong number. please try again.\n");
		}
	}while(flag);


	
	

	return 0;
}