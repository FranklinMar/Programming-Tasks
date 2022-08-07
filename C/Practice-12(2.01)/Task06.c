/*
----------------
Name: Task06.c
------------------------------------------------------------
Description: Repeat the code, implemented in the example of
  the first task, and insert some changes inside of it.
  Change the code of functions addname() and delname(), so
  you could delete names by indicating them as unused.
  
  After the successful execution of the program, give answer
  on the following question: How much isolated the rest of 
  the program is from these changes?

  Hint: The alternative to moving elements (memmove) inside 
    of the array - is to indicate selected elements as unused.
    Then, to add a new element, you have to find the free 
    cell, and only if there is none, increase the array to a 
    new size. In the example to the first lecture, to 
    indicate the element as unused, it's field name is 
    assigned to NULL value.
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
};

struct NVtab {
	int nval;
	int max;
	Nameval *nameval;
} nvtab;

enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname) {
	Nameval *nvp;
	int empty;
	int ind = 0;
	if (nvtab.nameval == NULL) {
		nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
		if (nvtab.nameval == NULL)
			return -1;
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	} else if (nvtab.nval >= nvtab.max) {
		for (int i = 0; i < nvtab.nval && ind == 0; i++) {
			if (nvtab.nameval[i].name == NULL) {
				empty = i;
				ind = 1;
			}
		}
		if (ind) {
			nvtab.nameval[empty] = newname;
			return -2;
		} else {
		  nvp = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max) * sizeof(Nameval));
		  if(nvp == NULL)
			  return -1;
		  nvtab.max *= NVGROW;
		  nvtab.nameval = nvp;
		}
	}
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}

int delname(char *name) {
	for (int i = 0; i < nvtab.nval; i++)
		if (strcmp(nvtab.nameval[i].name, name) == 0) {
			nvtab.nameval[i].name = NULL;
			//nvtab.nval--;
			return 1;
		}
	return 0;
}

int main(void) {
	int curnum = addname((struct Nameval) {.name="Andy", .value=12});
	printf("%d\n", curnum);
	curnum = addname((struct Nameval) {.name="Billy", .value=18});
	printf("%d\n", curnum);
	for (int i = 0; i < nvtab.nval; i++) {
		printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
	}
	curnum = delname("Andy");
	printf("%d\n", curnum);
	curnum = addname((struct Nameval) {.name="Hank", .value=16});
	printf("%d\n", curnum);
	/*curnum = addname((struct Nameval) {.name="Arkasha", .value=6});
	printf("%d\n",curnum);*/
	for(int i = 0; i < nvtab.nval; i++) {
		printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
	}		
	return 0;
}
