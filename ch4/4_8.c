#include <stdio.h>
#include <string.h>

preverse(char s[], int i) {
    if (s[i] == '\0') {
        return 0;
    }
    preverse(s, ++i);
    putchar(s[--i]);    
}

int reverse(char s[], int start, int end)
{     
    if (start >= end) {
        return 0;
    }
    char tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    reverse(s, start+1, end-1);
}

// int main(int argc, char const *argv[])
// {
//     char s[] = "hello";
//     preverse(s, 0);
//     printf("\n");
//     int len = 0;
//     while (s[len] != '\0') {
//         len++;
//     }
//     reverse(s, 0, len-1);
//     printf("%s\n", s);
//     return 0;
// }
