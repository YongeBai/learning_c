#include <stdio.h>
#define BUFSIZE 2

char buf[20][BUFSIZE]; 
int bufp = 0;      

ungets(char s[])
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        strncpy(buf[bufp++], s, 20);
}

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char s1[] = "hey";
    char s2[] = "goodbye";
    char s3[] = "NOOOO";
    ungets(s);
    checkStrings();
    ungets(s1);
    checkStrings();
    ungets(s2);
    checkStrings();
    ungets(s3);
    checkStrings();
    return 0;
}

checkStrings() {
    for (int i = 0; i < BUFSIZE; i++) {
        printf("%s\n", buf[i]);
    }
    printf("end\n");
}
