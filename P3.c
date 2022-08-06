#include <stdio.h>
#include <string.h>
#define S 50
void scital(char t[S],int key);
int main(void){
	char text[S];
	int key;
	printf("Please enter text without spaces to cypher it:");
	scanf("%s",text);
	printf("You have entered:'%s'\n",text);
	printf("Please enter a shift value(key):");
	scanf("%d",&key);
	if(key > 0){
		scital(text,key);
	}else{
		printf("Error.Shift value can't be negative or 0.\nPlease enter positive numbers only");
	}
	return 0;
}
void scital(char t[S],int key){
printf("Encrypted text:");
	for(int j=strlen(t)/key-1;j>=0;j--)
		for(int i=0;i<=key;i++)
		if(i*(strlen(t)/key)+j<strlen(t))
		printf("%c",t[i*(strlen(t)/key)+j]);
}
/* #include <stdio.h>
#include <string.h>
#define S 50
void scital(char t[S],int key);
int main(void){
	char text[S];
	int key;
	printf("Please enter text without spaces to cypher it:");
	scanf("%s",text);
	printf("You have entered:'%s'\n",text);
	printf("Please enter a shift value(key):");
	scanf("%d",&key);
	if(key > 0){
		scital(text,key);
	}else{
		printf("Error.Shift value can't be negative or 0.\nPlease enter positive numbers only");
	}
	return 0;
}
void scital(char t[S],int key){
printf("Encrypted text:");
	for(int j=0;j<=key;j++){
		for(int i=j;i<=strlen(t);i=i+key){
		printf("%c",t[i]);
		}
	}
}*/