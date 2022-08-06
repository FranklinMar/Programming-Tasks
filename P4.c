#include <stdio.h>
#include <ctype.h>

int main(void){
	printf("Enter symbol:\n");
	char a = getchar();
	if(isalpha(a)){
		printf("%c is an alphabet",a);
	}else if(isspace(a)){
		printf("SPACE was entered");
	}else{
		printf("%c is not an alphabet",a);
	}
	return 0;
}