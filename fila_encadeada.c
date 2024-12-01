#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    int valor;
} no;

typedef struct {
    no *inicio, *final;
    int tamanho;
} fila;

void constroi(fila *);
void enfileira(fila *, int);
int desinfileira(fila *);
int proximo(fila);

int main() {
    return 0;
}

void constroi(fila *f) {
    f->tamanho = 0, f->inicio = NULL, f->final = NULL;
}

void enfileira(fila *f, int x) {
    no *novo = (no *) malloc(sizeof(no));
    novo->valor = x, novo->prox = NULL;
    if (f->tamanho > 0) {
        f->final->prox = novo;
        f->final = novo;
    }
    else {
        f->inicio = f->final = novo;
    }
    f->tamanho++;
}

int desinfileira(fila *f) {
    if (f->tamanho > 0) {
        no *p; p = f->inicio;
        int x = p->valor;
        f->inicio = p->prox;
        free(p); f->tamanho--;
        return x;
    }
}

int proximo(fila f) {
    return f.inicio->valor;
}