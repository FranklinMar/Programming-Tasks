#include <stdio.h>
#include <string.h>

char* string_in(char s1[], char s2[], int w1, int w2);
void my_gets(char *word);
int main(void){
	char s1[20];
	char s2[20];
	printf("Please enter string #1:");
	my_gets(s1);
	printf("\nPlease enter string #2:");
	my_gets(s2);
	int w1 = strlen(s1);
	int w2 = strlen(s2);
    printf("Result:%p",string_in(s1,s2,w1,w2));
	return 0;
}
void my_gets(char *word){
	int size=sizeof(word);
	int i = 0;	
	*word = getchar();
	do{
		*(++word) = getchar();
		
	}while(*(word) !='\n' && *(word) !='\0' && *(word) != ' ' && (++i)<size);
	if(*(word) =='\n')
		*(word) = '\0';
}
char* string_in(char s1[], char s2[], int w1, int w2) {
	int j = 0;
	int e = 1;
	int ind;
	if (w1 >= w2) {
		for (int i = 0; i < w1; i++) {
			if (s1[i] == s2[j]) {
				if(e){
					ind = j;
					e--;
				}
				j++;
				if (j == w2-1/*індекс другого рядка дійшов до кінця*/) {
				return &s2[ind];
				}
			}
			else {
				j = 0;
			}
		}
	//return NULL;
	}
	else {
		return NULL;
	}
}

/*
#include <stdio.h>
char* string_in(char *s,char *sin){
 int i=0;
 for(int x=0;s[x]!='\0';)
 {
  if(s[x]==sin[i])
  {i++;
 if(sin[i]=='\0')
  return s;
 x++;
 }else{x=x-i+1;i=0;}
 }
 i=0;
 for(int x=0;sin[x]!='\0';)
 {
  if(sin[x]==s[i])
  {i++;
 if(s[i]=='\0')
  return sin;//нуль вказівник
 x++;
 }else{x=x-i+1;i=0;}
 }
 return NULL;
}

int main(void) {
 char s[100],s1[100];
 int i=0;
 while((s[i++]=getchar())!='\n'&&i<100);
 i=0;
 while((s1[i++]=getchar())!='\n'&&i<100);
 printf("%ld",string_in(s,s1)-s);
return 0;
}
*/







/*
#include <stdio.h>

char* string_in(char *s,char *sin);
void my_gets(char *word);
int main(void){
	char s1[20];
	char s2[20];
	printf("Please enter word #1:");
	my_gets(s1);
	printf("\nPlease enter word #2:");
	my_gets(s2);
	printf("%ld",string_in(s1,s2)-s1);
	return 0;
}
void my_gets(char *word){
	int size=sizeof(word);
	int i = 0;
	*word = getchar();
	do{
		*(++word) = getchar();
	}while(*(word) !='\n' && *(word) !='\0' && *(word) != ' ' && (++i)<size);
	if(*(word) =='\n')
		*(word) = '\0';
}
char* string_in(char *s,char *sin){
	int i=0;
	for(int x=0;s[x]!='\0';){
		if(s[x]==sin[i]){
			i++;
			if(sin[i]=='\0')
			return s;
			x++;
		}else{
		x=x-i+1;
		i=0;
		}
	}
	i=0;
	for(int x=0;sin[x]!='\0';){
		if(sin[x]==s[i]){
			i++;
			if(s[i]=='\0')
			return sin;//нуль вказівник
			x++;
		}else{
			x=x-i+1;
			i=0;
		}
	}
	return NULL;
}
*/

/*
#include <stdio.h>
#include <string.h>
#define N 50
char* string_in(char* line1, char* line2, int len1, int len2);
int main() {
  char line1[N];
  char line2[N];
  printf("Введіть рядок 1\n");
  fgets(line1, N, stdin);
  printf("Введіть рядок 2\n");
  fgets(line2, N, stdin);
  int len1 = strlen(line1);
  int len2 = strlen(line2);
  char* result = string_in(line1, line2, len1, len2);
    printf("%p", result);
  return 0;
}
char* string_in(char* line1, char* line2, int len1, int len2) {
  int j = 0;
  if (len1 >= len2) {
    for (int i = 0; i < len1; i++) {
        if (line2[j] == line1[i]) {
          j++;
          if (j == len2-1) {
            int index = i - len2 + 2;
            return &line1[index];
          }
        }
        else {
          j = 0;
        }
    }
  }
  else {
      return NULL;
    }
  
}
*/