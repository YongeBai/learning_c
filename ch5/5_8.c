#include <stdio.h>
#define MAXLINE 100

entab(int t) /* get line into s, return length */
{
    int c, i;
    int spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;
            if (spaces % t == 0) {
                putchar('\t');
                spaces = 0;
            }
        }
        else {
            while (spaces > 0) {
                putchar(' ');
                spaces--;
            }
        }
        putchar(c);
    }
    
}

int atoi(char s[]) {
    int n = 0, i = 0;
    while (s[i]) {
        n = n * 10 + s[i]-'0';
        i++;
    }
    return n;
}

int main(int argc, char const *argv[])
{    
    char *s;
    int t = 10;
    while (--argc>0 && (*++argv )[0] == '-') {
        for (s = argv[0]+1; *s != '\0'; s++) {
            switch (*s)
            {
            case 't':
                t = atoi(s);
                break;            
            default:
                break;
            }
        }
    }
    
    entab(t);

    return 0;
}
