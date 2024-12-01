#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    int valor;
} no;

typedef struct {
    no *inicio;
    int n;
} pilha;

void constroi(pilha *);
int desempilha(pilha *);
void empilha(pilha *, int);
int topo(pilha);

int main() {
    pilha p; constroi(&p);
    empilha(&p, 3); empilha(&p, 5); empilha(&p, 7);
    printf("%d %d\n", topo(p), p.n); printf("%d %d\n", desempilha(&p), p.n);
    printf("%d %d\n", topo(p), p.n); printf("%d %d\n", desempilha(&p), p.n);
}

void constroi(pilha *p) {
    p->n = 0; p->inicio = NULL;
}

int desempilha(pilha *p) {
    if (p->inicio != NULL) {
        no *ptr = p->inicio; int x = ptr->valor;
        p->inicio = ptr->prox; free(ptr); 
        p->n--; return x;
    }
    else return -1;
}

void empilha(pilha *p, int x) {
    no *novo = (no *) malloc(sizeof(no));
    novo->valor = x; novo->prox = p->inicio;
    p->inicio = novo; p->n++;
}

int topo (pilha p) {
    if (p.n > 0)
        return p.inicio->valor;
    else return -1;
}