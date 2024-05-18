#include <stdlib.h>
#include <string.h>

#include <stdio.h>


struct nlist
{ /* basic table entry */
    char *name;
    char *def;
    struct nlist *next; /* next entry in chain */
};

#define HASHSIZE 100
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

hash(s) /* form hash value for string s */
    char *s;
{
    int hashval;

    for (hashval = 0; *s != '\0';)
        hashval += *s++;
    return (hashval % HASHSIZE);
}

struct nlist *lookup(s) /* look for s in hashtab */
char *s;
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return (np); /* found it */
    return (NULL);       /* not found */
}

struct nlist *install(name, def) /* put (name, def) */
char *name, *def;                /* in hashtab */
{
    struct nlist *np, *lookup();
    char *strsave();
    int hashval;
    if ((np = lookup(name)) == NULL)
    { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL)
            return (NULL);
        if ((np->name = strsave(name)) == NULL)
            return (NULL);
        hashval = hash(np->name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else               /* already there */
        free(np->def); /* free previous definition */
    if ((np->def = strsave(def)) == NULL)
        return (NULL);
    return (np);
}

int remove_entry(char *name)
{
    struct nlist *np, *lookup();
    int hashval;
    if ((np = lookup(name)) != NULL)
    { /* not found */
        hashval = hash(np->name);
        hashtab[hashval] = NULL;
        free(np);
        return 0;
    }
    else              
        return -1;    
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

int main()
{
    struct nlist *result;
    // Install some key-value pairs
    install("key1", "value1");
    install("key2", "value2");
    install("key3", "value3");

    // Look up the keys
    result = lookup("key1");
    if (result != NULL)
    {
        printf("Found key1: %s\n", result->def);
    }
    else
    {
        printf("Did not find key1\n");
    }

    result = lookup("key2");
    if (result != NULL)
    {
        printf("Found key2: %s\n", result->def);
    }
    else
    {
        printf("Did not find key2\n");
    }

    result = lookup("key3");
    if (result != NULL)
    {
        printf("Found key3: %s\n", result->def);
    }
    else
    {
        printf("Did not find key3\n");
    }

    // Look up a key that was not installed
    result = lookup("key4");
    if (result != NULL)
    {
        printf("Found key4: %s\n", result->def);
    }
    else
    {
        printf("Did not find key4\n");
    }

    remove_entry("key2");
    result = lookup("key2");
    if (result != NULL)
    {
        printf("Found key2: %s\n", result->def);
    }
    else
    {
        printf("Did not find key2\n");
    }
    return 0;
}