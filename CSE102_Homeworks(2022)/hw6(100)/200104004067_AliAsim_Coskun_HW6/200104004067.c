#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void yellow(){/* it turns the output yellow */
	printf("\033[1;33m");
}

void red(){/* it turns the output red */
	printf("\033[1;31m");
}

void cyan(){/* it turns the output cyan */
	printf("\033[0;36m");
}

void green(){/* it turns the output green */
	printf("\033[0;32m");
}

void reset(){/* it resets the color of the output */
	printf("\033[0m");
}

/*
 * Function:	dice
 * ----------------------
 * It does: dividing each number by 6 and adding 1 to the remainder to obtain a number in the range [1,6].
 *
 *
 *
 * returns: it returns that number(between [1,6])
 *
 */
 
int dice(){
	int random;
	random=(rand() % 6)+1;
	return random;	
}

/*
 * Function:	dice_for_player1
 * ----------------------
 * It does: it warns if a character other than '\n' is entered (for player 1)
 *
 *
 *
 * a: return value of dice()
 *
 * d: the variable that '\n' should be entered.
 *
 * f: second variable that provides the '\n' check
 *
 * returns: random number between [1,6].
 *
 */
 
int dice_for_player1(){
	char d,f;
	int a;
	yellow();
	do{
		printf("PLAYER 1... press ENTER to dice... ");
		scanf("%c", &d);
		if(d!='\n'){
			scanf("%c", &f);
			if(f!='\n') while (getchar() != '\n');
		}
		if(d!='\n') printf("wrong input, please try again!\n");
	}while(d!='\n');
	
	a=dice();
	printf("DICE: %d\n", a);
	reset();
	
	return a;
}

/*
 * Function:	dice_for_player2
 * ----------------------
 * It does: it warns if a character other than '\n' is entered (for player 2)
 *
 *
 *
 * b: return value of dice()
 *
 * d: the variable that '\n' should be entered.
 *
 * f: second variable that provides the '\n' check
 *
 * returns: random number between [1,6].
 *
 */
 
int dice_for_player2(){
	char d,f;
	int b;
	cyan();
	do{
		printf("PLAYER 2... press ENTER to dice... ");
		scanf("%c", &d);
		if(d!='\n'){
			scanf("%c", &f);
			if(f!='\n') while (getchar() != '\n');
		}
		if(d!='\n') printf("\nwrong input, please try again!\n");
	}while(d!='\n');

	b=dice();
	printf("DICE: %d\n", b);
	reset();
	
	return b;
}

/*
 * Function:	startGame
 * ----------------------
 * It does: it provides 2 players to roll the dice and also decides which player to start the game
 *
 *
 *
 * a: dice_for_player1's return value
 *
 * b: dice_for_player2's return value
 *
 * returns: it returns the number of the player who will start the game.
 *
 */

int startGame(){
	int a,b;
	printf("\n\nTo start to game, players should dice and decide who is going to start first according to it...\n");
	do{
		a=dice_for_player1();
		b=dice_for_player2();
		if(a==b) printf("Same dice value... Please try again.\n");
	}while(a==b);
	if(a>b){
		printf("\n\n *** PLAYER 1 will start the game... ***\n");
		return 1;
	}
	if(b>a){
		printf("\n\n *** PLAYER 2 will start the game... ***\n");
		return 2;
	}
}

/*
 * Function:	createArrayofMap
 * ----------------------
 * It does: puts the entire game map in a two-dimensional array
 *
 *
 *
 * a[][100]: array where we put the whole game map
 *
 *
 *
 * m: Roadmap for player 1 -> By adding the number on the dice to this variable, the path of the 1st player is determined.
 *
 * n: Roadmap for player 2 -> By adding the number on the dice to this variable, the path of the 2nd player is determined.
 *
 * p[]: when the player reaches the penalty point, it makes him/her go back 2 steps
 *
 *
 *
 *
 * temp & temp1: it provides us not to print the space character on '1' & '2'
 *
 * penalty1 & penalty2: it provides penalty point control for print, for player 1 & player 2
 *
 * returns: we do not return anything. 
 *
 */

void createArrayofMap(char a[][100], int m, int n, char p[]){

	int y, x, i;
	int temp=0, temp1=0, penalty1=0, penalty2=0;

	for(y=0;y<15;y++){
		for(x=0;x<30;x++){
			
			if(y==0 || y==14) a[y][x]='.';
			else if(x==0 || x==29) a[y][x]=':';
			
			else if((y==2 || y==12) && 2<=x && x<=27) a[y][x]='.';
			else if((x==2 || x==27) && 3<=y && y<=11) a[y][x]=':';
			
			else if((y==4 || y==10) && 4<=x && x<=25) a[y][x]='.';
			else if((x==4 || x==25) && 5<=y && y<=9) a[y][x]=':';
			
			else if((y==1 && x==14) || (y==7 && x==28) || (y==13 && x==14)) a[y][x]='X';
			else if((y==3 && x==10) || (y==3 && x==18) || (y==5 && x==26) || (y==10 && x==26) || (y==11 && x==10) || (y==11 && x==18)) a[y][x]='X';
			
			else{
				if(a[y][temp]=='1' || a[y][temp1]=='2');
				else a[y][x]=' ';
			}
			
			if(y==1 && x==m){
				if(1<=m && m<=28){
					if(a[y][x]=='X'){
						a[y][x-2]='1';
						p[0]=1;
						penalty1=1;
					}
					else a[y][x]='1';
				}
			}
			else if(y==m-27 && x==28){
				if(28<=m && m<=40){
					if(a[y][x]=='X'){
						a[y-2][x]='1';
						p[0]=1;
						penalty1=1;
					}
					else a[y][x]='1';
				}
			}
			else if(y==13 && 29-x==m-39){
				if(40<=m && m<=67){
					if(a[y][x]=='X'){
						for(i=1;i<=6;i++){
							if(i==2) continue;
							a[y][x+i]=' ';
						}
						a[y][x+2]='1';
						temp=x+2;
						p[0]=1;
						penalty1=1;
					}
					else a[y][x]='1';
				}
			}
			else if(14-y==m-66 && x==1){
				if(67<=m && m<=79){
					a[y][x]='1';
				}
			}
			else if(y==1 && x==m-78){
				if(79<=m && m<=83){
					a[y][x]='1';
				}
			}
			
			else if(y==3 && x==n){
				if(3<=n && n<=26){
					if(a[y][x]=='X'){
						a[y][x-2]='2';
						p[1]=1;
						penalty2=1;
					}
					else a[y][x]='2';
				}
			}
			else if(y==n-23 && x==26){
				if(26<=n && n<=34){
					if(a[y][x]=='X'){
						a[y-2][x]='2';
						p[1]=1;
						penalty2=1;
					}
					else a[y][x]='2';
				}
			}
			else if(y==11 && 27-x==n-33){
				if(34<=n && n<=57){
					if(a[y][x]=='X'){
						for(i=1;i<=6;i++){
							if(i==2) continue;
							a[y][x+i]=' ';
						}
						a[y][x+2]='2';
						temp1=x+2;
						p[1]=1;
						penalty2=1;
					}
					else a[y][x]='2';
				}
			}
			else if(12-y==n-56 && x==3){
				if(57<=n && n<=65){	
					a[y][x]='2';
				}
			}
			else if(y==3 && x==n-64+2){
				if(65<=n && n<=69){
					a[y][x]='2';
				}
			}
			else if((y==2 && x==1) || (y==4 && x==3)) a[y][x]='_';
				
			if(x==29) a[y][x+1]='\n';
		}
	}
	yellow();
	if(penalty1!=0) printf("Penalty for player 1...\n");
	cyan();
	if(penalty2!=0) printf("Penalty for player 2...\n");
	reset();
}

/*
 * Function:	printMap
 * ----------------------
 * It does: prints the entire game map which is in the array
 *
 *
 *
 * a[][100]: array where we put the whole game map
 *
 *
 *
 * returns: we do not return anything. 
 *
 */
 
void printMap(char a[][100]){
	
	int x,y;
	
	for(y=0;y<15;y++){
		for(x=0;x<=30;x++){
			if(a[y][x]=='X'){
				red();
				printf("%c", a[y][x]);
				reset();
			}
			else if(a[y][x]=='1'){
				yellow();
				printf("%c", a[y][x]);
				reset();
			}
			else if(a[y][x]=='2'){
				cyan();
				printf("%c", a[y][x]);
				reset();
			}
			else if(a[y][x]=='_'){
				green();
				printf("%c", a[y][x]);
				reset();
			}
			else printf("%c", a[y][x]);
		}
	}
}

int main(){
	char map[100][100];
	int m=1, n=3;
	int a=0, b=0;
	char p[100];
	srand(time(NULL));
	int control=1;
	int t;

	createArrayofMap(map,m,n,p);
	printMap(map);
	t=startGame();
	
	while(m<=83 && n<=69){
		if(p[0]==1){
			m=m-2;
			p[0]=0;
		}
		if(p[1]==1){
			n=n-2;
			p[1]=0;
		}
		
		if(t==1){/* if the 1st player starts */
			a=dice_for_player1();
			m=m+a;
			if(m>=78) control = 0;
			if(control){
				b=dice_for_player2();
				n=n+b;
			}	
		}
		if(t==2){/* if the 2nd player starts */
			b=dice_for_player2();
			n=n+b;
			if(n>=64) control = 0;
			if(control){
				a=dice_for_player1();
				m=m+a;
			}
		}
		if(m>=78) break;
		if(n>=64) break;
		createArrayofMap(map,m,n,p);
		printMap(map);
	}
	yellow();
	if(m>=78) printf("\n\n\n\n\n\n *** PLAYER 1 WON THE GAME ***\n\n");
	cyan();
	if(n>=62 ) printf("\n\n\n\n\n\n *** PLAYER 2 WON THE GAME ***\n\n");
	reset();
	
	createArrayofMap(map,m,n,p);
	printMap(map);
	
	printf("\n\n");
	return 0;
}
