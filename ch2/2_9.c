#include <stdio.h>

int countBits(int n) {
    int b = 0;
    while (n != 0) {
        b++;
        n &= (n-1);
    }
    return (b);
}
int main() {
    printf("%d\n", countBits(9));
}