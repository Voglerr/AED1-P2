#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ponteiro;
} no;

void anexar(no **, int);

int main() {
    no *l = NULL;
    anexar(&l, 3); anexar(&l, 6); anexar(&l, 7);
    no *p = l;
    while (p != NULL) {
        printf("%d\n", p->valor); p = p->ponteiro;
    }
    
}

void anexar(no **L, int x) {
    if (*L == NULL) {
        // complexidade: theta(N)
        no *p = (no *) malloc(sizeof(no));
        p->ponteiro = NULL; p->valor = x;
        *L = p;
    }
    else 
        // L eh ponteiro para um ponteiro de no
        anexar(&((*L)->ponteiro), x);
}