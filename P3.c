#include <stdio.h>
#include <ctype.h>

int main(void){
	int k = 'a' - 'A';//'a' - 'A' = 32 По таблиці ASCII
	int S = 28;
	int i = 0;
	char a[S];
	printf("Enter symbols:\n");
	// printf("%d %d %d %d\n",'A','Z','a','z');
	while((a[i] = getchar()) != '\n' && i < sizeof(a)){
		i++;
	}
	printf("Result:\n");
	for(int j=0;j < i;j++){
		if(isupper(a[j])){
			putchar( a[j] );
		}else if(a[j] >='a' && a[j] <= 'z'){// if(islower(a[j])
			a[j] = (int)a[j] - k;
			putchar((char)a[j]);
		}else{
			putchar(a[j]);	
		}
	}
	return 0;
}