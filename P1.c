#include <stdio.h>
void getsize(int *h,int *w);
int main(void){
	int height,width;
	getsize(&height,&width);
	
	float matrix[height][width];
	float transposed[width][height];
	printf("Now enter %d elements to fill up \nthe matrix line by line(use space):",height*width);
	for(int i=0;i < height;i++){
		for(int j=0;j < width;j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	printf("\nMatrix:\n");
	for(int i=0;i < height;i++){
		printf("|");
		for(int j=0;j < width;j++){
			printf("%6.3f ",*(*(matrix+i)+j));
		}
		printf("|\n");
	}
	for(int i=0;i < height;i++){
		for(int j=0;j < width;j++){
			*(*(transposed+j)+i) = *(*(matrix+i)+j);
		}
	}
	printf("\nTransposed matrix:\n");
	for(int i=0;i < width;i++){
		printf("|");
		for(int j=0;j < height;j++){
			printf("%6.3f ",*(*(transposed+i)+j));
		}
		printf("|\n");
	}
	return 0;
}
void getsize(int *h,int *w){
	printf("Please enter the size of the matrix.(use space):\n");
	printf("Height(lines):");
	scanf("%d",h);
	printf("\nWidth(columns):");
	scanf("%d",w);
	if ((*h<=0 || *w<=0)){
		printf("*Error*Negative sized matrix doesn't exist.\n.The Height and Width will be taken as 1.\n");
		*h=1;
		*w=1;
	}else if(*h>10 || *w>10){
		printf("*Error*Size of matrix is too bigger than 11.\nThe Height and Width will be taken as 10\n");
		*h=10;
		*w=10;
	}
	printf("\n");
}