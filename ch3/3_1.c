#include <stdio.h>

int main() {
    char s[] = "Hello\nThere";
    char t[50];
    printf("%s\n", s);
    extend(s, t);
    printf("%s\n", t);
    return 0;
}

void extend(char s[], char t[]) {
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            t[i] = '\\n';
        }
        else if (s[i] == '\t')
        {
            t[i] = '\\t';
        }      
        else {
            t[i] = s[i];
        }  
    }

}