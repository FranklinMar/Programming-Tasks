#include <stdio.h>

int main(void){
	int data [30][100];
	int *adress = &data[0][0];
/*	int *add1 = &data[22][56];
	int *add2 = &data[22][0];
	int *add3 = &data[0][0];
	*adress = data;
	*add1 = &data[22][56];
	*add2 = &data[22][0];
	*add3 = &data[0][0];*/
	printf("data[22][56]:address %p\n",(*(data+22)+56));
	printf("data[22][56]:address %p\n",&data[22][56]);
	//printf("data[22][0]:address %p\n",(adress+22)/*(adress+2200)*/);
	printf("data[22][0]:address %p\n",(data+22));
	printf("data[22][0]:address %p\n",&data[22][0]);
	printf("data[0][0]:address %p\n",adress);
	printf("data[0][0]:address %p\n",&data);
	return 0;
}