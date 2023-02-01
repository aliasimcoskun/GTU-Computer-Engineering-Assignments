#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
 * Function: generate_sequence
 *
 * It does: it generates a sequence based on the mathematical conjecture namely Collatz with the numbers which are entered.
 *
 *
 * xs: this is the first element of the generated sequence.
 *
 * currentlen: this is the length of the array that constantly changes during recursion.
 *
 * seqlen: this is the length of the generated sequence.
 *
 *
 * *seq: this is the sequence which is generated in this function.
 *
 *
 *
 * return: we don't return anything.
 *
 */
void generate_sequence(int xs, int currentlen, int seqlen, int *seq){//seq is an array of integers
	int elements;
	if(currentlen==seqlen) return;
	seq[currentlen]=xs;

	if(xs%2==0) elements=xs/2;
	if(xs%2==1) elements=3*xs+1;
	
	generate_sequence(elements,currentlen+1,seqlen,seq);
}

/*
 * Function: check_loop_iterative
 *
 * It does: provides us to find the length of the loop in the sequence. (if there is a loop)
 *
 * (*f): this is the function where we generated the sequence.
 *
 * xs: this is the first element of the generated sequence.
 *
 * seqlen: this is the length of the generated sequence.
 *
 * *loop: this is the array where we put the loop we found.
 *
 *
 *
 * *looplen: this is the length of the loop we found.
 *
 * return: we don't return anything.
 *
 */
void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop, int *looplen){
	int *seq;
	seq=(int*)malloc(seqlen*sizeof(int));
	(*f)(xs, 0, seqlen, seq); //we get "seq" array.

	if(*looplen<=1){//this will print "no loop found" in main.c
		*looplen=0;
		return;
	}

	int value, ls, le, t=0, k=0;
	value=has_loop(seq,seqlen,*looplen,&ls,&le); //that is checking if there is a loop or not.
	if(value==1){
		printf("\n\nLoop detected with a length of %d.\n", *looplen);
		printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n", ls, le);
		t=ls;
		while(t<=le){//we put the loop in array.
			*(loop+k)=seq[t];
			k++;
			t++;
		}
		return;
	}
	else{
		*looplen=*looplen-1;
		check_loop_iterative(f,xs,seqlen,loop,looplen);
	}
}

/*
 * Function: has_loop
 *
 * It does: provides us to find if there is a loop or not in the sequence.
 *
 *
 * *arr: this is the sequence which is generated in this function. (*seq)
 *
 *
 *
 * n: this is the length of the generated sequence. (seqlen)
 *
 * looplen: this is the length of the loop we found.
 *
 * *ls: loop's starting index in array.
 *
 * *le: loop's ending index in array.
 *
 * return: we return 1 if there is a loop, otherwise we return 0.
 *
 */
int has_loop(int *arr, int n, int looplen, int *ls, int *le){
	printf("Checking if there is a loop of length %d...\n", looplen);
	int t=0, check=1;
	while(t<looplen){
		if(arr[n-1-t]!=arr[n-1-looplen-t]) check=0;
		t++;
	}
	if(check==1){
		*ls=n-1-looplen+1-looplen;
		*le=n-1-looplen+1-1;
		return 1;
	}
	return 0;
}

/*
 * Function: hist_of_firstdigits
 *
 * It does: calculates the histogram of the first digits of the sequence generated by a given function.
 *
 * (*f): this is the function where we generated the sequence.
 *
 * xs: this is the first element of the generated sequence.
 *
 * seqlen: this is the length of the generated sequence.
 *
 * *h: array where we put the histogram of the first digits of the sequence. it has has 9 elements(1-9).
 *
 *
 *
 * digit: this is the index of the sequence's array that constantly changes during recursion.
 *
 * return: we don't return anything.
 *
 */
void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit){
	int *seq;
	seq=(int*)malloc(seqlen*sizeof(int));
	(*f)(xs, 0, seqlen, seq);

	if(digit==seqlen) return;

	int firstdigit;
	if(digit<seqlen){
		firstdigit=seq[digit];
		while(!(0<=firstdigit && firstdigit<=9)){
			firstdigit=firstdigit/10;
		}
		h[firstdigit-1]++; //we add -1 because of index of array.
		hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit+1);
	}
}