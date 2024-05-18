#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXWORD 50
#define LETTER 'a'
#define DIGIT '0'
#define NKEYS (sizeof(keytab) / sizeof(struct key))

struct key
{
    char *keyword;
    int keycount;
} keytab[] = {
    "break", 0,
    "case", 0,
    "char", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "while", 0};

main() /* count C keywords */
{
    int n, t, binary(), getword();
    char word[MAXWORD];
    clock_t start, stop;

    start = clock();

    while ((t = getword(word, MAXWORD)) != EOF)
    {
        if (t == LETTER)
            if ((n = binary(word, keytab, NKEYS)) >= 0)
                keytab[n].keycount++;
    }

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].keycount > 0)
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);

    stop = clock();
    printf("Run time: %f\n", (stop - start) / CLOCKS_PER_SEC);
}

int binary(word, tab, n) /* find word in tab[0]...tab[n-1] */
char *word;
struct key tab[];
int n;
{
    int low = 0, mid, high = n - 1, cond;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cond = (strcmp(word, tab[mid].keyword));
        if (cond < 0)
            high = mid - 1;
        else if (cond > 0)
        {
            low = mid + 1;
        }
        else
            return mid;
    }
    return (-1);
}
int getword(w, lim) /* get next word from input */
char *w;
int lim;
{
    int c, t, type();
    if (type(c = *w++ = getchar()) != LETTER)
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        t = type(c = *w++ = getchar());
        if (t != LETTER && t != DIGIT)
            break;
    }
    *(w - 1) = '\0';
    return (LETTER);
}

type(c) /* return type of ASCII character */
    int c;
{
    if (isalpha(c) || c == 34)    
        return (LETTER);

    else if (isdigit(c))
        return (DIGIT);
    else
        return (c);
}