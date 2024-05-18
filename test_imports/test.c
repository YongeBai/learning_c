#include <stdio.h>
#include "add.h"

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    int c = LeAdd(a, b);
    print(c);
    return 0;
}
