#include <stdio.h>

int atoi(char *s)
{
    int n = 0;
    while (*s)
    {
        n = n * 10 + *s - '0';
        s++;
    }
    return n;
}

void reverse(char *s)
{
    char *i = s;
    char tmp;
    while (*i)
        i++;
    i--;
    while (s < i)
    {
        tmp = *s;
        *s++ = *i;
        *i-- = tmp;
    }
}

void iota(int n, char *s)
{
    do
    {
        *s = n % 10 + '0';
        s++;
    } while (n /= 10);
    reverse(s);
}

int main(int argc, char const *argv[])
{
    char s[] = "123";
    printf("%d\n", atoi(s));
    reverse(s);
    printf("%s\n", s);
    int n = 321;
    iota(n, s);
    printf("%s\n", s);
    return 0;
}
