#include <stdio.h>

int wordlength() 
{
    unsigned x = ~0u;
    int bits = 0;
    while (x != 0) {
        x = x >> 1;
        bits++;        
    }
    return (bits);
}

int main() {
    printf("%d\n", wordlength());
}