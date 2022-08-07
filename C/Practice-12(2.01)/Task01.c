/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: Write a program, that will use variable type 
  struct NVtab {...}, where variable nvtab is global. Modify 
  functions addname and delname (from the example "Growing 
  Arrays", demonstrated in the first lecture), so the bodies 
  of these functions would not use global variable nvtab.
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval{
	char *name;// array of names
	int value;
};

typedef struct NVtab NVtab;
struct NVtab{
		int nval;
		int max;
		Nameval *nameval;// array of structures of Nameval type
enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname,struct NVtab *nvtab) {
	Nameval *nvp;
	if (nvtab->nameval == NULL) {
		nvtab->nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
		if (nvtab->nameval == NULL)
			return -1;
		nvtab->max = NVINIT;
		nvtab->nval = 0;
	} else if (nvtab->nval >= nvtab->max) {
		nvp = (Nameval *) realloc(nvtab->nameval, (NVGROW*nvtab->max)*sizeof(Nameval));
		if (nvp == NULL)
			return -1;
		nvtab->max *= NVGROW;
		nvtab->nameval = nvp;
	}
	nvtab->nameval[nvtab->nval] = newname;
	return nvtab->nval++;
}

int delname(char *name,struct NVtab *nvtab) {
	for(int i = 0; i < (*nvtab).nval; i++)
		if (strcmp((*nvtab).nameval[i].name, name) == 0) {
			memmove((*nvtab).nameval + i, (*nvtab).nameval + i + 1, 
            ((*nvtab).nval - (i + 1)) * sizeof(Nameval));
			(*nvtab).nval--;
			return 1;
		}
	return 0;
}

int main(void) {
	struct NVtab tabl;
	tabl.nameval = NULL;
	int curnum = addname((struct Nameval) {.name="Andy", .value=12}, &tabl);
	printf("%d\n", curnum);
	curnum = addname((struct Nameval) {.name="Billy", .value=18}, &tabl);
	printf("%d\n", curnum);
	curnum = delname("Andy", &tabl);
	printf("%d\n", curnum);
	for (int i = 0; i < tabl.nval; i++) {
		printf("%s %d\n", tabl.nameval[i].name, tabl.nameval[i].value);
	}
	return 0;
}
