#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function:	random_number_0_to_49
 * ----------------------
 * It does: dividing each number by 50 to obtain a number in the range [0,50).
 *
 *
 *
 * returns: it returns that number which is between [0,50).
 *
 */
int random_number_0_to_49(){
	int random;
	random = (rand() % 50);
	return random;
}

/*
 * Function:	random_char_a_to_z
 * ----------------------
 * It does: dividing each number by 26 and adding 97 to the remainder to pick a letter between 'a' and 'z'.
 *
 *
 *
 * returns: it returns that letter which is between 'a' and 'z'.
 *
 */
char random_char_a_to_z(){
	char random;
	random = (rand() % 26) + 'a'; //0 to 25
	return random;
}

/*
 * Function:	random_number_0_to_14
 * ----------------------
 * It does: dividing each number by 15 to obtain a number in the range [0,15).
 *
 *
 *
 * returns: it returns that number which is between [0,15).
 *
 */
int random_number_0_to_14(){
	int random;
	random = (rand() % 15);
	return random;
}

/*
 * Function:	straight_or_diagonal
 * ----------------------
 * It does: dividing each number by 2 to determine whether it is straight or diagonal.
 *
 *
 *
 * returns: it returns that number which is 0 or 1.
 *
 */
int straight_or_diagonal(){//0 straight //1 diagonal
	int random;
	random = (rand() % 2);
	return random;
}

/*
 * Function:	up_or_down
 * ----------------------
 * It does: dividing each number by 2 to determine whether it is up or down.
 *
 *
 *
 * returns: it returns that number which is 0 or 1.
 *
 */
int up_or_down(){//0 up //1 down
	int random;
	random = (rand() % 2);
	return random;
}

/*
 * Function:	left_or_right
 * ----------------------
 * It does: dividing each number by 2 to determine whether it is left or right.
 *
 *
 *
 * returns: it returns that number which is 0 or 1.
 *
 */
int left_or_right(){//0 left //1 right
	int random;
	random = (rand() % 2);
	return random;
}

/*
 * Function:	horizontal_or_vertical
 * ----------------------
 * It does: dividing each number by 2 to determine whether it is horizontal or vertical.
 *
 *
 *
 * returns: it returns that number which is 0 or 1.
 *
 */
int horizontal_or_vertical(){//0 horizontal //1 vertical	//for straight
	int random;
	random = (rand() % 2);
	return random;
}

void red(){/* it turns the output red. */
  printf("\033[1;31m");
}
void reset(){/* it resets the color of the output. */
  printf("\033[0m");
}

/*
 * Function:	getting_words_to_array
 * ----------------------
 * It does: puts all words in txt into an array.
 *
 * 
 * 
 * words[][100]: the array where we get the all words.
 * 
 *
 *
 * returns: we do not return anything.
 *
 */
void getting_words_to_array(char words[][100]){
	int i=0;
	FILE *fp;
	fp=fopen("wordlist.txt","r");
	if(fp==NULL) printf("the file does not open.\n");
	else{
		while(!feof(fp)){
			fscanf(fp, "%s\n", words[i]);
			i++;
		}
	}
	fclose(fp);
}

/*
 * Function:	picking_random_7_words
 * ----------------------
 * It does: It randomly selects 7 words from 50 words and puts them in an array.
 *
 * 
 * 
 * words[][100]: the array where we get the all words.
 * 
 *
 *
 * sevenwords[][100]: the array where we get 7 random words.
 * 
 * 
 * 
 * returns: we do not return anything.
 *
 */
void picking_random_7_words(char words[][100], char sevenwords[][100]){
	int i, a, k;
	int check[100];
	for(i=0;i<7;i++){ //takes random 7 numbers
		a=random_number_0_to_49();
		for(k=0;k<i;k++){ //provides us to get each word at most 1 time
            if(check[k]==a){
				a=random_number_0_to_49();
				k=-1; //I set it to -1 to start with 0 in the next loop.
			}
		}
        check[i]=a;
		strcpy(sevenwords[i],words[a]);
	}
	sevenwords[i][0]='\0';
}

/*
 * Function:	building_board
 * ----------------------
 * It does: creates a 15x15 table which consist of random letters.
 *
 * 
 * 
 * board[][100]: 2D array where we put the 15x15 table.
 * 
 *
 *
 * returns: we do not return anything.
 *
 */
void building_board(char board[][100]){
	int i, j;
	char a;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			a = random_char_a_to_z();
            board[i][j] = a;
		}
	}
}

/*
 * Function:	filling_board
 * ----------------------
 * It does: it places each word on the table in random directions and in random places.
 *
 * 
 * 
 * sevenwords[][100]: the array where we get 7 random words.
 * 
 *
 *
 * board[][100]: 2D array where we put the 15x15 table.
 * 
 * 
 * 
 * start_point[][100]: starting points of words which are randomly placed in the table.
 * 
 * 
 * 
 * finish_point[][100]: finish points of words which are randomly placed in the table.
 * 
 * 
 * 
 * returns: we do not return anything.
 *
 */
void filling_board(char sevenwords[][100], char board[][100], int start_point[][100], int finish_point[][100]){
	int i, j, k, m, u, l, v, r1, r2, direction, length;
	int check_overlap1, check_overlap2, control=0, sp1, sp2;
	char check[100][100];
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			check[i][j]=' ';
		}
	}
	for(k=0;k<7;k++){
		i=0;
		direction = straight_or_diagonal();
		r1 = random_number_0_to_14();
		r2 = random_number_0_to_14();
		length=strlen(sevenwords[k]);
		check_overlap1=r1;
		check_overlap2=r2;
        if(control==0) printf("THE WORD:  %s\n", sevenwords[k]);
		printf("starting point: (%d, %d)\n", r1, r2);
        control=0;
		if(direction==1){ //diagonal
			if((length+r2>14) && (r1-length<-1)) //to the left & down
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    check_overlap1=check_overlap1+1;
                    check_overlap2=check_overlap2-1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					r1=r1+1;
					r2=r2-1;
					i++;
				}
				if(control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2+1);
                }
			}
			else if((length+r2>14) && (length+r1>14)) //to the left && up
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    check_overlap1=check_overlap1-1;
                    check_overlap2=check_overlap2-1;
				}
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					r1=r1-1;
					r2=r2-1;
					i++;
				}
				if(control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2+1);
                }
			}
			else if((r2-length<-1) && (r1-length<-1)) //to the right && down
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    check_overlap1=check_overlap1+1;
                    check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					r1=r1+1;
					r2=r2+1;
					i++;
				}
				if(control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2-1);
                }

			}
			else if((r2-length<-1) && (length+r1>14)) //to the right && up
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    check_overlap1=check_overlap1-1;
                    check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					r1=r1-1;
					r2=r2+1;
					i++;
				}
				if(control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2-1);
                }
			}
			else if(length+r2>14){ //to the left (up or down)
				u=up_or_down();
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(u==0){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2-1;
                    }
                    if(u==1){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2-1;
                    }
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(u==0){//up-left
						r1=r1-1;
						r2=r2-1;
					}
					if(u==1){//down-left
						r1=r1+1;
						r2=r2-1;
					}
					i++;
				}
				if(u==0 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2+1);
                }
				if(u==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2+1);
                }
			}
			else if(r2-length<-1){ //to the right (up or down)
				u=up_or_down();
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(u==0){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2+1;
                    }
                    if(u==1){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2+1;
                    }
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(u==0){//up-right
						r1=r1-1;
						r2=r2+1;
					}
					if(u==1){//down-right
						r1=r1+1;
						r2=r2+1;
					}
					i++;
				}
				if(u==0 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2-1);
                }
				if(u==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2-1);
                }
			}
			else if(r1-length<-1){ //to the down (left or right)
				l=left_or_right();
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(l==0){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2-1;
                    }
                    if(l==1){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2+1;
                    }
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(l==0){//left-down
						r1=r1+1;
						r2=r2-1;
					}
					if(l==1){//right-down
						r1=r1+1;
						r2=r2+1;
					}
					i++;
				}
				if(l==0 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2+1);
                }
				if(l==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2-1);
                }
			}
			else if(length+r1>14){ //to the up (left or right)
				l=left_or_right();
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(l==0){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2-1;
                    }
                    if(l==1){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2+1;
                    }
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(l==0){//left-up
						r1=r1-1;
						r2=r2-1;
					}
					if(l==1){//right-up
						r1=r1-1;
						r2=r2+1;
					}
					i++;
				}
				if(l==0 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2+1);
                }
				if(l==1 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2-1);
                }
			}
			else{
				u=up_or_down();
				l=left_or_right();
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(l==0 && u==0){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2-1;
                    }
                    if(l==1 && u==0){
                        check_overlap1=check_overlap1-1;
                        check_overlap2=check_overlap2+1;
                    }
                    if(l==0 && u==1){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2-1;
                    }
                    if(l==1 && u==1){
                        check_overlap1=check_overlap1+1;
                        check_overlap2=check_overlap2+1;
                    }
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(l==0 && u==0){//left-up
						r1=r1-1;
						r2=r2-1;
					}
					if(l==1 && u==0){//right-up
						r1=r1-1;
						r2=r2+1;
					}
					if(l==0 && u==1){//left-down
						r1=r1+1;
						r2=r2-1;
					}
					if(l==1 && u==1){//right-down
						r1=r1+1;
						r2=r2+1;
					}
					i++;
				}
				if(l==0 && u==0 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2+1);
                }
				if(l==1 && u==0 && control==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2-1);
                }
				if(l==0 && u==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2+1);
                }
				if(l==1 && u==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2-1);
                }
			}
		}
		if(direction==0){ //straight
			u=up_or_down();
			l=left_or_right();
			v=horizontal_or_vertical(); //0 horizontal //1 vertical
			if((length+r2>14) && (r1-length<-1)) //upper right corner
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1+1;
                    if(v==0) check_overlap2=check_overlap2-1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==0) r2=r2-1;
					if(v==1) r1=r1+1;
					i++;
				}
				if(v==0 && control==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(v==1 && control==0){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
			}
			else if((r2-length<-1) && (r1-length<-1)) //upper left corner
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1+1;
                    if(v==0) check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==1) r1=r1+1;
					if(v==0) r2=r2+1;
					i++;
				}
				if(control==0 && v==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
                if(control==0 && v==1){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
			}
			else if((length+r2>14) && (length+r1>14)) //bottom right corner
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1-1;
                    if(v==0) check_overlap2=check_overlap2-1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==1) r1=r1-1;
					if(v==0) r2=r2-1;
					i++;
				}
				if(control==0 && v==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(control==0 && v==1){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
			}
			else if((r2-length<-1) && (length+r1>14)) //bottom left corner
			{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1-1;
                    if(v==0) check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==1) r1=r1-1;
					if(v==0) r2=r2+1;
					i++;
				}
				if(control==0 && v==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
                if(control==0 && v==1){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
			}
            else if(r2-length<-1){//left edge
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==0) check_overlap2=check_overlap2+1;
                    if(v==1 && u==0) check_overlap1=check_overlap1-1;
                    if(v==1 && u==1) check_overlap1=check_overlap1+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==0) r2=r2+1;
                    if(v==1 && u==0) r1=r1-1;
                    if(v==1 && u==1) r1=r1+1;
					i++;
				}
				if(control==0 && v==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
                if(control==0 && v==1 && u==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
                if(control==0 && v==1 && u==1){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
            }
            else if(length+r2>14){//right edge
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==0) check_overlap2=check_overlap2-1;
                    if(v==1 && u==0) check_overlap1=check_overlap1-1;
                    if(v==1 && u==1) check_overlap1=check_overlap1+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==0) r2=r2-1;
                    if(v==1 && u==0) r1=r1-1;
                    if(v==1 && u==1) r1=r1+1;
					i++;
				}
				if(control==0 && v==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(control==0 && v==1 && u==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
                if(control==0 && v==1 && u==1){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
            }
            else if(r1-length<-1){//top edge
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1+1;
                    if(v==0 && l==0) check_overlap2=check_overlap2-1;
                    if(v==0 && l==1) check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==1) r1=r1+1;
                    if(v==0 && l==0) r2=r2-1;
                    if(v==0 && l==1) r2=r2+1;
					i++;
				}
				if(control==0 && v==1){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
                if(control==0 && v==0 && l==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(control==0 && v==0 && l==1){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
            }
            else if(length+r1>14){//bottom edge
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==1) check_overlap1=check_overlap1-1;
                    if(v==0 && l==0) check_overlap2=check_overlap2-1;
                    if(v==0 && l==1) check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
				while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==1) r1=r1-1;
                    if(v==0 && l==0) r2=r2-1;
                    if(v==0 && l==1) r2=r2+1;
					i++;
				}
				if(control==0 && v==1){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
                if(control==0 && v==0 && l==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(control==0 && v==0 && l==1){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
            }
			else{
                for(m=0;m<length;m++){
                    if(check[check_overlap1][check_overlap2]!=' '){
                        k=k-1;
                        printf("There are OVERLAP! Another starting point is determined...\n");
                        control=1;
                        break;
                    }
                    if(v==0 && l==0) check_overlap2=check_overlap2-1;
                    if(v==0 && l==1) check_overlap2=check_overlap2+1;
                    if(v==1 && u==0) check_overlap1=check_overlap1-1;
                    if(v==1 && u==1) check_overlap2=check_overlap2+1;
                }
                if(control==0){
                    start_point[k][0]=r1;
                    start_point[k][1]=r2;
                }
                while(sevenwords[k][i]!='\0'){
					if(control==1) break;
					check[r1][r2]=sevenwords[k][i];
					board[r1][r2]=sevenwords[k][i];
					if(v==0 && l==0) r2=r2-1;
                    if(v==0 && l==1) r2=r2+1;
                    if(v==1 && u==0) r1=r1-1;
                    if(v==1 && u==1) r1=r1+1;
					i++;
				}
                if(control==0 && v==0 && l==0){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2+1;
                    printf("finish point: (%d, %d)\n\n", r1, r2+1);
                }
                if(control==0 && v==0 && l==1){
                    finish_point[k][0]=r1;
                    finish_point[k][1]=r2-1;
                    printf("finish point: (%d, %d)\n\n", r1, r2-1);
                }
                if(control==0 && v==1 && u==0){
                    finish_point[k][0]=r1+1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1+1, r2);
                }
                if(control==0 && v==1 && u==1){
                    finish_point[k][0]=r1-1;
                    finish_point[k][1]=r2;
                    printf("finish point: (%d, %d)\n\n", r1-1, r2);
                }
            }
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
    printf("\n\n  -------THE ANSWER KEY-------  \n\n");
    for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ", check[i][j]);
		}
		printf("\n");
	}
}

/*
 * Function:	filling_board
 * ----------------------
 * It does: it places each word on the table in random directions and in random places.
 * 
 *
 *
 * board[][100]: 2D array where we put the 15x15 table.
 * 
 * 
 * 
 * start_point[][100]: starting points of words which are randomly placed in the table.
 * 
 * 
 * 
 * finish_point[][100]: finish points of words which are randomly placed in the table.
 * 
 * 
 * 
 * sevenwords[][100]: the array where we get 7 random words.
 * 
 * 
 * 
 * returns: we do not return anything.
 *
 */
void solving(char board[][100], int start_point[][100], int finish_point[][100], char sevenwords[][100]){
    char temp, temp0, compare[100], temp1[10], temp2[10];
    int c1, c2, i, m, k, j, fp1, fp2, sp1, sp2, comp1, comp2;
    int point=0, mistake=3, flag=0, win=0, gameover=0, quit=0;
    do{
        printf("Enter coordinates and word:");
        scanf("%s", temp1);
        if(temp1[0]==':' && temp1[1]=='q' && temp1[2]=='\0'){
            quit=1;
            break;
        }
        scanf("%s %s", temp2, compare);
        if(temp1[1]=='\0'){
            temp=temp1[0];
            c1=temp-48;
        }
        if(temp1[1]!='\0' && temp1[2]=='\0'){
            temp0=temp1[0];
            temp=temp1[1];
            c1=10*(temp0-48)+(temp-48);
        }
        if(temp2[1]=='\0'){
            temp=temp2[0];
            c2=temp-48;
        }
        if(temp2[1]!='\0' &&  temp2[2]=='\0'){
            temp0=temp2[0];
            temp=temp2[1];
            c2=10*(temp0-48)+(temp-48);
        }
        for(i=0;i<7;i++){
            m=0;
            if(start_point[i][0]==c1 && start_point[i][1]==c2){
                flag=1;
                fp1=finish_point[i][0];
                sp1=start_point[i][0];
                fp2=finish_point[i][1];
                sp2=start_point[i][1];
                comp1=fp1-sp1;
                comp2=fp2-sp2;
                while(sevenwords[i][m]!='\0'){
                    if(comp1>0 && comp2>0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1 || sp2==fp2) break;
                        sp1=sp1+1;
                        sp2=sp2+1;
                    }
                    else if(comp1>0 && comp2<0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1 || sp2==fp2) break;
                        sp1=sp1+1;
                        sp2=sp2-1;
                    }
                    else if(comp1<0 && comp2<0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1 || sp2==fp2) break;
                        sp1=sp1-1;
                        sp2=sp2-1;
                    }
                    else if(comp1<0 && comp2>0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1 || sp2==fp2) break;
                        sp1=sp1-1;
                        sp2=sp2+1;
                    }
                    else if(comp1==0 && comp2<0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp2==fp2) break;
                        sp2=sp2-1;
                    }
                    else if(comp1==0 && comp2>0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp2==fp2) break;
                        sp2=sp2+1;
                    }
                    else if(comp1<0 && comp2==0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1) break;
                        sp1=sp1-1;
                    }
                    else if(comp1>0 && comp2==0){
                        if((board[sp1][sp2]=='X') || (strcmp(compare,sevenwords[i])!=0)) {
                            flag=0;
                            break;
                        }
                        board[sp1][sp2]='X';
                        if(sp1==fp1) break;
                        sp1=sp1+1;
                    }
                    m++;
                }
            }
        }

        for(k=0;k<15;k++){//reprints the table in every loop
            for(j=0;j<15;j++){
                if(board[k][j]=='X') red();
                printf("%c ", board[k][j]);
                reset();
            }
            printf("\n");
        }

        if(flag==0){//wrog answer
            mistake=mistake-1;
            if(mistake==0){
                gameover=1;
                break;
            }
            printf("Wrong choice! You have only %d lefts\n\n", mistake);
        }
        if(flag==1){//correct answer
            point=point+2;
            printf("Founded! You got 2 points. Your total points: %d\n\n", point);
            flag=0;
        }

        win=1;
        for(i=0;i<7;i++){//win=0 if all 7 words are not covered with X
            sp1=start_point[i][0];
            sp2=start_point[i][1];
            if(board[sp1][sp2]!='X') win=0;
        }
        if(win==1) break;
    }while(quit==0);

    if(win==1){
        printf("\nYou won! Your total points are: %d\n", point);
    }
    if(gameover==1){
        printf("\nGame is over! You lost! Your points are: %d\n", point);
    }
    if(quit==1){
        printf("\nYou quit the game! Your total points are: %d\n", point);
    }
}

int main(){
	char words[100][100]; // all 50 words.
	char sevenwords[100][100]; // randomly picked 7 words.
	srand(time(NULL));
	
	getting_words_to_array(words);
	picking_random_7_words(words, sevenwords);

	char board[100][100];
	building_board(board);
    printf("\n");
	int start_point[100][100], finish_point[100][100]; // coordinates.
	filling_board(sevenwords, board, start_point, finish_point);
    solving(board, start_point, finish_point, sevenwords);

	return 0;
}