#include <stdio.h>

int main()
{
    char t[] = "hello";
    int length = 0, tmp;
    while (t[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < length / 2; i++)
    {
        tmp = t[i];
        t[i] = t[length - i - 1];
        t[length - i - 1] = tmp;
        length++;
    }
    printf("%s\n", t);
}
