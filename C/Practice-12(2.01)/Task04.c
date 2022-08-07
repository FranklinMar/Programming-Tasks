/*
----------------
Name: Task04.c
------------------------------------------------------------
Description: Pay attention, that code in "Growing Arrays"
  of the first lecture doesn't use next expression:
  
  nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW * nvtab.max) *
        sizeof(Nameval));
  
  In this case, if there was an error in reallocation of the 
  memory, all data would be lost. Explain, why?
  Write an example of program, in which demonstrate the 
  usage of similiar expression and how it affects the 
  occurence of errors.
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
	if (nvtab.nameval == NULL ) {
		nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
		if (nvtab.nameval == NULL)
			return -1;
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	} else if (nvtab.nval >= nvtab.max) {
		nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
		if (nvp == NULL)
			return -1;
		nvtab.max *= NVGROW;
		nvtab.nameval = nvp;
	}
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}

int delname(char *name) {
	for (int i = 0; i < nvtab.nval; i++)
		if (strcmp(nvtab.nameval[i].name, name) == 0) {
			memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval - (i + 1)) * sizeof(Nameval));
			nvtab.nval--;
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
	return 0;
}
/*
------------------------------------------------------------
Expression:	nvp = (Nameval *) realloc(nvtab.nameval,(NVGROW*nvtab.max)*sizeof(Nameval));
allocates memory of structure type "Nameval" with the help of 
realloc() function, that increases memory for "nvtab.nameval" 
element, so that structure "Nameval" could fit inside it and 
((NVGROW*nvtab.max)*sizeof(Nameval)) passes the address of 
this memory to the pointer "nvl". Later, this memory is 
passed to the element nvtab.nameval. 
(Expression: nvtab.nameval = nvp;)

Expression:	nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max) * sizeof(Nameval));
allocates memory as "Nameval" the same way, as previous 
time and passes the addres for "nvtab.nameval" element. 
However, after this, we have a function of assigning 
"nvtab.nameval" to "nvl" structure variable, memory of which 
wasn't initialized. Because of that, we have an error with a 
loss of data, because the element that had previous data, 
is assigned to the new one.
------------------------------------------------------------
*/
