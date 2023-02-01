#include <stdio.h>
//kernel -1 1 -1

void display(int dizi[][10]){/* in this function, we print the matrices on the screen. */
	int i, j;

	for (i = 0; i < 3; ++i){
		for (j = 0; j < 3; ++j) {
			printf("%d\t", dizi[i][j]);
			if (j == 2)
				printf("\n");
		}
	}
}

void dizi_al2(int dizi[][10]){/* in this function, we take the 2D matrices from the user. */
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &dizi[i][j]);
		}
	}	

}

void dizi_al(int dizi[]){/* in this function, we take the 1D matrices from the user. */
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&dizi[i]);
	}
}

void kernel_operation(int dizi[], int kernel[]){/* in this function, we make the filter operation with kernel. */
	int i, j;
	int filtered[8];
	int temp[3];
	int id;
	//for (id=0; id<3; id++) printf("D: %d ", kernel[id]);

	for(i=0;i<8;i++){/* filtered matrice has to have 8 elements. */
		for(j=0;j<3;j++){/* in this loop, we execute the each element's operation */
			temp[j]=dizi[i]*kernel[j];
			i++;
		}
		i=i-3;
		filtered[i]=temp[0]+temp[1]+temp[2]; /* that is why filtered matrice has to have 8 elements. */
	}
	//int id;
	for (id=0; id<8; id++) printf("%d\t", filtered[id]);
}

void multi_of_matrix(int first[][10], int second[][10], int result[][10])
{
	int i, j, k;

	for (i = 0; i < 3; ++i) {/* we equalize elements of matrix of 0 */
		for (j = 0; j < 3; ++j) {
			result[i][j] = 0;
		}
	}

	for (i = 0; i < 3; ++i) { /*we are multiplying first and second matrices and storing it in result */
		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				result[i][j] += first[i][k] * second[k][j];
			}
		}
	}
}

int main(){/* we specify the variables which are required below cases. */
	int op, flag=1;
	int dizi[10];
	int kernel[3]={-1, 1, -1};
	int a[10][10], a3[10][10];
	int a1[10][10], a2[10][10];
	int transpose[10][10], transpose1[10][10];
	int Trace[10][10], Trace1[10][10];
	int multi[10][10];
	int i, j;
	do{
		printf("\nChoose the matrix operation\n------------------------------\n1. Convolutional Filter for 1D array\n2. Multiplication\n3. Trace\n4. Transpose\n5. Exit\n------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &op);
		switch(op){
		case 1:
			printf("ID Array\n"); /* we take the 1D matrice from the user. */
			dizi_al(dizi);
			printf("\nConvolutional Filter Result:\n");
			kernel_operation(dizi, kernel);
			printf("\n---------------------------------------------------------------------------\n");
			break;
		case 2:
			printf("\nFirst Matrix\n"); /* we take the 2D matrice from the user. */
			dizi_al2(a1); 
			printf("Second Matrix: \n"); /* we take the 2D matrice from the user. */
			dizi_al2(a2); 
			printf("-------------------------\n");
			multi_of_matrix(a1, a2, multi); /* computing the multiplication */

			printf("Multiplication of matrix:\n"); /* printing the result of multiplication. */
			display(multi);
			printf("-------------------------\n");
			break;
		case 3:
			printf("First Matrix:\n"); /* we take the 2D matrice from the user. */
			int trace = 0;
			dizi_al2(Trace);
			printf("Second Matrix:\n"); /* we take the 2D matrice from the user. */
			dizi_al2(Trace1);
			printf("-------------------------\n");
			printf("\nTrace of the first matrix:\n"); 
			display(Trace);
			for (i=0; i<3; i++) /* computing the trace */
			{
				for (j=0; j<3; j++)
				{
					if (i == j)
					{
						trace = trace + Trace[i][j];
					}
				}
			}
			printf("Trace of matrix is: %d\n", trace); /* printing the first trace */
			printf("\nTrace of the second matrix:\n");
			display(Trace1);
			
			trace=0;
			for (i=0; i<3; i++){/* computing the trace */
				for (j=0; j<3; j++){
					if (i == j){
						trace = trace + Trace1[i][j];
					}
				}
			}
			printf("Trace of matrix is: %d\n", trace); /* printing the second trace */
			printf("-------------------------\n");
			break;
		case 4:
			printf("First Matrix:\n"); /* we take the 2D matrice from the user. */
			dizi_al2(a);
			printf("Second Matrix:\n"); /* we take the 2D matrice from the user. */
			dizi_al2(a3);
			printf("-------------------------\n");

			for (i = 0; i < 3; i++){/* computing the transpose */
				for (j = 0; j < 3; j++) {
					transpose[j][i] = a[i][j];
				}
			}

			printf("\nTranspose of the first matrix:\n"); /* printing the first transpose */
			display(transpose);
			for (i = 0; i < 3; i++){/* computing the transpose */
				for (j = 0; j < 3; j++) {
					transpose1[j][i] = a3[i][j];
				}
			}
			printf("Transpose of the second matrix:\n"); /* printing the second transpose */
			display(transpose1);
			printf("-------------------------\n");
			break;
		case 5:/* if the user wants to quit. */
			flag=0;
			break;
		default:/* if the user enters wrong value. */
			printf("you entered something wrong.");
		}
	}while(flag);

return 0;
}