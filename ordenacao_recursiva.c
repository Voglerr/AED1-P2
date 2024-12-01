#include <stdio.h>

int* merge_sort(int *, int);

int main() {
    int l[] = {4, 6, 3, 7, 8, 13};
    merge_sort(l, sizeof(l) / sizeof(l[0]));
    for (int i = 0; i < 6; i++) printf("%d\n", l[i]);

}

void merge(int *v, int inicio, int meio, int fim) {
    int tamanho_1 = meio - inicio + 1;
    int tamanho_2 = fim - meio;

    // Duas arrays ordenadas
    int arr_1[tamanho_1], arr_2[tamanho_2];
    for (int i = 0; i < tamanho_1; i++)
        arr_1[i] = v[inicio + i];
    for (int j = 0; j < tamanho_2; j++)
        arr_2[j] = v[meio + 1 + j];

    // Combinando arr_1 e arr_2
    for (int i = 0, j = 0, k = inicio; k <= fim; k++) {
        if (i < tamanho_1 && (j >= tamanho_2 || arr_1[i] <= arr_2[j])) {
            v[k] = arr_1[i]; i++;
        }
        else {
            v[k] = arr_2[j]; j++;
        }
    }

}

void merge_recursion(int *v, int inicio, int fim) {
    /* Inclui o index fim */
    // se inicio = fim, entao so existe um elemento em v, que esta ordenado
    if (inicio < fim) {

        int meio = inicio + (fim - inicio) / 2;
        merge_recursion(v, inicio, meio);
        merge_recursion(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int* merge_sort(int *v, int tamanho) {
    /* Funcao auxiliar */
    merge_recursion(v, 0, tamanho - 1);
    return v;
}