/*
----------------
Name: Task05.c
------------------------------------------------------------
Description: -
------------------------------------------------------------
*/
#include <stdio.h>

void plus_int128(char *h[], char int128[128]) {
	int p = 0;
	for (int i = 1; i <= *h[0]; i++) {
		int y = int128[i] + * h[i] + p - 48;
		if (y > 57) {
			p = 1;
			y -= 10;
		} else
			p = 0;
		*h[i] = y;
	}
	if (p == 1) {
		*h[*h[0] + 1] = '1';
		*h[0] = *h[0] + 1;
	}
}

void multiply_int128(char *h[128], int i) {
	char int128[128];
	for (int x = 0; x < 128; x++)
		int128[x] = *h[x];
	for (int x = 1; x < i; x++)
		plus_int128(h, int128);
}

void factorial_int128(char *h[128], int i) {
	if (i == 1)
		*h[1] = '1';
	else {
		factorial_int128(h, i - 1);
		multiply_int128(h, i);
	}
}

void printf_int128(char *h[128]) {
	for (int i = *h[0]; i > 0; i--)
		printf("%c", *h[i]);
}

int main() {
	char int128[128];
	char *int128_ip[128];
	
	int128[0] = 1;
	int128_ip[0] = &int128[0];
	for (int i = 1; i < 128; i++) {
		int128[i] = 48;
		int128_ip[i] = &int128[i];
	}
	
	int i;
	scanf("%d", &i);
	factorial_int128(int128_ip, i);
	printf("factorial of %d is ", i);
	printf_int128(int128_ip);
	return 0;
}

// #include <stdio.h>
#include <string.h>
#define S 50
int main(void) {
	char text[S];
	int key;
	printf("Please enter text without spaces to cypher it:");
	scanf("%s",text);
	printf("You have entered:'%s'\n",text);
	printf("Please enter a shift value(key):");
	scanf("%d",&key);
	if (key > 0) {
		printf("Encrypted text:");
		for (int y = strlen(text) / key - 1; y >= 0; y--)
			for (int x = 0; x <= key; x++)
				if (x * (strlen(text) / key) + y < strlen(text))
					printf("%c", text[x * (strlen(text) / key) + y]);
	} else {
		printf("Error.Shift value can't be negative or 0.\nPlease enter positive numbers only");
	}
	return 0;
}
