#include <stdio.h>

int rightIndex(char s[], char t) {
    int i = 0, res = -1;
    for (; s[i] != '\0'; i++) {
        if (s[i] == t) {
            res = i;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    char s[] = "Hello w cruel world";
    char t = 'w';
    printf("%d\n", rightIndex(s, t));
    return 0;
}
