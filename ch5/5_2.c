#include <stdio.h>

void strcat(char *s, char *t) {
    while (*s)
        s++;            
    while (*s++ = *t++);    
}

void strcpy(char *s1, char *s2) {
    while (*s2++ = *s1++);
}


int main(int argc, char const *argv[])
{
    char s[50] = "hello";
    // strcpy("hello", s);    

    char *t = " world";        
    strcat(s, t);

    printf("%s\n", s);
    return 0;
}
