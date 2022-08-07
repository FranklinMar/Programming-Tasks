#include <stdio.h>
void reverse(){
	char s[50];
	int i=0;
	while((s[i++]=getchar())!='\n' && i<50);
	--i;
	while(i >= 0){
		putchar(s[i]);
		i--;
	}
}

int main(void) {
	printf("Enter the sentence:");
	reverse();
	return 0;
}
/*
#include <stdio.h>
void doIt(){
 char s[100];
 int i=0;
 while((s[i++]=getchar())!='\n'&&i<100);
 i--;
 while(i>=0)
  putchar(s[i--]);
}

int main(void) {
 doIt();
return 0;
}
*/