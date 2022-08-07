#include <stdio.h>
char *my_gets(char *word){
//	int size=sizeof(word);
// типу що треба зробити в виклику функції щоб та функція на картинці використовувалась як треба
	*word = getchar();
	do{
		*++word = getchar();
		
	}while(*(word) !='\n' && *(word) !='\0');
	if(*(word) =='\n')
		*(word) = '\0';
	return word;
}
int main(void){
	char word[20];
	printf("Enter a word:");
	my_gets(word);
	printf("\nWord:%s",word);
	return 0;
}