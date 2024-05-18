#include <stdio.h>

void extend(char s[], char t[]) {
    int i = 0, j = 0;
    while (s[i] == ' ' || s[i] == '-') {
        i++;
    }
    char prev, nxt;     
    char k;
    for (;s[i] != '\0'; i++) {
        if (s[i] == '-') {
            prev = s[i-1];
            nxt = s[i+1];
            for (k = 1; k < nxt - prev; k++) {
                t[j] = prev + k;
                j++;
            }            
        }
        else {
            t[j] = s[i];
            j++;
        }
            
    }    
    t[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char s[] = "a-b-f0-91-4";
    char t[50];
    t[0] = '\0';
    printf("%s\n", s);
    extend(s, t);
    printf("%s\n", t);
}
