#include <stdio.h>
int is_within(char mass[5][18],char sym,int row,int size);
int main(void){
	char mass[5][18]={"Hello,i am Denys",
	"This is the way",
	"I am simple man",
	"Making his way",
	"The Galaxy"};
	char sym;
	int row;
	int f = 1;
	printf("Enter the symbol for search:");
	sym=getchar();
	printf("\nEnter the number of the row:");
	while(f){
		printf("\nEnter the number of the row:");
		scanf("%d",&row);
		if(row<=0 || row>5){
			printf("Number of row can't be negative/0,or bigger than 5");
			getchar();
		}else{
			f=0;
		}
	}
	int l=is_within(mass,sym,row,18);
	if(l){
		printf("\n'%c' was found.",sym);
	}else{
		printf("\n'%c' wasn't found.",sym);
	}
	return 0;
}
int is_within(char mass[5][18],char sym,int row,int size){
	int l=0;
	for(int i=0;i<size && l==0;i++){
		if(sym == mass[row][i]/* *(*(mass+row)+i)*/){
			l=1;
		}
	}
	return l;
}