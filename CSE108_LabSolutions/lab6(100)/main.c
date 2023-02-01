#include <stdio.h>

void print_table(char table[][100]){ //In this function, we create the table.
	int i,j;
	int n='A',m='A';
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			table[i][j]=n;
			if(n=='Z'){
				table[i][j+1]=n;
				n='A';
			}
			else n++;
		}
		n++;
	}
	/* after this part, we make some additions to make the table look nice. */
	int k;
	char q='A';
	printf("    ");
	for(k=0;k<26;k++){ /* "ADDITIONS" */
		printf(" %c",q);
		q++;
	}
	printf("\n");
	printf(" -------------------------------------------------------\n");
	q='A';
	for(i=0;i<26;i++){ /* for the rows -> i=1 means 1. row */
		printf(" %c |", q); /* "ADDITIONS" */
		q++; 
		for(j=0;j<26;j++){ /* for the columns -> j=1 means 1. column */
			printf(" %c", table[i][j]);
		}
		printf("\n");
	}
}

void encrypt_letter(char plaintext[], char keystream[],char table[][100], char ciphertext[]){
	int i;
	char p,q;
	int m,n;
	for(i=0;i<10;i++){/* In this loop, we perform the encryption according to the table. */
		p=plaintext[i]; /* we equalize the letter to p */
		q=keystream[i]; /* we equalize the letter to q */
		m=p-'A'; /* for example, E-A=4, so table[4][] is what we need.*/
		n=q-'A'; /* for example, C-A=2, so table[][2] is what we need.*/
		ciphertext[i]=table[m][n];
	}
	ciphertext[i]='\0'; /* To avoid errors, we equalize the last elemen of the array to NULL */
}

void decrypt_letter(char plaintext[], char keystream[],char table[][100], char ciphertext[]){
	int i;
	char q;
	int m=0,n;
	for(i=0;i<10;i++){/* In this loop, we perform the decryption according to the table. */
		q=keystream[i];
		n=q-'A';/* for example, c;  2. element -> n=2;  (dikey sütun)(column) */
		for(m=0;m<26;m++){
			if(table[m][n]==ciphertext[i]){
			plaintext[i]=m+'A';
			}
		}
	}
	plaintext[i]='\0'; /* To avoid errors, we equalize the last elemen of the array to NULL */
}

int main(){/* we create our arrays for the parts. */
	char table[100][100];
	char plaintext[10],plaintext1[10];
	char key[3],key1[3];
	char keystream[10],keystream1[10];
	char ciphertext[10],ciphertext1[10];
	int i=0,j=0,p=0,y=0; /* these are for the getchar loops. */
	printf("\n");
	print_table(table); //TABLE HAS BEEN CREATED.
	char c;
	printf("\n*** ENCRYPTION ***\n\n");
	printf("Plaintext: ");
	while((c=getchar()) != '\n'){ /* we get our array using getchar in the loop. */
		plaintext[i]=c;
		i++;
	}
	plaintext[i]='\0'; //PLAINTEXT HAS BEEN CREATED.

	printf("Key: ");
	while((c=getchar()) != '\n'){ /* we get our array using getchar in the loop. */
		key[j]=c;
		j++;
	}
	key[j]='\0'; //KEY HAS BEEN CREATED.

	int k=0,m=0;
	while(k<10){ /* we create the keystream of part1 by using key of part1 */
		keystream[k]=key[m];
		m++;
		if(m==3) m=0;
		k++;
	}
	keystream[k]='\0'; //KEYSTREAM HAS BEEN CREATED.
	
	printf("Keystream: ");
	for(k=0;k<10;k++){
		printf("%c",keystream[k]);
	}

	encrypt_letter(plaintext,keystream,table,ciphertext); //ENCRYPTED.
	
	printf("\nCiphertext: ");
	for(m=0;m<10;m++){
		printf("%c",ciphertext[m]);
	}

//----------------------------------------
	printf("\n\n*** DECRYPTION ***\n\n");
	printf("Ciphertext: ");
	while((c=getchar()) != '\n'){ /* we get our array using getchar in the loop. */
		ciphertext1[p]=c;
		p++;
	}
	ciphertext1[p]='\0'; 	//CIPHERTEXT1 HAS BEEN CREATED.

	printf("Key: ");
	while((c=getchar()) != '\n'){ /* we get our array using getchar in the loop. */
		key1[y]=c;
		y++;
	}
	key1[y]='\0'; //KEY1 HAS BEEN CREATED.

	k=0,m=0;
	while(k<10){ /* we create the keystream of part2 by using key of part2 */
		keystream1[k]=key1[m];
		m++;
		if(m==3) m=0;
		k++;
	}
	keystream1[k]='\0'; //KEYSTREAM1 HAS BEEN CREATED.
	
	printf("Keystream: ");
	for(k=0;k<10;k++){
		printf("%c",keystream1[k]);
	}

	decrypt_letter(plaintext1,keystream1,table,ciphertext1); //DECRYPTED.

	printf("\nCiphertext: ");
	for(k=0;k<10;k++){
		printf("%c",plaintext1[k]);
	}
	return 0;
}