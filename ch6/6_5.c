#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define LETTER 'a'

struct tnode
{
    char *word;
    int lines[MAXWORD];
    int i;
    struct tnode *left;
    struct tnode *right;
};

int main()
{
    struct tnode *root, *treeAdd();
    int word[MAXWORD];
    int t, line = 0, get_word();

    root = NULL;
    while ((t = get_word(word, MAXWORD, &line)) != EOF)
    {
        if (t == LETTER)
            root = treeAdd(root, word, line);
    }

    preOrder(root);

    return 0;
}

int get_word(w, lim, line) /* get next word from input */
char *w;
int lim, *line;
{
    int c;
    if (!isalpha(c = *w++ = getchar()))
    {
        *w = '\0';
        if (c == '\n')
            (*line)++;
        return (c);
    }

    while (--lim > 0)
    {
        if (!isalpha(c = *w++ = getchar())) {
            if (c == '\n')
                (*line)++;
            break;
        }
    }
    *(w - 1) = '\0';
    return (LETTER);
}

struct tnode *treeAdd(struct tnode *p, char *w, int line)
{
    struct tnode *talloc();
    char *strsave();
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strsave(w);
        p->i = 0;
        p->lines[p->i] = line;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->lines[++(p->i)] = line;
    }
    else if (cond < 0)
    {
        p->left = treeAdd(p->left, w, line);
    }
    else
        p->right = treeAdd(p->right, w, line);
    return p;
}

preOrder(struct tnode *p)
{
    if (p != NULL)
    {
        preOrder(p->left);
        printf("%s ", p->word);
        for (int i = 0; p->lines[i]; i++)
        {
            printf("%d, ", p->lines[i]);
        }
        putchar('\n');
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