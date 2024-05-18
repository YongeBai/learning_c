#include <stdio.h>

get_float(pn) /* get next integer from input */
    float *pn;
{
    float c;

    for (*pn = 0; c >= '0' && c <= '9'; c = getchar())
        *pn = 10.0 * (float)(*pn + c - '0');
    
    return (c);
}
int main(int argc, char const *argv[])
{
    int n, v, a[10];

    for (n = 0; n < 10 && get_float(&v) != EOF; n++)
        a[n] = v;
    
    for (int i=0; a[i] != '\0'; i++)
        printf("%d", a[i]);
    return 0;
}

