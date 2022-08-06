#include <stdio.h>
int main(){
	char c1, c2;
	int diff;
	float num;
	c1 = 'S';
	c2 = 'O';
	diff = c1 - c2;//Компілятор переводить змінні с1 і с2 в табличний номер ASCII,віднімає ці номери і зберігає різницю в змінній diff
	num = diff;// Компілятор переводить значення типу int в тип float та зберігає її в змінній num
	printf("%c%c%c:%d %3.2f\n", c1, c2 ,c1, diff, num);
	return 0;
}