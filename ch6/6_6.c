#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
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
    
    struct tnode *words[MAXWORD];
    int i = 0, compare();

    fillWords(root, words, &i);
    
    qsort(words, i, sizeof(struct tnode *), compare);
    for (int j = 0; j < i; j++)
    {
        printf("%4d %s\n", words[j]->count, words[j]->word);
    }
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

fillWords(struct tnode *p, struct tnode *words[], int *i)
{
    
    if (p != NULL && *i < MAXWORD)
    {
        words[(*i)++] = p;
        fillWords(p->left, words, i);        
        fillWords(p->right, words, i);
    }
}

int compare(const void *a, const void *b)
{
    struct tnode *ta = (struct tnode *)a;
    struct tnode *tb = (struct tnode *)b;
    return tb->count - ta->count;
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