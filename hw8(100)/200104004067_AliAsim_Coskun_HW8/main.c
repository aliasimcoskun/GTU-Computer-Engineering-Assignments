#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
	int xs, currentlen=0, seqlen;
	int *seq;
	printf("Please enter the sequence length: ");
	scanf("%d", &seqlen);
	printf("Please enter the first element: ");
	scanf("%d", &xs);

	seq=(int*)malloc(seqlen*sizeof(int));	//we allocate memory to seq array by using malloc.

	int i;
	if(seq==NULL){
		printf("Memory not allocated.\n");
		exit(0);
	}
    else{	//memory has been successfully allocated
		printf("\n");
		generate_sequence(xs, currentlen, seqlen, seq);		//we get the elements of the array
 
		printf("Sequence: {");		//we print the elements of the 'seq' array
		for (i=0; i<seqlen; ++i){
			if(i==seqlen-1) printf("%d", seq[i]);
			else printf("%d, ", seq[i]);
		}
		printf("}\n\n");
    }

	int *loop;
    loop=(int*)malloc(seqlen*sizeof(int));		//we allocate memory to loop array by using malloc.
    int looplen;
    looplen=seqlen/2;
	check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen);
	int t=0;
	if(looplen==0) printf("No loop found!\n");
	else{
		for(t=0;t<looplen;t++){		//we print the elements of the loop array
			if(t==0) printf("Loop: {%d, ", loop[t]);
			else if(t==looplen-1) printf("%d}\n", loop[t]);
			else printf("%d, ", loop[t]);
		}
	}

	int *h;
	h=(int*)malloc(9*sizeof(int)); //we allocate memory to h array by using malloc.
	int digit=0;
	hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit);

	printf("\nHistogram of the sequence: {");		//we print the elements of the histogram array
	for(t=0;t<9;t++){
		if(t==9-1) printf("%d}", h[t]);
		else printf("%d, ", h[t]);
	}
	printf("\n");
	return 0;
}