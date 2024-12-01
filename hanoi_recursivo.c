#include <stdio.h>

void hanoi(int, char, char, char);

int main() {
    hanoi(3, 'A', 'C', 'B');
}

void hanoi(int n, char tOrig, char tDest, char tAux) {
    if (n > 0) {
        hanoi(n - 1, tOrig, tAux, tDest);
        printf("%c -> %c\n", tOrig, tDest);
        hanoi(n - 1, tAux, tDest, tOrig);
    }
}