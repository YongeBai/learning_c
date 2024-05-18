#include <stdio.h>

void printBits(unsigned int n)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    putchar('\n');
}

int rightrot(int n, int b)
{
    unsigned int mask = ~0u >> (32 - b);
    unsigned int x = (n & mask) << (32-b);
    n = n >> b;    
}

int main()
{
    rightrot(9, 2);
}