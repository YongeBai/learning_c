#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

getch() /* get a (possibly pushed back) character */
{
    if (bufp > 0) {
        if (buf[--bufp] == EOF && bufp > 0) 
            return buf[--bufp];
        else if (buf[--bufp] == EOF && bufp <= 0)
            return getchar();
    }
    else
        return getchar();
    
}

ungetch(c) /* push character back on input */
    int c;
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c == EOF)
        printf("c is EOF\n");
    else 
        buf[bufp++] = c;
}