#include <stdio.h>
void getsen(char *string,int n){
	int l = 1;
	for(int i = 0;i<n && l==1;i++){
		*(string+i)=getchar();
		if(*(string+i)=='\n' || *(string+i)==' ' || *(string+i)=='\t'){
			*(string+i)='\0';
			l=0;
		}
	}
	/*int i = 0;
	while((*(string+i)=getchar())!='\n' && i<n){
		if(*(string+i)!='\t' && *(string+i)!=' '){
			*(string+i)='\0';
		}
		i++;
	}
	*(string+i)='\0';*/
}
int main(void){
	int n;
	printf("Enter the length of sentence:");
	scanf("%d",&n);
	char string[n+1];
	getchar();
	printf("Enter the word length of which is %d:",n);
	getsen(string,n+1);
	printf("%s",string);
	return 0;
}
