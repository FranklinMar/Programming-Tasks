/*
--------------
Name: Task04.c
--------------
The Tower of Hanoi is a mathematical game or puzzle

Description: Write a program for solving Hanoi tower problem.
The problem is that, having 3 pins and 3 rings of different size 
on a pin #1 (like a pyramid), it is required to move these ring on a last
pin, so that rings would remain in the same order.
--------------
*/
#include <stdio.h>
#define MAX_NRINGS 64 // Max number of rings
int st[4]/*No. of pins*/[MAX_NRINGS];// No. of rings on certain pin
int nr[4];// No. of rings on pin
int nmoves; // No. of rings movement

// Print current position on pins
void print_st(void) {
	for (int i = 1; i<=3; i++){
		printf("\n|");
		for (int j=0; j<nr[i]; j++){
			printf("%d", st[i][j]);
		}
	}
	printf("\n");
}

// Reset
void init(int nrings) {
	for (nr[1]=0; nrings>0; nr[1]++, nrings--){
		 st[1][nr[1]] = nrings;
    }
    nr[2] = nr[3] = 0;// ALL rings on pin #1
    nmoves = 0;
    print_st();
}

// Move one ring from pin #1 to pin #2
void move1(int n1, int n2) {
    // Adds ring no.'n2' to pin inside 'nr' variable.
    // Reduces 1 ring from 'nr' variable from pin with no.'n'
    st[n2][nr[n2]++] = st[n1][nr[n1]--];
    print_st();
    nmoves++;
}

// Move upper rings from pin #1 to pin #3 #2 as temporary
void hanoi(int nrings, int i1, int i2, int i3){
    if (nrings == 1){
        move1(i1, i3);
    }else{
        hanoi(nrings - 1, i1, i3, i2);
        move1(i1, i3);
        hanoi(nrings - 1, i2, i1, i3);
    }
}

int main(){
    int nrings;
    printf("Rings number: ");
    scanf("%d", &nrings);
    hanoi(nrings, 1, 2, 3);
    printf("All rings were moved.\n");
    printf("Moves: %d.\n", nmoves);
    return 0;
}
