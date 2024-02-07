#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

enum shapes{/* the enum types which specified in the assignment */
	Triangle=1, Quadrilateral, Circle, Pyramid, Cylinder
};

enum calculators{/* the enum types which specified in the assignment */
	Area=1, Perimeter, Volume
};

int select_calc(){/* in this function, we select the type of calculator */
	int op, temp, i, c;
	int flag=1;
	printf("\nSelect a calculator:\n---------------------------\n1. Area\n2. Perimeter\n3. Volume\n0. Exit\n---------------------------\n");
	
	do{
		printf("Input : ");
		op=0;
		temp=0;
		i=getchar();
		if(i=='0' || i=='\n'){/* If the first character entered is '0' or '\n', give an error */
			if(i=='\n') temp=1;
			else{
				while((c=getchar()) != '\n'){
					if(c!='\n') temp=1;
				}
			}
		}
		else{
			if('0'<=i && i<='9')
				op = (op * 10) + (i - '0');
			else{
				temp=1;
			}
			while((c=getchar()) != '\n'){
				if('0'<=c && c<='9')
					op = (op * 10) + (c - '0');
				else{
					temp=1;
				}
			}
		}

		if(temp==1) op=-1;

		if(0<=op && op<=3) flag=0;
		else printf("\nERROR ! Please enter a valid entry.\n\n");
	}while(flag);
	
	return op;
}

int select_shape(){
	int op, temp, i, c;
	int flag=1;
	printf("\nSelect a shape to calculate:\n---------------------------\n1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cylinder\n0. Exit\n---------------------------\n");
	
	do{
		printf("Input : ");
		op=0;
		temp=0;
		i=getchar();
		if(i=='0' || i=='\n'){
			if(i=='\n') temp=1;
			else{
				while((c=getchar()) != '\n'){
					if(c!='\n') temp=1;
				}
			}
		}
		else{
			if('0'<=i && i<='9')
				op = (op * 10) + (i - '0');
			else{
				temp=1;
			}
			while((c=getchar()) != '\n'){
				if('0'<=c && c<='9')
					op = (op * 10) + (c - '0');
				else{
					temp=1;
				}
			}
		}

		if(temp==1) op=-1;

		if(0<=op && op<=5) flag=0;
		else printf("\nERROR ! Please enter a valid entry.\n\n");
	}while(flag);
	
	return op;
}

int calc_triangle(int calc_type){
	float area=0,perimeter=0,semi_perimeter,s,a,b,c;
	int temp=1;
	char term1, term2, term3;
	printf("\nPlease enter three sides of Triangle :\n");
	do{/* this loop continues until valid input is entered */
		scanf("%f%c", &a, &term1); /* term1 means that the '\n' character which entered after number */
		if(term1!='\n') while (getchar() != '\n');
		else{/* term1 == '\n' */
			scanf("%f%c", &b, &term2); /* term2 means that the '\n' character which entered after number */
			if(term2!='\n') while (getchar() != '\n');
			else{/* term2 == '\n' */
				scanf("%f%c", &c, &term3); /* term3 means that the '\n' character which entered after number */
				if(term3!='\n') while (getchar() != '\n');
			}
		}
		if((term1 !='\n') || (term2 !='\n') || (term3 !='\n')){ /* if a character instead of '\n' is entered after the number*/
			printf("\nERROR ! Please enter a valid entry.\n\n");
			a=0;
			b=0; /* we need to equate them to zero against any errors that may occur. */
			c=0;
		}
		else{
			semi_perimeter=(a+b+c)/2; 
			if(a<=0 || b<=0 || c<=0){/* if it is equal to 0 and less than 0 give an error. */
				printf("\nERROR ! Please enter a valid entry.\n\n");
				term3='a'; /* we need to equate term3 to 'a' against any errors that may occur. */
			}
			else if(a>=semi_perimeter || b>=semi_perimeter || c>=semi_perimeter){
				printf("\nERROR ! Please enter a valid triangle.\n\n");
				term3='a'; /* we need to equate term3 to 'a' against any errors that may occur. */
			}
			else temp=0;
		}
	}while((temp) || ((term1!='\n') || (term2!='\n') || (term3 !='\n')));

	switch(calc_type){/* the formulas which are given in document. */
		case Area: //Area=1;
			s=(a+b+c)/2;
			area=sqrt(s*(s-a)*(s-b)*(s-c));
			break;
		case Perimeter: //Perimeter=2;
			perimeter=a+b+c;
			break;
	}
	
	if(area!=0) printf("\nArea of TRIANGLE : %.2f\n", area);
	if(perimeter!=0) printf("\nPerimeter of TRIANGLE : %.2f\n", perimeter);
	
	return 1;
}

int calc_quadrilateral(int calc_type){
	float area=0,perimeter=0,s,a,b,c,d;
	char term1, term2, term3, term4;
	int temp=1;
	
	printf("\nPlease enter four sides of Quadrilateral\n");
	do{/* this loop continues until valid input is entered */
		scanf("%f%c", &a, &term1); /* term1 means that the '\n' character which entered after number */
		if(term1!='\n') while (getchar() != '\n');
		else{/* term1 == '\n' */
			scanf("%f%c", &b, &term2); /* term2 means that the '\n' character which entered after number */
			if(term2!='\n') while (getchar() != '\n');
			else{/* term2 == '\n' */
				scanf("%f%c", &c, &term3); /* term3 means that the '\n' character which entered after number */
				if(term3!='\n') while (getchar() != '\n');
				else{/* term3 == '\n' */
					scanf("%f%c", &d, &term4); /* term4 means that the '\n' character which entered after number */
					if(term4!='\n') while (getchar() != '\n');
				}
			}
		}
		if ((term1 !='\n') || (term2 !='\n') || (term3 !='\n') || (term4 !='\n')){ /* if a character instead of '\n' is entered after the number*/
			printf("\nERROR ! Please enter a valid entry.\n\n");
			a=0;
			b=0; /* we need to equate them to zero against any errors that may occur. */
			c=0;
			d=0;
		}
		else{
			if(a<=0 || b<=0 || c<=0 || d<=0){/* if it is equal to 0 and less than 0 give an error. */
				printf("\nERROR ! Please enter a valid entry.\n\n");
				term3='a'; /* we need to equate term3 to 'a' against any errors that may occur. */
			}
			else temp=0; /* for break the loop */
		}
	}while((temp) || ((term1 !='\n') || (term2 !='\n') || (term3 !='\n') || (term4 !='\n')));
	
	switch(calc_type){/* the formulas which are given in document. */
		case Area: //Area=1;
			s=(a+b+c+d)/2;
			area=sqrt((s-a)*(s-b)*(s-c)*(s-d)); 
			break;
		case Perimeter: //Perimeter=2;
			perimeter=a+b+c+d;
			break;
	}
	
	if(area!=0) printf("\nArea of QUADRILATEREAL : %.2f\n", area);
	if(perimeter!=0) printf("\nPerimeter of QUADRILATEREAL : %.2f\n", perimeter);
	
	return 1;
}

int calc_circle(int calc_type){
	float area=0,circumference=0,r;
	char term1;
	int temp=1;
	printf("\nPlease enter radius of Circle :\n");
	do{/* this loop continues until valid input is entered */
		scanf("%f%c", &r, &term1); /* term1 means that the '\n' character which entered after number */
		if(term1!='\n') while (getchar() != '\n');
		if (term1 != '\n'){ /* if a character instead of '\n' is entered after the number*/
			printf("\nERROR ! Please enter a valid entry.\n\n");
			r=0; /* we need to equate it to zero against any errors that may occur. */
		}
		else{
			if(r<=0){/* if it is equal to 0 and less than 0 give an error. */
				printf("\nERROR ! Please enter a valid entry.\n\n");
				term1='a'; /* we need to equate term1 to 'a' against any errors that may occur. */
			}
			else temp=0; /* for break the loop */
		}
	}while((term1 != '\n') || (temp));
	
	switch(calc_type){/* the formulas which are given in document. */
		case Area: //Area=1;
			area=PI*r*r; // pi*r*r
			break;
		case Perimeter: //Perimeter=2;
			circumference=2*PI*r; // 2*pi*r
			break;
	}
	
	if(area!=0) printf("\nArea of CIRCLE : %.2f\n", area);
	if(circumference!=0) printf("\nCircumference of CIRCLE : %.2f\n", circumference);
	
	return 1;
}

int calc_pyramid(int calc_type){
	float volume=0,base_surface_area=0,lateral_surface_area=0,surface_area=0,perimeter=0;
	float base_side,height,slant_height;
	char term1, term2;
	int temp=1;
	do{/* this loop continues until valid input is entered */
		switch(calc_type){
			case Area:
				printf("\nPlease enter the base side and slant height of a Pyramid :\n");
				scanf("%f%c", &base_side, &term1); /* term1 means that the '\n' character which entered after number */
				if(term1!='\n') while (getchar() != '\n');
				else{/* term1 == \n */
					scanf("%f%c", &slant_height, &term2); /* term2 means that the '\n' character which entered after number */
					if(term2!='\n') while (getchar() != '\n');
				}
				if ((term1 !='\n') || (term2 !='\n')){ /* if a character instead of '\n' is entered after the number*/
					printf("\nERROR ! Please enter a valid entry.\n\n");
					base_side=0; /* we need to equate them to zero against any errors that may occur. */
					slant_height=0;
				}
				else{
					if(base_side<=0 || slant_height<=0){/* if it is equal to 0 and less than 0 give an error. */
						printf("\nERROR ! Please enter a valid entry.\n\n");
						term2='a'; /* we need to equate term2 to 'a' against any errors that may occur. */
					}
					else temp=0; /* for break the loop */
				}
				break;
			case Perimeter:
				printf("\nPlease enter the base side of a Pyramid :\n");
				scanf("%f%c", &base_side, &term1); /* term1 means that the '\n' character which entered after number */
				if(term1!='\n') while (getchar() != '\n');
				term2 ='\n';
				if (term1 !='\n'){ /* if a character instead of '\n' is entered after the number*/
					printf("\nERROR ! Please enter a valid entry.\n\n");
					base_side=0; /* we need to equate it to zero against any errors that may occur. */
				}
				else{
					if(base_side<=0){/* if it is equal to 0 and less than 0 give an error. */
						printf("\nERROR ! Please enter a valid entry.\n\n");
						term1='a'; /* we need to equate term1 to 'a' against any errors that may occur. */
					}
					else temp=0; /* for break the loop */
				}
				break;
			case Volume:
				printf("\nPlease enter the base side and height of a Pyramid :\n");
				scanf("%f%c", &base_side, &term1); /* term1 means that the '\n' character which entered after number */
				if(term1!='\n') while (getchar() != '\n');
				else{/* term1 == \n */
					scanf("%f%c", &height, &term2); /* term2 means that the '\n' character which entered after number */
					if(term2!='\n') while (getchar() != '\n');
				}
				if ((term1 !='\n') || (term2 !='\n')){ /* if a character instead of '\n' is entered after the number*/
					printf("\nERROR ! Please enter a valid entry.\n\n");
					base_side=0; /* we need to equate them to zero against any errors that may occur. */
					height=0;
				}
				else{
					if(base_side<=0 || height<=0){/* if it is equal to 0 and less than 0 give an error. */
						printf("\nERROR ! Please enter a valid entry.\n\n");
						term2='a'; /* we need to equate term2 to 'a' against any errors that may occur. */
					}
					else temp=0; /* for break the loop */
				}
				break;
		}
	}while(((term1 !='\n') || (term2 !='\n')) || (temp));
	
	switch(calc_type){/* the formulas which are given in document. */
		case Area: //Area=1;
			base_surface_area=base_side*base_side; // B = a*a
			lateral_surface_area=2*base_side*slant_height; // L = 2*a*l
			surface_area=base_surface_area+lateral_surface_area; // B + L
			break;
		case Perimeter: //Perimeter=2;
			perimeter=base_side*4; // a*4
			break;
		case Volume: //Volume=3;
			volume=(base_side*base_side*height)/3; // (1/3)*a*a*h
			break;
	}
	
	if(base_surface_area!=0) printf("\nBase Surface Area of PYRAMID : %.2f\n", base_surface_area);
	if(lateral_surface_area!=0) printf("\nLatereal Surface Area of PYRAMID : %.2f\n", lateral_surface_area);
	if(surface_area!=0) printf("\nSurface Area of PYRAMID : %.2f\n", surface_area);
	if(perimeter!=0) printf("\nBase Surface Perimeter of PYRAMID : %.2f\n", perimeter);
	if(volume!=0) printf("\nVolume of PYRAMID : %.2f\n", volume);
	
	return 1;
}

int calc_cylinder(int calc_type){
	float base_surface_area=0,lateral_surface_area=0,surface_area=0,perimeter=0;
	float volume=0,area=0,circumference=0,r,height;
	char term1, term2;
	int temp=1;;
	printf("\nPlease enter radius and height of a Cylinder :\n");
	do{/* this loop continues until valid input is entered */
		scanf("%f%c", &r, &term1); /* term1 means that the '\n' character which entered after number */
		if(term1!='\n') while (getchar() != '\n');
		else{/* term1 == \n */
			scanf("%f%c", &height, &term2); /* term2 means that the '\n' character which entered after number */
			if(term2!='\n') while (getchar() != '\n');
		}
		if ((term1 !='\n') || (term2 !='\n')){ /* if a character instead of '\n' is entered after the number*/
			printf("\nERROR ! Please enter a valid entry.\n\n");
			r=0; /* we need to equate them to zero against any errors that may occur. */
			height=0;
		}
		else{
			if(r<=0 || height<=0){/* if it is equal to 0 and less than 0 give an error. */
				printf("\nERROR ! Please enter a valid entry.\n\n");
				term2='a'; /* we need to equate term2 to 'a' against any errors that may occur. */
			}
			else temp=0; /* for break the loop */
		}
	}while(((term1 !='\n') || (term2 !='\n')) || (temp));
	
	switch(calc_type){/* the formulas which are given in document. */
		case Area: //Area=1;
			base_surface_area=PI*r*r; // pi*r*r
			lateral_surface_area=2*PI*r*height; // 2*pi*r*h
			surface_area=2*PI*r*(r+height); // 2*pi*r*(r+h)
			break;
		case Perimeter: //Perimeter=2;
			perimeter=2*PI*r; // 2*pi*r
			break;
		case Volume:
			volume=PI*r*r*height; // pi*r*r*h
			break;
	}

	if(base_surface_area!=0) printf("\nBase Surface Area of CYLINDER : %.2f\n", base_surface_area);
	if(lateral_surface_area!=0) printf("\nLatereal Surface Area of CYLINDER : %.2f\n", lateral_surface_area);
	if(surface_area!=0) printf("\nSurface Area of CYLINDER : %.2f\n", surface_area);
	if(perimeter!=0) printf("\nBase Surface Perimeter of CYLINDER : %.2f\n", perimeter);
	if(volume!=0) printf("\nVolume of CYLINDER : %.2f\n", volume);

	return 1;
}

int calculate(int (*select_shape)(), int (*select_calc)()){ //switch-case
	int a,b;
	a=select_shape();
	switch(a){
		case 0:
			return 0; /* that means exit the program (in main function) */
			break;
		case Triangle:
			b=select_calc();
			switch(b){
				case 0:
					return 0; /* that means exit the program (in main function)n */
					break;
				case Area:
					if(calc_triangle(b)!=1);
					else
						break;
				case Perimeter:
					if(calc_triangle(b)!=1);
					else
						break;
				case Volume:
					printf("\nERROR ! You cannot calculate the volume of a triangle. Please try again.\n");
					break;
			}
			break;
		case Quadrilateral:
			b=select_calc();
			switch(b){
				case 0:
					return 0; /* that means exit the program (in main function) */
					break;
				case Area:
					if(calc_quadrilateral(b)!=1);
					else
						break;
				case Perimeter:
					if(calc_quadrilateral(b)!=1);
					else
						break;
				case Volume:
					printf("\nERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n");
					break;
			}
			break;
		case Circle:
			b=select_calc();
			switch(b){
				case 0:
					return 0; /* that means exit the program (in main function) */
					break;
				case Area:
					if(calc_circle(b)!=1);
					else
						break;
				case Perimeter:
					if(calc_circle(b)!=1);
					else
						break;
				case Volume:
					printf("\nERROR ! You cannot calculate the volume of a Circle. Please try again.\n");
					break;
			}
			break;
		case Pyramid:
			b=select_calc();
			switch(b){
				case 0:
					return 0; /* that means exit the program (in main function) */
					break;
				case Area:
					if(calc_pyramid(b)!=1);
					else
						break;
				case Perimeter:
					if(calc_pyramid(b)!=1);
					else
						break;
				case Volume:
					if(calc_pyramid(b)!=1);
					else
						break;
			}
			break;
		case Cylinder:
			b=select_calc();
			switch(b){
				case 0:
					return 0; /* that means exit the program (in main function) */
					break;
				case Area:
					if(calc_cylinder(b)!=1);
					else
						break;
				case Perimeter:
					if(calc_cylinder(b)!=1);
					else
						break;
				case Volume:
					if(calc_cylinder(b)!=1);
					else
						break;
			}
			break;
	}
	return 1; /* that means ask the menu again and again.. (in main function) */
}

int main(){
	int x;
	printf("Welcome to the geometric calculator!\n");
	x=calculate(select_shape,select_calc);
	while(x==1) x=calculate(select_shape,select_calc);
	if(x==0) exit(0);
	
	return 0;
}
