/*
--------------
Name: Task01.c
--------------
Description: Write a program, that prints a mark ETCS
information by grade using "switch" operator with "case"s by
using a table with grades.
--------------
*/
#include <stdio.h>
#include <stdlib.h>
int main(void){
	printf("Please enter a mark ETCS to convert it:");
	char l = getchar();
	char k = getchar();
	switch(l){
		case 'A':
			printf("%c - Відмінно\n",l);// Perfect 
			printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");// Points up to 100 / Grade / Grade by-
			printf("       95 … 100                       A                        Відмінно\n ");// -National Scale
			break;
		case 'B':
			printf("%c - Добре\n",l);// Good
			printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
			printf("       85 … 94                        B                         Добре\n ");
			break;
		case 'C':
			printf("%c - Добре\n",l);// Good
			printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
			printf("       75 … 84                        C                         Добре\n ");
			break;
		case 'D':
			printf("%c - Задовільно\n",l);// Quite Enough
			printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
			printf("       65 … 74                        D                       Задовільно\n ");
			break;
		case 'E':
			printf("%c - Задовільно\n",l);// Quite Enough
			printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
			printf("       60 … 64                        E                       Задовільно\n ");
			break;
		case 'F':
			if(k =='x'){// Not Enough
				printf("%c%c - Незадовільно\n",l,k);
				printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
				printf("       менше 60                       Fx                     Незадовільно\n ");
			} else {// Not cleared
				printf("%c - Не допущено\n",l);
				printf("Бали за 100-бальною шкалою          Оцінка за шкалою ЄКТС          Оцінка за національною шкалою\n ");
				printf("Меньше 60,не виконання умов допуску         F                   Не допущено до семестрового контролю\n");
			}
			break;
		default:
			printf("Error.Invalid mark entered.Please use A,B,C,D,E or F\n");
			break;
	}
	printf("\nТаблиця:\n");
	printf("Бали за 100-бальною шкалою  Оцінка за шкалою ЄКТС  Оцінка за національною шкалою\n ");
	printf("       95 … 100                       A                        Відмінно\n ");
	printf("       85 … 94                        B                         Добре\n ");
	printf("       75 … 84                        C                         Добре\n ");
	printf("       65 … 74                        D                       Задовільно\n ");
	printf("       60 … 64                        E                       Задовільно\n ");
	printf("       менше 60                       Fx                     Незадовільно\n ");
	printf("не виконання умов допуску             F                   Не допущено до семестрового контролю\n");
	return 0;
}
