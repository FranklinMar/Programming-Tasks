/*
--------------
Name: Task02.c
--------------
Description: Print out address of the same 
given array elements in a different ways.
--------------
*/
#include <stdio.h>

int main(void){
	int data [30][100];
	int *adress = &data[0][0];
	printf("data[22][56]:address %p\n",(*(data+22)+56));
	printf("data[22][56]:address %p\n",&data[22][56]);
	printf("data[22][0]:address %p\n",(data+22));
	printf("data[22][0]:address %p\n",&data[22][0]);
	printf("data[0][0]:address %p\n",adress);
	printf("data[0][0]:address %p\n",&data);
	return 0;
}
