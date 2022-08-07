#include <stdio.h>
#include <string.h>
#define W 10
int main(void){
	char string[W][30];
//h3el4loпривіт T-!@h%e##re
	printf("Please enter 10 words(Press Enter):\n");
	for(int u = 0;u<W;u++){
		gets(*(string+u));
	}
	for(int u = 0;u<W;u++){
		for(int i = 0;string[u][i] != '\0';++i){
			while(!((*(*(string+i)+u)=='\0') || ((*(*(string+i)+u)>='a') && ((*(*(string+i)+u)<='z'))) || ((*(*(string+i)+u)>='A') && (*(*(string+i)+u)<='Z')))){
				int j;
				for(j = i;*(*(string+j)+u) != '\0';++j){
					*(*(string+j)+u)=*(*(string+j+1)+u);
				}
				*(*(string+j+1)+u)='\0';
			}
		}
	}
	printf("Words in given order:\n");
	for(int u = 0;u<W;u++){
		printf("%s\n",*(string+u));
	}
	char t[30];
	for(int i = 0;i<W-1;++i){
		for(int j = i+1;j<W;++j){	
			if(strcmp(*(string+i),*(string+j))>0){
				strcpy(t,*(string+i));
				strcpy(*(string+i),*(string+j));
				strcpy(*(string+j),t);
			}
		}
	}
	printf("Words in Alphabet order:\n");
	for(int u = 0;u<W;u++){
		printf("%s\n",string[u]);
	}
	/*char string[W][30];
	char *ptr = &string[0];
	int w = 0;
	int i = 0;
	printf("Enter 10 words:");
	while	(
	while((*(ptr+i)=getchar())!='\n' && i<30){
		i++;
	}
	printf("%s",string);*/
	return 0;
}