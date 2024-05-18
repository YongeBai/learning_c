#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define LETTER 'a'

struct tnode
{
    char *prefix;
    char *words[MAXWORD];
    int i;
    struct tnode *left;
    struct tnode *right;
};

int main(int argc, const char *argv[])
{
    struct tnode *root, *treeAdd();
    char word[MAXWORD];
    int t, n = 1, get_word();
    if (argc != 2)
    {
        printf("using defualt n = 1, to change: ./6_4 -n \n");
    }
    else
        n = atoi(argv[1] + 1);

    root = NULL;
    while ((t = get_word(word, MAXWORD)) != EOF)
    {
        if (t == LETTER)
            root = treeAdd(root, word, n);
    }

    preOrder(root);

    return 0;
}

int get_word(w, lim) /* get next word from input */
char *w;
int lim;
{
    int c;
    if (!isalpha(c = *w++ = getchar()))
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        if (!isalpha(c = *w++ = getchar()))
            break;
    }
    *(w - 1) = '\0';
    return (LETTER);
}

struct tnode *treeAdd(struct tnode *p, char *w, int n)
{
    struct tnode *talloc();
    char *strsave();
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->prefix = strsave(w, n);
        p->i = 0;
        p->words[p->i] = strsave(w, strlen(w));
        p->left = p->right = NULL;
    }
    else if ((cond = strncmp(w, p->prefix, n)) == 0)
    {
        p->words[++(p->i)] = strsave(w, strlen(w));
    }
    else if (cond < 0)
    {
        p->left = treeAdd(p->left, w, n);
    }
    else
        p->right = treeAdd(p->right, w, n);
    return p;
}

preOrder(struct tnode *p)
{
    if (p != NULL)
    {
        preOrder(p->left);
        printf("%s ", p->prefix);
        for (int i = 0; p->words[i]; i++)
        {
            printf("%s, ", p->words[i]);
        }
        putchar('\n');
        preOrder(p->right);
    }
}

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strsave(char *w, int n)
{
    char *s = malloc(strlen(w) + 1);
    char *start = s;

    while ((*s = *w) && (n-- > 0))
    {
        s++;
        w++;
    }
    *s = '\0';    
    return start;
}