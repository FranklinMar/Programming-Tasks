/*
----------------
Name: Task07.c
------------------------------------------------------------
Description: Write a program, that will have the modified 
  function of the previous task.The function must have the
  second parameter, that will point out on how many words 
  must be read from each of the lines.
------------------------------------------------------------
*/
#include <stdio.h>

int getsen(char *string, int n, int *f) {
	int e = 1;
	for (int i = 0; i < n; i++) {
		*(string + i) = getchar();
		if (*(string + i) == '\n') {
			*(f + e) = i + 1;
			e++;
		}
	}
	*(string + n) = '\0';
	return e;
}

void str(char *string, int n, int e, int *f, int par) {
	char word[50];
	int m = 0;
	int l = 1;
	for (int j = 0, k = 0; j < e; j++) {
		l = 1;
		m = 0;
		for (int i = *(f + j); i < n && l == 1; i++, k++) {
			if (*(string + i) != ' ' && *(string + i) != '\t' && *(string + i) != '\n') {
				*(word + k) = *(string + i);
			}
			if ((*(string + i) == ' ' || *(string + i) == '\t') && m < par) {
				*(word + k) = ' ';
				m++;
			} else if (*(string + i) == '\n' || m >= par) {
				*(word + k) = ' ';
				l = 0;
			}
		}
	}
	for (int i = 0; i < n; i++){
		*(string + i) = *(word + i);
	}
	*(string + n) = '\0';
}

int main(void) {
	char string[50];
	int param;// Параметр кількості слів для зберігання
	int f = 1;
	while (f) {
		printf("\nEnter number of words to be saved:");
		scanf("%d", &param);
		if (param <= 0) {
			printf("Number of words can't be negative/0");
			getchar();
		} else {
			f = 0;
		}
	}
	printf("\nEnter lines of words:\n");
	int newline[50];// Масив з індексами нових рядків
	newline[0] = 0;// Кількість нових рядків
	int new = getsen(string, 50, newline);
	str(string, 50, new, newline, param);
	printf("The words are:%s", string);
	return 0;
}
