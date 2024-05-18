#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10


void strcpy(char *dest, char *src) {
    while (*dest++ = *src++);        
}

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *save[MAXLINE];
    int len, n = MAXLINE;

    if (argc != 2)
    {
        printf("Error, usage ./5_10 -n\n");
        return -1;
    }    
    else
        n = atoi(argv[1]+1);
    
    char **s = save;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        *s = malloc(len+1);
        strcpy(*s, line);
        s++;
    }
    
    int saved = s - save;
    int start = (saved > n) ? saved - n : 0;
    for (char **ptr = save + start; ptr < s; ptr++) {
        printf("%s", *ptr);
        free(*ptr);
    }
    return 0;
}

get_line(s, lim) /* get line into s, return length */
    char s[];
int lim;
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return (i);
}

