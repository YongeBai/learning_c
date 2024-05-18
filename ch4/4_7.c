#include <stdio.h>
#include <math.h>

itoa(int n, char s[])
{
    int i = 0;
    if (n/10) {
        i = itoa(n/10, s);
    }
    else if (n < 0)        
        s[i++] = '-';

    s[i++] = abs(n%10) + '0';    
    s[i] = '\0';
    return i;
}
int main(int argc, char const *argv[])
{
    int n = -123;
    char s[10];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}
