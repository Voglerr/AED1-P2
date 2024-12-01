#include <stdio.h>
#include <stdlib.h>

int busca_1(int[], int, int);
int busca_2(int[], int, int, int);
int busca_3(int[], int, int, int);
int busca_binaria(int[], int, int, int);

int main() {
    int l[] = {4, 6, 3, 7, 8, 10, 11, 21};
    // for (int i = 0; i < 22; i++) 
    //     printf("%d -> %d\n", i, busca_1(l, 8, i));
    
    for (int i = 0; i < 22; i++) 
        printf("%d -> %d\n", i, busca_3(l, 0, 8, i));
    
    int l_ord[] = {3, 1, 6, 7, 8, 10, 11, 21};
    for (int i = 0; i < 22; i++)
        printf("%d -> %d\n", i, busca_binaria(l_ord, 0, 8, i));
    return 0;
}

int busca_1(int v[], int n, int x) {
    if (n == 0) return -1; // elemento nao encontrado
    if (v[n - 1] == x) return n - 1;

    return busca_1(v, n - 1, x); 
}

int busca_2(int v[], int inicio, int fim, int x) {
    if (inicio == fim) return -1;

    if (v[inicio] == x) return inicio;
    return busca_2(v, inicio + 1, fim, x);
}

int busca_3(int v[], int inicio, int fim, int x) {
    // Caso base
    if (inicio >= fim) return -1;

    int meio = (inicio + fim) / 2;
    // Caso geral
    if (v[meio] == x) return meio;
    else {
        int pos = busca_3(v, inicio, meio, x);
        if (pos == -1) return busca_3(v, meio + 1, fim, x);
        else return pos;
    }
}

int busca_binaria(int v[], int inicio, int fim, int x) {
    /* Supoe vetor ordenado */
    if (inicio >= fim) return -1;

    int meio = (inicio + fim) / 2;
    if (v[meio] == x) return meio;
    else if (v[meio] > x) return busca_binaria(v, inicio, meio, x);
    else return busca_binaria(v, meio + 1, fim, x);

}