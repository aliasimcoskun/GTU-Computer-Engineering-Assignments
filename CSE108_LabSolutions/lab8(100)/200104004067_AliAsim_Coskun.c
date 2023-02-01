#include <stdio.h>
#include <string.h>

/*
 * Function: reverse
 *
 * It does: reverse the string to another string and checks is it palindrome or not
 *
 * str: the original string that entered from user.
 *
 *
 *
 * reversed: the reversed string
 *
 *
 * i: starts from 0 and goes to end of the string with recursion.
 *
 * return: this function does not return anything.
 */
void reverse(char str[], char reversed[], int i)
{
    int len = strlen(str);
    int y=len-1;
    int x;
    for(x=0; x<len; x++){
        reversed[x]=str[y];
        y--;
    }
    reversed[len]=='\0';
    
    if(str[i] == reversed[i]){
        if(i==len-1) printf("It is a palindrome\n\n\n");
        else reverse(str, reversed, i+1);   //recursion
    }
    else printf("It is NOT a palindrome\n\n\n");
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
    // Create L <- A[p..q] and M <- A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i,j,k;
    i = 0;
    j = 0;
    k = p;

    //Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

/*
 * Function: mergeSort
 *
 * It does: sorts the array by splitting it into parts, then merges it.
 *
 * arr: the string which has the numbers that will be sorted.
 *
 *
 *
 * l: the beginning of the string
 *
 * r: the last index of the string
 *
 * return: this function does not return anything.
 */
void mergeSort(int arr[], int l, int r)
{
    int middle;
    if(l>=r);
    else {
        middle = l + (r - l) / 2;

        mergeSort(arr, l, middle); // begining of the string to middle of the string

        mergeSort(arr, middle + 1, r); // middle+1 of the string to end of the string

        merge(arr, l, middle, r);
    }
}

int main(){/* main function */
    char str[100], reversed[100];
    int array[]={6,5,12,10,9,1};
 
    printf("check is it a palindrome:\n");
    scanf("%s", str);
    
    reverse(str, reversed, 0);
    
    int arr_size = sizeof(array) / sizeof(array[0]);
    int i;
    
    printf("original array is \n");
    for(i=0;i<arr_size;i++)
        printf("%d ", array[i]);
    
    
    mergeSort(array, 0, arr_size-1);

    printf("\n\nsorted array is \n");
    for(i=0;i<arr_size;i++)
        printf("%d ", array[i]);
    return 0;
}