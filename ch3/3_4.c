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

void itob(int n, char s[])
{
    int i = 0;
    do
    {
        s[i++] = n % 2 + '0';
    } while ((n /= 2) > 0);

    s[++i] = '\0';
    reverse(s);
}

void itoh(int n, char s[])
{
    int i = 0;
    int remainder;
    do
    {
        remainder = n % 16;
        if (remainder > 10)
        {
            s[i++] = remainder + 55;
        }
        else
        {
            s[i++] = remainder + '0';
        }
    } while ((n /= 16) > 0);

    s[++i] = '\0';
    reverse(s);
}

int main(int argc, char const *argv[])
{
    int n = 479;
    char s[32];
    s[0] = '\0';
    itob(n, s);
    printf("%s\n", s);
    s[0] = '\0';
    itoh(n, s);
    printf("%s\n", s);
    return 0;
}
