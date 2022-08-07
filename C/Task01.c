/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: A incomplete code of program was given to you.
  Let's review next call of function: 'call: x = 
  pr("Ho Ho Ho!")'. Write a full completed version of 
  program and answer or implement next problems (tasks).
  
A) What will be printed out by function?
B) Whate will be the type of "x" variable?
C) What value will be stored inside "x"?
D) What will expression "*--pc" mean? And how does it differ 
   from "--*pc"?
E) What will be printed out if expression "*--pc" will be 
   replaced by "*pc--"?
F) For what or why there is 2 while loops?
G) What will happen, if pr() will be given zero arguments?
H) What needs to be done in calling of function, for it's 
   proper use, as showed?
------------------------------------------------------------
*/
#include <stdio.h>

char *pr(char *str);

int main(void) {
	char x;
	x = pr("Ho Ho Ho!");
	printf("%c", x);
	return 0;
}

char *pr(char *str){
	char *pc;
	pc = str;
	while (*pc)
		putchar(*pc++);
	do {
		putchar(*--pc);
	} while (pc-str);
	return (pc);
}
/*
------------------------------------------------------------
A - Function will print - "Ho Ho Ho!!oH oH oH"
B - char type
C - "x" will have '\0' value
D - expression "*--pc" means that the address of "pc" pointer 
    will be reduced by 1, meaning it will move to the previous 
    element, and then it will go by address and return a value.
  - expression "*--pc" differs from "--*pc" because the first 
    one moves pointer to previous на 1, and the latest one 
    reduces value of pointer's value by 1.
E - if expression "*--pc" will be replaced by "*pc--", then 
    the operations done to the expression will be done on 
    pointer "pc" with the address, and after that it will 
    change it's address to the previous one, thus the last 
    element of the array won't be reached.
F - "while" loops are used for printing array elements in 
    direct and reversed order, respectively.
G - if pr() will have none arguments, then function will 
    reach out of bounds section of memory and will start 
    to print contents of addresses past the pointer.
H - don't write prefix 'call:', and print '*' before the call
------------------------------------------------------------
*/ 
