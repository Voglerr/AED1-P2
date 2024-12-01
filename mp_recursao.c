#include <stdio.h>

int soma(int[], int); 
float media_ponderada(int[], int[], int);

int main() {
    int l1[] = {6, 4, 5, 3, 2, 7}; int l2[] = {1, 2, 3, 4, 5, 6};
    printf("%f\n", media_ponderada(l1, l2, 6));
}

int soma(int t[], int n) {
    if (n == 1) return t[0];
    return t[n-1] + soma(t, n - 1);
}

float media_ponderada(int v[], int t[], int n) {
    /* MP(N) = (p1a1+ ... + pNaN)/(p1+ ... + pN) 
       v = [a1, a2, ... an], t = [p1, p2, ... pn]
    */    
    if (n == 1) return v[0];
    return (media_ponderada(v, t, n - 1) * (soma(t, n - 1)) + v[n - 1] * t[n-1]) / (float) soma(t, n);
}