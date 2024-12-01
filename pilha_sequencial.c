#include <stdio.h>

#define MAX_N 100

typedef struct {
    int elem[MAX_N];
    int tamanho;
} pilha;

void constroi(pilha *);
int desempilha(pilha *);
void empilha(pilha *, int);
int topo(pilha);

int main() {
    pilha p; constroi(&p);
    empilha(&p, 3); printf("%d\n", topo(p));
    empilha(&p, 5); printf("%d\n", topo(p));
    empilha(&p, 7); printf("%d\n", desempilha(&p)); printf("%d\n", topo(p));
}

int topo(pilha P) {
    return P.elem[P.tamanho - 1];
}

void constroi(pilha *P) {
    P->tamanho = 0;
}

int desempilha(pilha *P) {
    if (P->tamanho > 0) {
        (P->tamanho)--; return P->elem[P->tamanho];
    }
}

void empilha(pilha *P, int x) {   
    if (P->tamanho < MAX_N) {
        P->elem[P->tamanho] = x; (P->tamanho)++;
    }
    else printf("Overflow\n");
}