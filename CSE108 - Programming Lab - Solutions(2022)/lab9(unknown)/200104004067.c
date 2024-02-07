#include <stdio.h>
#include <string.h>
#define MIN(x,y) (((x)<(y)) ? (x) : (y)) // macro
#define THREE_MIN(a,b,c) MIN(MIN(a,b),c)

/*
 * Function: findMaximumDistance
 *
 * It does: It finds the maximum and minimum value in an array of a certain size and puts it to another array.
 *
 *
 * start: the starting index of the array (i.e. 0)
 *
 * end: the ending index of the array (ie size-1
 *
 * distanceOfCities[]: the array of integers that we received from the user
 *
 *
 * result[]: the array which containing the maximum and minimum value.
 *
 *
 * return: it does not return anything.
 *
 */
void findMaximumDistance(int distanceOfCities[], int start, int end, int result[]){
    int max=distanceOfCities[0];
    int min=distanceOfCities[0];
    int i;
    if(start==end){
        max=distanceOfCities[start];
        min=distanceOfCities[end];
    }
    else if(start+1==end){
    	if(distanceOfCities[start]<distanceOfCities[end]){
            max=distanceOfCities[end];
            min=distanceOfCities[start];
        }
        else{
            max=distanceOfCities[start];
            min=distanceOfCities[end];
        }
    }
    else{
    	for(i=0;i<end+1;i++){
	        if(distanceOfCities[i]>max){
	            max=distanceOfCities[i];
	        }
	        else if(distanceOfCities[i]<min){
	            min=distanceOfCities[i];
	        }
	    }
    }
    result[0]=max;
    result[1]=min;
}

/*
 * Function: recursiveMinStrDiff
 *
 * It does: It compares 2 strings received from the user and calculates the minimum number of operations required to make the two strings same.
 *
 *
 * m: the length of str1
 *
 * n: the length of str2
 *
 * str1[]: the 1st string we received from the user
 *
 *
 * str2[]: the 2nd string we received from the user
 *
 *
 * return: it returns the 'number of operations' performed in that loop
 *
 */
int recursiveMinStrDiff(char str1[], char str2[], int m, int n){
	int num1,num2,num3;
	if(m==0 && n==0) return 1;
	// since str2 is empty, we need operations as long as str1:
	else if(n==0 && m!=0) return m;
	// since str1 is empty, we need operations as long as str2:
	else if(m==0 && n!=0) return n;
	//if the words are the same, we don't need any operation:
	else if(strcmp(str1,str2)==0) return 0;
	//this is not an operation:
	if(str1[m]==str2[n]) return recursiveMinStrDiff(str1,str2,m-1,n-1);
	else if(str1[m]!=str2[n]){//these are the operations:
		num1=recursiveMinStrDiff(str1,str2,m,n-1);
		num2=recursiveMinStrDiff(str1,str2,m-1,n);
		num3=recursiveMinStrDiff(str1,str2,m-1,n-1);
		return 1+THREE_MIN(num1,num2,num3);
	}
}

int main(){
    int sizeofarray=5; // you can change that.
    int distanceOfCities[sizeofarray];
    int i;
    printf("\nplease enter the numbers:\n");
    for(i=0;i<sizeofarray;i++){
        scanf("%d",&distanceOfCities[i]);
    }
    //120, 200, 105, 300, 295
    int result[2];
    findMaximumDistance(distanceOfCities, 0, sizeofarray-1, result);

    printf("\nMaximum Value of Array: %d\n", result[0]);
    printf("\nMinimum Value of Array: %d\n\n\n", result[1]);

    char str1[100], str2[100];
    int m, n;
    printf("please enter the 1st string: ");
	scanf("%s",str1);
	printf("please enter the 2nd string: ");
	scanf("%s",str2);
	m=strlen(str1); //m: length of str1
	n=strlen(str2); //n: length of str2
	printf("\nThe result is: ");
	if(str1[m-1]==str2[n-1]) printf("%d\n",recursiveMinStrDiff(str1,str2,strlen(str1),strlen(str2)));	
	else if(str1[m-1]!=str2[n-1]) printf("%d\n",recursiveMinStrDiff(str1,str2,strlen(str1),strlen(str2)));

    return 0;
}