#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 100
#define	TAILLEAJOUT 50

int initTab(int * tab, int size) {
	if (tab == NULL || size < 0){
		return -1;
	}

	for (int i = 0; i < size; i++){
		tab[i] = 0;
	}

	return size;
}

int afficheTab(int *tab, int size, int nbElts) {

	if (tab == NULL || size < nbElts || size < 0){
		return -1;
	}

	for (int i = 0; i < nbElts; i++){
		printf_s("%d \n", tab[i]);
	}
	return 0;
}

int * ajoutElementDansTableau(int *tab, int *size, int *nbElts, int element) {


	if (*size + 1 > TAILLEINITIALE){
		nbElts++;
		int* tmp = realloc(tab, sizeof(TAILLEINITIALE + TAILLEAJOUT));
		if (tmp == NULL){
			free(tab);
			printf("L'allocation a échoué.\n");
			return NULL;
		}
		tab = tmp;
	}

	tab[*nbElts] = element;

	return nbElts;
}
