#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct //struct that called book keeps some kinds of informations
{
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	char subject[MAX_SIZE];
	int year;
}book;

int main(){
	//struct book strct[MAX_SIZE];
	book *strct = malloc(sizeof(book)*2);
	int maximum_size=2;
	int select, select2, loop_checker=1, loop_checker1=1;
	char control_string[MAX_SIZE];
	int size=0, control=0;
	int temp, t, l, k, m;
	int sort[MAX_SIZE];

	do{ /* the main menu: it repeats until you choose 'exit' */
		if(size!=0 && loop_checker1!=0) printf("******************\n");
		loop_checker1=1;
		printf("\nMENU\n");
		printf("\t1. Add New Book\n");
		printf("\t2. List Books\n");
		printf("\t3. EXIT\n");
		printf("\nChoose = ");
		scanf("%d", &select);
		fflush(stdin);
		printf("******************\n");
		switch(select){
			case 1: /* provides us to add books to struct */
				if(size==maximum_size){
					strct=realloc(strct, maximum_size+2);
					maximum_size+=2;
				}
				printf("Please enter book title = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",strct[size].title);
				printf("Please enter book author = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",strct[size].author);
				printf("Please enter book subject = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",strct[size].subject);
				printf("Please enter book year = ");
				scanf("%d", &strct[size].year);
				size++;
				break;
			case 2:
				do{ /* the submenu: it repeats until you choose 'exit submenu' */
					control=0;
					printf("SUBMENU\n");
					printf("\t1. Get by Title\n");
					printf("\t2. Get by Author\n");
					printf("\t3. Get by Subject\n");
					printf("\t4. Sorted List by Year (DESC)\n");
					printf("\t5. List All Books\n");
					printf("\t6. EXIT SUBMENU\n");
					printf("\nChoose = ");
					scanf("%d", &select2);
					printf("******************\n");
					switch(select2){
						case 1: /* finds books according to title */
							printf("Enter a books title = "); 
							fflush(stdin);
							scanf(" %[^\n]%*c", control_string);
							for(t=0;t<size;t++){
								if(strcmp(strct[t].title,control_string)==0){
									printf("Book found\n");
									printf("Title -> %s\n", strct[t].title);
									printf("Author -> %s\n", strct[t].author);
									printf("Subject -> %s\n", strct[t].subject);
									printf("Year -> %d\n", strct[t].year);
									printf("******************\n");
									control=1;
									break; //provides us to select only the first one.
								}	
							}
							if(control==0) printf("Book couldn't found!\n******************\n");
							break;
						case 2: /* finds books according to author */
							printf("Enter a books Author = ");
							fflush(stdin);
							scanf(" %[^\n]%*c", control_string);
							for(t=0;t<size;t++){
								if(strcmp(strct[t].author,control_string)==0){
									printf("Book found\n");
									printf("Title -> %s\n", strct[t].title);
									printf("Author -> %s\n", strct[t].author);
									printf("Subject -> %s\n", strct[t].subject);
									printf("Year -> %d\n", strct[t].year);
									printf("******************\n");
									control=1;
									break; //provides us to select only the first one.
								}
							}
							if(control==0) printf("Book couldn't found!\n******************\n");
							break;
						case 3: /* finds books according to subject */
							printf("Enter a books Subject = ");
							fflush(stdin);
							scanf(" %[^\n]%*c", control_string);
							for(t=0;t<size;t++){
								if(strcmp(strct[t].subject,control_string)==0){
									printf("Book found\n");
									printf("Title -> %s\n", strct[t].title);
									printf("Author -> %s\n", strct[t].author);
									printf("Subject -> %s\n", strct[t].subject);
									printf("Year -> %d\n", strct[t].year);
									printf("******************\n");
									break; //provides us to select only the first one.
								}
							}
							if(control==0) printf("Book couldn't found!\n******************\n");
							break;
						case 4: /* sorts according to year */
							for(m=0;m<size;m++){
								sort[m]=strct[m].year;
							}
							for(l=0;l<size;++l){
								for(k=l+1;k<size;++k){
									if(sort[l] < sort[k]){
										temp = sort[l];
										sort[l] = sort[k];
										sort[k] = temp;
									}
								}
							}
							printf("List of Books\n");
							printf("******************\n");
							for(t=0;t<size;t++){
								printf("%d. Book;\n",t+1);
								for(m=0;m<size;m++){
									if(sort[t]==strct[m].year){
										printf("Title -> %s\n", strct[m].title);
										printf("Author -> %s\n", strct[m].author);
										printf("Subject -> %s\n", strct[m].subject);
										printf("Year -> %d\n", strct[m].year);
									}
								}
								printf("******************\n");
							}
							break;
						case 5: /* sorts according to the book_id value */
							printf("List of Books\n");
							printf("******************\n");
							for(t=0;t<size;t++){
								printf("%d. Book;\n",t+1);
								printf("Title -> %s\n", strct[t].title);
								printf("Author -> %s\n", strct[t].author);
								printf("Subject -> %s\n", strct[t].subject);
								printf("Year -> %d\n", strct[t].year);
								printf("******************\n");
							}
							break;
						case 6:
							loop_checker1=0;
							break;
						default:
							printf("please try again!\n");
					}
				}while(loop_checker1);
				break;
			case 3:
				loop_checker=0;
				break;
			default:
				printf("please try again!\n");
		}
	}while(loop_checker);
	return 0;
}