#include <stdio.h>

void printBits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        unsigned int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    putchar('\n');
}

void invert(unsigned int x, int p, int n) {
    unsigned mask = (~0u << (32- n)) >> (32-n);
    mask = mask << (p+1-n);
    x = x ^ mask;
    printBits(x);
    
}

int main() {
    invert(13, 2, 2);
}