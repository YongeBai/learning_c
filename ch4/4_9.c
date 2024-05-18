#include <stdio.h>
#define swap(x, y) \
    tmp = x; \
    x = y; \
    y = tmp;

int main(int argc, char const *argv[])
{
    int x = 20;
    int y = 40;
    int tmp;
    swap(x, y);
    printf("%d %d\n", x, y);
    return 0;
}

