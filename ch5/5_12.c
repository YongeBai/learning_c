#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINES 100 /* max number of lines to be sorted */

char to_lower();

main(argc, argv) /* sort input lines */
    int argc;
char *argv[];
{
    char *lineptr[LINES], *s; /* pointers to text lines */
    int nlines;               /* number of input lines read */
    int strcmp(), strcmp_fold(), numcmp();   /* comparison functions */
    int swap();               /* exchange function */
    int numeric = 0, reverse = 0, fold = 0;          /* 1 if numeric sort */

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        for (s = argv[0] + 1; *s != '\0'; s++)
        {
            switch (*s)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                fold = 1;
                break;
            default:
                break;
            }
        }
    }

    if ((nlines = readlines(lineptr, LINES)) >= 0)
    {
        if (numeric)
            sort(lineptr, nlines, reverse, numcmp, swap);
        else if (fold)
            sort(lineptr, nlines, reverse, strcmp_fold, swap);
        else
            sort(lineptr, nlines, reverse, strcmp, swap);
        writelines(lineptr, nlines);
    }
    else
        printf("input too big to sort\n");
}

sort(v, n, r, comp, exch) /* sort strings v[0]...v[n-1] */
    char *v[];            /* into increasing order */
int n, r;
int (*comp)(), (*exch)();
{
    int gap, i, j;
    char *v1, *v2;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0; j -= gap)
            {
                v1 = v[j];
                v2 = v[j + gap];
                if (r)
                {
                    if ((*comp)(v1, v2) > 0)
                        break;
                }
                else
                {
                    if ((*comp)(v1, v2) <= 0)
                        break;
                }
                (*exch)(&v[j], &v[j + gap]);
            }
}

numcmp(s1, s2) /* compare s1 and s2 numerically */
    char *s1,
    *s2;
{
    double atof(), v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return (-1);
    else if (v1 > v2)
        return (1);
    else
        return (0);
}

int strcmp_fold(s1, s2)
char *s1, *s2;
{
    char lower();
    while (lower(s1++) == lower(s2++))
    {
        if (*s1 == '\0')
            return 0;
    }
    return lower(s1) - lower(s2);
}

char lower(char *s) {
    char c;
    if (*s <= 'Z' && *s >= 'A') 
        c = s + 'a' - 'A';
    else
        c = s;
    return c;
}

swap(px, py) /* interchange *px and *py */
    char *px[],
    *py[];
{
    char *temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

writelines(lineptr, nlines) /* write output lines */
    char *lineptr[];
int nlines;
{
    while (--nlines >= 0)
        printf("%s\n", *lineptr++);
}

readlines(lineptr, maxlines) /* read input lines */
    char *lineptr[];         /* for sorting */
int maxlines;
{
    int len, nlines, get_line();
    char *p, line[LINES];

    nlines = 0;
    while ((len = get_line(line, LINES)) > 0)
        if (nlines >= maxlines)
            return (-1);
        else if ((p = malloc(len)) == NULL)
            return (-1);
        else
        {
            line[len - 1] = '\0'; /* zap newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return (nlines);
}

int get_line(char s[], int max)
{
    int i = 0;
    char c;
    while (i < max - 1 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}