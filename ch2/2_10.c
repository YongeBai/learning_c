#include <stdio.h>

void lower(char s[]) 
{

    for (int i = 0; s[i] != '\0'; i++) {
        (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] = s[i] - 'A' + 'a') : ' ';
    }
}

int main() {
    char s[] = "HelloO";
    lower(s);
    printf("%s\n", s);
}