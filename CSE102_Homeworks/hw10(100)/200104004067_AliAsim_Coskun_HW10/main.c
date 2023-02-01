#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_BLOCK_SIZE 10

typedef struct{
	char * array;
	int currentsize;
	int maxsize;
}stack;

/*
 * Function: push
 *
 * It does: it adds a new disk to the top of the tower.
 *
 *
 *
 * stack *s: the struct containing the tower that we added disk.
 *
 *
 *
 * d: the number of the disk that we added to the tower.
 *
 * return: we don't return anything.
 *
 */
void push(stack *s, char d){
	if(s->currentsize == s->maxsize){ //we allocate memory by increasing 10 by 10
		s->maxsize=s->maxsize+STACK_BLOCK_SIZE;
		s->array = (char*) realloc(s->array, (sizeof(char)*(s->maxsize)));
	}
	s->array[(s->currentsize)++]=d;
	s->array[(s->currentsize)]='\0';
}

/*
 * Function: pop
 *
 * It does: it takes out the disk at the top of the tower.
 *
 *
 *
 * stack *s: the struct containing the tower from which we take out the disk.
 *
 *
 *
 * return: We return the number of the disk that we take out.
 *
 */
char pop(stack *s){
	if (s->currentsize == 0) return 'r'; //'r' is random character.
	s -> currentsize--;
	char popped = s -> array[s -> currentsize];
	return popped;
}

/*
 * Function: init_return
 *
 * It does: it allocates memory for the stack.
 *
 *
 *
 * return: it returns the allocated stack.
 *
 */
stack * init_return(){
	stack* new_stack =(stack*) malloc(sizeof(stack));
	new_stack -> maxsize = STACK_BLOCK_SIZE; //DENEME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	new_stack -> currentsize = 0; // -1 mi olmali 0 mi
	new_stack -> array = (char*) malloc((new_stack -> maxsize) * sizeof(char));
	return new_stack;
}

/*
 * Function: init
 *
 * It does: it checks if memory is allocated for the stack.
 *
 *
 *
 * stack *s: the stack we check to see if the memory is allocated.
 *
 *
 *
 * return: if it is allocated, it returns 1; if it is not, it returns 0.
 *
 */
int init(stack *s){
	if(s==NULL) return 0;
	else return 1;
}

/*
 * Function: tower_to_tower
 *
 * It does: it removes the disk from one tower and adds it to the other.
 *
 *
 *
 * stack *tower1: the first of the towers on which pop and push operations are performed.
 *
 *
 *
 * stack *tower2: the second of the towers on which pop and push operations are performed.
 *
 *
 *
 * first: the first number holding the number of the tower.
 *
 * second: the second number holding the number of the tower.
 *
 * return: we don't return anything.
 *
 */
void tower_to_tower(stack *tower1, stack *tower2, int first, int second){
	int controller=2;
	char last_added_disk_to_tower1=pop(tower1);
	char last_added_disk_to_tower2=pop(tower2);

	if (last_added_disk_to_tower1 == 'r'){ //'r' is random character.
		push(tower1, last_added_disk_to_tower2);
		controller=0;
	}
	else if (last_added_disk_to_tower2 == 'r'){  //'r' is random character.
		push(tower2, last_added_disk_to_tower1);
		controller=1;
	}
	else if (last_added_disk_to_tower1 > last_added_disk_to_tower2){
		push(tower1, last_added_disk_to_tower1);
		push(tower1, last_added_disk_to_tower2);
		controller=0;
	}
	else{
		push(tower2, last_added_disk_to_tower2);
		push(tower2, last_added_disk_to_tower1);
		controller=1;
	}

	if(controller==0) printf("Move the disk %d from \'%d\' to \'%d\'\n", last_added_disk_to_tower2, second, first);
	if(controller==1) printf("Move the disk %d from \'%d\' to \'%d\'\n", last_added_disk_to_tower1, first, second);
}

/*
 * Function: solving_puzzle
 *
 * It does: it contains the algorithm that solves the puzzle.
 *
 *
 *
 * disk_no: number of disks entered by the user.
 *
 * stack *first: the struct containing the first tower.
 *
 *
 *
 * stack *second: the struct containing the second tower.
 *
 *
 *
 * stack *third: the struct containing the third tower.
 *
 *
 *
 * return: we don't return anything.
 *
 */
void solving_puzzle(int disk_no, stack * first, stack *second, stack * third){
	int success, i;
	success=init(first);
	if(success==0) printf("we couldn't allocate memory for first struct\n");
	if(success==1) printf("allocating memory for first struct, successful!\n");
	success=init(second);
	if(success==0) printf("we couldn't allocate memory for second struct\n");
	if(success==1) printf("allocating memory for second struct, successful!\n");
	success=init(third);
	if(success==0) printf("we couldn't allocate memory for third struct\n");
	if(success==1) printf("allocating memory for third struct, successful!\n");

	for(i=disk_no; 1<=i; i--){ //in this loop, we insert the disks into the first tower.
		push(first, i);
	}

	int int_first=1;
	int int_second=2;
	int int_third=3;
	int min_move, controller;
	min_move=((pow(2,disk_no))-1);
	if(disk_no%2==0) controller = min_move/3;
	if(disk_no%2==1) controller = (min_move/3)+1;
	for (i=1; i<=controller; i++){
		if(disk_no%2==0) tower_to_tower(first, third, int_first, int_second);
		else tower_to_tower(first, third, int_first, int_third);

		if(disk_no%2==1 && i==(min_move/3)+1) break;

		if(disk_no%2==0) tower_to_tower(first, second, int_first, int_third);
		else tower_to_tower(first, second, int_first, int_second);
		
		if(disk_no%2==0) tower_to_tower(second, third, int_third, int_second);
		else tower_to_tower(second, third, int_second, int_third);
	}
}

int main(){ /* main function */
	int disk_no;
	stack * first;
	stack *second;
	stack * third;
	first=init_return();
	second=init_return();
	third=init_return();

	printf("Enter tower size: ");
	scanf("%d", &disk_no);
	while(disk_no<1){
		printf("Wrong input, please try again: ");
		scanf("%d", &disk_no);
	}

	solving_puzzle(disk_no, first, second, third);
	return 0;
}