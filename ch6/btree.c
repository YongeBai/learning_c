#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 20
#define LETTER 'a'

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main()
{
    struct tnode *root, *treeAdd();
    char word[MAXWORD];
    int t, get_word();

    root = NULL;
    while ((t = get_word(word, MAXWORD)) != EOF)
    {
        if (t == LETTER)
            root = treeAdd(root, word);
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

struct tnode *treeAdd(struct tnode *p, char *w)
{
    struct tnode *talloc();
    char *strsave();
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strsave(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = treeAdd(p->left, w);
    }
    else
        p->right = treeAdd(p->right, w);
    return p;
}

preOrder(struct tnode *p)
{
    if (p != NULL)
    {
        preOrder(p->left);
        printf("%4d %s\n", p->count, p->word);
        preOrder(p->right);
    }
}

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strsave(char *w)
{
    char *s = malloc(strlen(w) + 1);
    char *start = s;
    while (*s = *w)
    {
        s++;
        w++;
    }
    return start;
}