#include <stdio.h>
#include <string.h>

int palindromo(char *);

int main() {
    char *s = "roma e amor"; 
    if (palindromo(s)) printf("Palindromo\n");
    
    return 0;
}

int palindromo_recursivo(char *string, int inicio, int fim) {
    if (inicio == fim) return 1;
    else if (inicio == fim - 1) 
        if (string[inicio] == string[fim]) return 1;
        else return 0;

    return (string[inicio] == string[fim] && palindromo_recursivo(string, inicio + 1, fim - 1));
}

int palindromo(char *string) {
    int tamanho = strlen(string);
    return palindromo_recursivo(string, 0, tamanho - 1);
}