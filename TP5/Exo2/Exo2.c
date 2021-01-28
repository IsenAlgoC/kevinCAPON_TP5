#include <stdlib.h>
#include <stdio.h>

typedef struct Tableau {
	int *elt;
	int size;
	int eltsCount;
} TABLEAU;

#define TAILLEINITIALE 100

TABLEAU newArray();

int elt = TAILLEINITIALE;

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.elt = NULL;
	tab.eltsCount = 0;
	tab.elt = (int*)malloc(tab.size * sizeof(int));

	for (int i = 0; i < tab.size; i++) {
		tab.elt[i] = 0;
	}
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {

	if ((*tab).elt == NULL) {
		return -1;
	}
	else {
		int Size2 = (*tab).size += incrementValue;
		int* tmpMemoire = (int*)calloc(Size2, sizeof(int));
	}
	if ((*tab).elt == NULL) { 
		return -1;
	}
	for (int i = (*tab).size; i < (((*tab).size + incrementValue) - 1); i++) {
		(*tab).elt[i] = 0;
	}

	return tab->size;
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (tab == NULL) {
		return 0;
	}
	else if (pos > tab->size)
	{
		incrementArraySize(tab, pos - ((*tab).size));
	}

	(*tab).elt[pos - 1] = element; 

	if (pos > tab->eltsCount)
	{
		(*tab).eltsCount = pos;
	}
	return pos;

}


int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos >= endPos)) {
		return -1;
	}
	else {
		if (startPos <= endPos) {
			for (int i = startPos; i < endPos + 1; i++) {
				printf("%d", (*tab).elt[i]);
			}
		}
		else {
			for (int i = startPos; i < endPos + 1; i++) {
				printf("%d", (*tab).elt[i]);
			}
		}
		return 0;
	}
}


int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	if ((*tab).elt == NULL || startPos<0 || startPos>(*tab).size || endPos > (*tab).size || endPos < 0) {
		return -1;
	}
	else {
		if (startPos > endPos) {
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (int i = startPos; i < endPos + 1; i++) {
			tab[i] = tab[i + 1];
			(*tab).size = (*tab).size--;
		}
	}

	return tab->size;
}

int main() {
	TABLEAU tab = newArray();
	incrementArraySize(&tab, 5);
	setElement(&tab, 2, 6);
	displayElements(&tab, 1, 9);
	deleteElements(&tab, 10, 17);

	return EXIT_SUCCESS;
}
