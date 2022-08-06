#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define S 18
#define a 30
char cypher(char w[S],char key[S]);
int main(void){
	char word[S];
	char key[S];
	int j = 1,I = 1;
	printf("Enter the code word:");
	scanf("%s",key);
	for(int i = 0;i < strlen(key);i++)
		if(!islower(key[i]) && !isupper(key[i])) j = 0;
	if(j){
		printf("Please enter the word to encrypt it:");
		scanf("%s",word);
		for(int i = 0;i < strlen(word);i++)
			if(!islower(word[i]) && !isupper(word[i])) I = 0;
		if(I){
			cypher(word,key);
			printf("\nEncrypted word:%s",word);
		}else printf("Sorry,but you have entered wrong type of symbols.\n Please use only English Alphabet letters");
	}else printf("Sorry,but you have entered wrong type of symbols.\n Please use only English Alphabet letters");
	
	return 0;
}
char cypher(char w[S],char key[S]){
//-96+key[p%strlen(key)]
	int p = 0;
	int k;
	for(int i = 0;i < strlen(w); i++){
		if(islower(key[i]))	k = -96+/*Для малих літер*/key[p%strlen(key)/*для великих*/];
		else if(isupper(key[i])) k = -64 + key[p%strlen(key)];
		if((w[i] > ('z'- k) && w[i] <= 'z')||(w[i] > ('Z'- k) && w[i] <= 'Z')){
			w[i] -= 26 - k;
		}else{
		w[i] += k;
		}
		p++;
	}
	return w;
}
/*	printf("Please enter the word to encrypt it:\n");
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
	}*/