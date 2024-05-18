#include <stdio.h>

void squeeze2(char s1[], char s2[])
{
    int j = 0, len2 = 0;

    for (int i = 0; s2[i] != '\0'; i++)
        len2++;

    for (int i = 0; s1[i] != '\0'; i++) {
        int k;
        for (k = 0; k < len2 && s1[i] != s2[k]; k++);
        if (k == len2) 
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main() {    
    char s1[] = "abcd";
    char s2[] = "ad";
    squeeze2(s1, s2);
    printf("%s\n", s1);
}