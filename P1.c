#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define S 18
#define a 30
char cypher(char w[S]);
int main(void){
	char word[S];
	int I = 1;
	printf("Please enter the word to encrypt it:\n");
	scanf("%s",word);
	for(int i = 0;i < strlen(word);i++){
		if(!islower(word[i]) && !isupper(word[i])){
			I = 0;
		}
	}
	if(I){
		cypher(word);
		printf("Encrypted word:%s",word);
	}else{
		printf("Sorry,but you have entered wrong type of symbols.\n Please use English Alphabet letters");
	}
	return 0;
}
char cypher(char w[S]){
	for(int i = 0;i < strlen(w); i++){
		if(w[i] >= 'x'||(w[i] >= 'X' && w[i] <= 'Z')){
			w[i]-= 23;
		}else{
		w[i] += 3;
		}
	}
	return w;
}