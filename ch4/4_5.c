#include <stdio.h>

int buf = 0;      

getch() /* get a (possibly pushed back) character */
{
    return ((buf) ? buf : getchar());
}

ungetch(c) /* push character back on input */
    int c;
{
    if (buf)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}

int main(int argc, char const *argv[])
{
    getch();
    ungetch('n');
    printf("%c\n", buf);
    ungetch('z');
    return 0;
}
