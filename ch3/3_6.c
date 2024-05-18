#include <stdio.h>
#include <string.h>

int main()
{
    char line[1000];
    char keep[1000];
    char prev[1000];
    while (gets(line) != NULL)
    {
        strcpy(keep, line);
        if (strcmp(keep, prev) > 0)
        {
            printf("%s\n", keep);
        }        
        strcpy(prev, keep);
    }
}