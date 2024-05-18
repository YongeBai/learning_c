#include <stdio.h>
#define strcpy(s, t)    \
    char *i = s;        \
    char *j = t;        \
    while (*i++ = *j++) \
        ;

int main(int argc, char const *argv[])
{
    char s[] = "123";
    char t[10];
    strcpy(s, t);
    printf("%s %s\n", s, t);
    return 0;
}
