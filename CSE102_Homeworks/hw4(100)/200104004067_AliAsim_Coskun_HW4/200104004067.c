#include <stdio.h>

int coordinate_points(int a, int b, int c, int y){/* In this function, we determine at which points we will put '#'... */
    int x = a*y*y + b*y + c; /* ...according to the selected a, b and c values. */
    return x; /* We return the value of x, which is the result of the equality. */
}

void axes_of_coordinate(int x, int y){/* In this function, we draw the coordinate plane. */
	printf("\033[0;37m"); //COLOR: white
	if(x==56 && y!=0) printf("\n"); /* we add '\n' to the end of each line */
	else if(x==0 && y==16) printf("^"); /* up arrow */
    else if(x==-56 && y==0) printf("<"); /* left arrow */
    else if(x==56 && y==0) printf(">\n"); /* right arrow */
    else if(x==0) printf("|"); /* y axis */
    else if(y==0) printf("-"); /* x axis */
    else if (-56<=x && x<=56) printf(" "); /* we fill all the rest with 'space' */
    printf("\033[0m"); //reset color
}

void numbers(int x, int y, int i){/* In this function, we place the numbers of the axes on the coordinate. */
	printf("\033[1;31m"); //COLOR: red
	int a, b;
	for(a=15;a>=-15;a=a-5){/* This loop checks the numbers on the y-axis starting from 15 and decreasing by 5 to -15. */
		if(x==-2 && y==a){
			if(y==5){/* We specify it specially because 5 is a 1-character number. */
				if(y==i) continue; /* do NOT print the number if point is near y-axis numbers */
				else printf("\b%d", y);
			}
			else if(-15<=y &&  y<=-10){/* -15 and -10 is 3-character number. */
				if(x==i || x-1==i || x-2==i) continue; /* do NOT print the number if point is near y-axis numbers */
				else printf("\b\b\b%d", y);
			} 
			else if(y!=0){/* the rest is a 2-character number. (-5, 10, 15) */
				if(x==i || x-1==i) continue; /* do NOT print the number if point is near y-axis numbers */
				else printf("\b\b%d", y);
			}
		}
	}
	for(b=-50;b<=50;b=b+10){/* This loop checks the numbers on the x-axis starting from -50 and decreasing by 10 to 50. */
		if(y==-1 && x==b){
			if(x<=-10 && -50<=x){/* between -10 and -50, is 3-character number. */
				if(x==i || x-1==i || x-2==i) continue; /* do NOT print the number if point is near x-axis numbers */
				else printf("\b\b\b%d", x);
			}
			else if(x!=0){/* the rest is a 2-character number. (10, 20, 30, 40, 50) */
				if(x==i || x-1==i) continue; /* do NOT print the number if point is near x-axis numbers */
				else printf("\b\b%d", x);
			}
		}
	}
	if(x==-1 && y==-1) printf("\b%d", 0); /* we specify exception for zero. */
	printf("\033[0m"); //reset color
}

void draw_graph(int x, int y, int i){/* In this function, we draw the graph. */
	printf("\033[0;36m"); //COLOR: Cyan
	if(-55<=i && i<=55){/* print '#', if it's in the given range. */
		if(y==16); /* Do not print anything on a line containing ^(up arrow) */
		else if(i==x) printf("\b#"); /* print '#', if x values are equal to x of the given equation. */
	}
	printf("\033[0m"); //reset color
}

int main(){
	int op, flag=1;
	int a, b, c;
	int i, x, y;
	FILE *fp;
	FILE *fp2;
	do{
		printf("\nSelect an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit.\n");
		printf("\nChoice: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				fp=fopen("coefficients.txt","w+"); /* If the file does not exist, we create it. */
				printf("\nPlease enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\n");
				printf("a: ");
				scanf("%d", &a);
				printf("b: ");
				scanf("%d", &b);
				printf("c: ");
				scanf("%d", &c);
				fprintf(fp, "%d\n%d\n%d\n", a, b, c); /* we print the a, b, c values to coefficients.txt file. */
				printf("\ncoefficients.txt file has been created.\n\n");
				fclose(fp);
				break;
			case 2:
				if((fp=fopen("coefficients.txt","r"))==NULL) printf("coefficients.txt file is not present.\n");
				else{/* if the file can be opened */
					fscanf(fp, "%d\n%d\n%d\n", &a, &b, &c); /* we read a, b, c values from coefficients.txt file. */
					for(y=16;-15<=y;y--){/* this loop for the y-axis */
						for(x=-56;x<=56;x++){/* this loop for the x-axis */
					    	axes_of_coordinate(x,y); /* draw the coordinate plane. */
							i = coordinate_points(a,b,c,y); /* determine at which points we will put '#' */
							numbers(x,y,i); /* place the numbers of the axes on the coordinate. */
							draw_graph(x,y,i); /* draw the graph. */
						}
					}
					fclose(fp);
				}
				break;
			case 3:
				if((fp=fopen("coefficients.txt","r"))==NULL) printf("coefficients.txt the file is not present.\n");
				else{/* if the file can be opened */
					printf("\nCoefficients has been read from the coefficient file.\n");
					fscanf(fp, "%d\n%d\n%d\n", &a, &b, &c); /* we read a, b, c values from coefficients.txt file. */
					fp2=fopen("graphs.txt","w+"); /* If the file does not exist, we create it. */
					for(y=16;-15<=y;y--){/* this loop for the y-axis */
						for(x=-56;x<=56;x++){/* this loop for the x-axis */
							i = coordinate_points(a,b,c,y); /* determine at which points we will put '#' */
						    if(x==56 && y!=0) fprintf(fp2, "\n"); /* we add '\n' to the end of each line */
							else if(x==0 && y==16) fprintf(fp2, "^"); /* up arrow */
						    else if(x==-56 && y==0) fprintf(fp2, "<"); /* left arrow */
						    else if(x==56 && y==0) fprintf(fp2, ">\n"); /* right arrow */
						    else if(x==0 && x!=i) fprintf(fp2, "|"); /* y-axis */
						    else if(y==0 && x!=i) fprintf(fp2, "-"); /* x-axis */
						    else if(x==i && y==16) fprintf(fp2, " "); /* an exception to line containing ^ */
						    else if(x!=i) fprintf(fp2, " "); /* we fill points that are not equal to 'points of equation' with space */
							else if(-55<=i && i<=55){ /* We do not include the < and > signs. */
								if(y==16); /* Do not print anything on a line containing ^(up arrow) */
								else if(i==x) fprintf(fp2, "#"); /* print '#', if x values are equal to x of the given equation. */
							}
						}
					}
					fclose(fp);
					fclose(fp2);
					printf("The graph of x=%d*(y*y) + %d*y + %d  has been written to graph.txt file.\n", a, b, c);
				}
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("an improper input, please try again!\n\n");
		}
	}while(flag); /* The loop is not broken unless we enter case 4. */
	
	return 0;
}
