#include <stdio.h>


entab(int m, int n) /* get line into s, return length */
{
    int curWords = 0, totalWords = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            curWords++;
            totalWords++;
            if (totalWords > m) {
                if (curWords % n == 0) {
                    putchar('\t');
                    curWords = 0;
                }                                        
            }
            putchar(' ');
        }
        else
            putchar(c);
    }
}

int atoi(char s[])
{
    int n = 0, i = 0;
    while (s[i])
    {
        n = n * 10 + s[i] - '0';
        i++;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    char *s;
    int n=5, m=1;
    while (--argc > 0)
    {
        for (s = argv; *s != '\0'; s++) {
            switch (*s)
            {
            case 'm':
                m = atoi(*s);
                break;
            case '+':
                n = atoi(*(s+1));
                break;
            default:
                break;
            }
        }        
    }
    
    entab(m, n);

    return 0;
}
