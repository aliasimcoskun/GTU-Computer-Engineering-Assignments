#include <stdio.h>
#include <stdlib.h>

typedef struct{/* struct which is given by teacher. */
    int *array;
    int currentsize;
}dynamic_array;

int *resize_array(int*,int);

/* Function: read_from_file
 *
 * It does: It takes the numbers from the txt file and puts them in the array inside the struct.
 *
 * fp: the txt file where we read numbers.
 *
 * strct: the struct where we put the numbers we get from the txt.
 *
 *
 * 
 * return: we return the struct where we put the numbers.
 *
 */
dynamic_array read_from_file(FILE *fp, dynamic_array strct){
    int i=0;
    strct.currentsize=0;
    while(!feof(fp)){
        fscanf(fp,"%d\n",(strct.array+i));
        i++;
        strct.currentsize++;
        strct.array=resize_array(strct.array, strct.currentsize);
    }
    return strct;
}

/* Function: removeData
 *
 * It does: it removes the number you selected from the array and assigns it to a new array.
 *
 * arr: the struct where we put the numbers we get from the txt.
 *
 * 
 *
 * number: the number the user chooses to remove from the array.
 * 
 * return: we return the struct, which is the removed version of the number.
 *
 */
dynamic_array removeData(dynamic_array arr, int number){
    int x=0,y=0;
    dynamic_array removed;
    while(y<arr.currentsize)
    {
        if(arr.array[y] == number) removed.currentsize--;
        else{
            removed.array[x] = arr.array[y];
            x++;
        }
        y++;
    }
    return removed;
}

/* Function: resize_array
 *
 * It does: it increases the size of the array by 1 to be able to add another element to the array.
 *
 * array: the array inside the struct where we put the numbers.
 *
 * 
 *
 * currentsize: the size of the array at the time the function is called.
 * 
 * return: we return the array whose size is increased by 1
 *
 */
int *resize_array(int *array, int currentsize){
    int *temp = (int*)calloc((currentsize+1),sizeof(int));
    int i;
    for(i=0;i<currentsize;i++){
        temp[i]=array[i];
    }
    return temp;
}

/* Function: print_array
 *
 * It does: it prints the array that passed as a parameter.
 *
 * strct: the struct where we put the numbers we get from the txt.
 *
 *
 * 
 * return: we don't return anything.
 *
 */
void print_array(dynamic_array strct){
    int i;
    for (i=0;i<strct.currentsize;i++){
        printf("%d ",strct.array[i]);
    }
}

int main(){/* main function */
    FILE *fp;
    fp=fopen("integers.txt","r");

    dynamic_array strct;
    strct.array = (int*)calloc((1),sizeof(int));//firstly
    strct=read_from_file(fp,strct);
    fclose(fp);

    printf("\n\nData in source file\n");
    print_array(strct);

    int number;
    printf("\n\nEnter the number you want to be deleted: ");
    scanf("%d", &number);
    strct=removeData(strct,number);
    print_array(strct);
    return 0;
}