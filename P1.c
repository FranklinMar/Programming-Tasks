#include <stdio.h>
#include <string.h>
#define H 3
void rotl(int a[H][H]);
void print(int a[H][H]);
void fliph(int a[H][H]);
void flipv(int a[H][H]);
int main(void){
	char e;
	int cube[H][H] = {{1,2,3},{4,5,6},{7,8,9}};
	for(int i = 0;i<H;i++){
		for(int j = 0; j < H;j++){
			printf(" %d ",cube[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Enter the operation of your choice:\n");
	printf("A. Rotate left\n");      
	printf("B. Rotate right\n");
	printf("C. Rotate 180\n");  
	printf("D. Flip vertical\n");
	printf("E. Flip horizontal\n");
	printf("Q. Quit\n");
	while((e = getchar()) != 'Q'){
	switch(e){
		case 'A':
			rotl(cube);
			print(cube);
			break;
		case 'B':
			rotl(cube);
			rotl(cube);
			rotl(cube);
			print(cube);
			break;
		case 'C':
			rotl(cube);
			rotl(cube);
			print(cube);
			break;
		case 'D':
			flipv(cube);
			print(cube);
			break;
		case 'E':
			fliph(cube);
			print(cube);
			break;
	}}
	return 0;
}

void print(int cube[H][H]){
	for(int i = 0;i<H;i++){
		for(int j = 0; j < H;j++){
			printf(" %d ",cube[i][j]);
		}
		printf("\n");
	}
}
void rotl(int cube[H][H]){
	int a[H][H];
	int e = 0;
	int f = 0;
	for(int i = 2; i >= 0;i--){
		f=0;
		for(int j = 0; j < H;j++){
			a[e][f] = cube[j][i];
			f++;
		}
		e++;
	}
	for(int i = 0;i<H;i++){
		for(int j = 0; j < H;j++){
			cube[i][j]=a[i][j];
		}
	}
}
void fliph(int cube[H][H]){
	int a[H][H];
	int f = 0;
	for(int i = 0; i < H ;i++){
		f=0;
		for(int j = 2; j >=0 ;j--){
			a[i][f] = cube[i][j];
			f++;
		}
	}
	for(int i = 0;i<H;i++){
		for(int j = 0; j < H;j++){
			cube[i][j]=a[i][j];
		}
	}
}
void flipv(int cube[H][H]){
	int a[H][H];
	int f = 0;
	for(int i = 2; i >= 0 ;i--){
		for(int j = 0; j < H ;j++){
			a[f][j] = cube[i][j];
		}
		f++;
	}
	for(int i = 0;i<H;i++){
		for(int j = 0; j < H;j++){
			cube[i][j]=a[i][j];
		}
	}
}