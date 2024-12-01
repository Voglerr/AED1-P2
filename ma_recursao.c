#include <stdio.h>

float media_aritmetica(int, int[]);

int main() {
    int l[] = {1, 2, 3, 4, 5, 6};
    printf("%f\n",media_aritmetica(6, l)); //media_aritmetica(2, l); media_aritmetica(3, l);
    return 0;
}

float media_aritmetica(int n, int v[]) {
    if (n == 1) return v[0];
    return ( ( (n - 1) * media_aritmetica(n - 1, v) + v[n - 1] ) / (float) n );
}