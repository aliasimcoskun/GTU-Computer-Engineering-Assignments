#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMOFITEMS 2
#define FILENAME "Lab11_data.bin"

typedef struct{
    //int id;
    char name[100];
    int price;
} item_t;

typedef union {
    int number;
    char mail[100];
} contactInfo_t;

typedef struct{
    char name[100];
    int price;
    int number;
    char mail[100];
} itemWithCont_t;

void flushInputBuffer(){
    char tmp;
    do{
        scanf("%c",&tmp);
    }while(tmp!='\n');
}

item_t *getItems(item_t *items,int size){
    static int i=0;
    static int k=1;
    int t=0;
    while(t<size){
        printf("ID=>%d\n", k);
        printf("Name=>");
        scanf("%s", items[i].name);
        flushInputBuffer();
        printf("Price=>");
        scanf("%d", &items[i].price);
        flushInputBuffer();
        k++;
        i++;
        t++;
    }
    printf("Printing...\n\n");
}

void printItem(item_t *item){
    int i;
    static int k=1;
    for(i=0;i<2;i++){
    	//item[i].id=k;
        printf("ID: %d\n", k);
        printf("Name: %s\n", item[k-1].name);
        printf("Price: %d\n", item[k-1].price);
        k++;
    }
}

int writeItems(char filename[], item_t *items, int size){
	unsigned char keeper[10];
    int keeper_id;
    int keeper_price;

    FILE *file;
    getItems(items,2);
    int i=0;
    file = fopen(filename,"wb");
    for(i=0;i<4;i++){
    	fwrite(&items[i],sizeof(items[i]),1,file);
    }
    
    printItem(items);
    printf("Successfully wrote data to file.\n\n");
    fclose(file);
}

item_t readAnItem(FILE *file){
	static int k=1;
    unsigned char keeper[10];
    int keeper_id;
    int keeper_price;
	item_t *temp;
	temp = (item_t*)malloc(10 * sizeof(item_t));
    file = fopen(FILENAME,"rb");
    int i=0;
    for(i=0;i<4;i++){
    	fread(&temp[i],sizeof(temp[i]),1,file);
	}
    int t=0;
    for(t=0;t<4;t++){
    	printf("id: %d\n", t+1);
    	printf("name: %s\n", temp[t].name);
 		printf("price: %d\n", temp[t].price);
    }
	printf("\n\n");
 	fclose(file);
    return *temp;
}

void contactInfoAdder(item_t *items, int size, itemWithCont_t contacts[]){
	int i;
	for(i=0;i<size;i++){
		strcpy(contacts[i].name, items[i].name);
		contacts[i].price=items[i].price;
		printf("Enter the phone for %s => ", items[i].name);
		scanf("%d", &contacts[i].number);
		printf("Enter a mail for %s => ", items[i].name);
		scanf("%s", contacts[i].mail);
		printf("\n");
	}
}

void printItemWithContactInfo(itemWithCont_t *itemsWithCont){
	static int k=1;
	int i;
	for(i=0;i<4;i++){
		printf("ID: %d\n", k);
		printf("Name: %s\n", itemsWithCont[i].name);
		printf("Price: %d\n", itemsWithCont[i].price);
		printf("Phone number: %d\n", itemsWithCont[i].number);
		printf("Mail: %s\n", itemsWithCont[i].mail);
		k++;
		printf("\n");
	}
}

int main(){
	item_t items[10];
    FILE *file;
    int size = NUMOFITEMS;
    while(size<=4){
    	writeItems(FILENAME, items, size);
    	size=size+2;
    }
    size=size-2;
    printf("\nReading from file:\n");
    readAnItem(file);
    itemWithCont_t contacts[10];
    contactInfoAdder(items, size, contacts);
    printf("Printing with contact information:\n");
    printItemWithContactInfo(contacts);
	return 0;
}