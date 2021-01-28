#include<stdio.h>
#include<stdlib.h>
#include "tab.h"

#define TAB2SIZE 100

int a = 1;

int main() {

	int myTab1[10];

	initTab(myTab1, 10);

	int * MyTab2 = NULL;

	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	initTab(MyTab2, TAB2SIZE);

	for (int i = 0; i < 20; i++){
		MyTab2[i] = a;
		a++;
	}

	afficheTab(MyTab2, TAB2SIZE, 20);
	ajoutElementDansTableau(MyTab2, TAB2SIZE, myTab1, 5);
	free(MyTab2);
	
	return(EXIT_SUCCESS);
}