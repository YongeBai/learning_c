#include <stdio.h>

void reverse(char s[])
{
    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    i--;
    char tmp;
    for (; j <= i; j++, i--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itoa(int n, int w, char s[]) {
    int i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    while (i < w) {
        s[i++] = ' ';
    }    
    s[i] = '\0';
    reverse(s);
}

int main(int argc, char const *argv[])
{
    int n = 123;
    int w = 10;
    char s[10];
    itoa(n, w, s);
    printf("%s\n", s);
    return 0;
}
