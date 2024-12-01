#include <stdio.h>

#define MAX_N 6

typedef struct {
    int elem[MAX_N];
    int inicio; // index do primeiro elemento
    int final; // index do último elemento
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
    f->inicio = f->final = -1;
    f->tamanho = 0;
}

void enfileira(fila *f, int x) {
    if (f->tamanho == 0) {
        f->elem[0] = x;
        f->inicio = f->final = 0;
    }

    else if (f->tamanho < MAX_N) {
        if (f->final < MAX_N - 1) {
            f->elem[f->final + 1] = x;
            f->final++;
        }
        // f->final é a última posição alocada da array
        else { 
            f->elem[0] = x; f->final = 0;
        }
    }
    f->tamanho++;
}

int desinfileira(fila *f) {
    int x = f->elem[f->inicio];
    if (f->tamanho == 1) {
        f->inicio = f->final = -1;
    }
    else if (f->inicio < MAX_N - 1) f->inicio++;
    // f->inicio é a última posição alocada da array     
    else f->inicio = 0;

    f->tamanho--; return x;
    
}

int proximo(fila f) {
    return f.elem[f.inicio];
}