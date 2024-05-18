#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    char *text;
    struct lnode *next;
} lnode;

typedef struct pylist
{
    lnode *head;
    lnode *tail;
    int count;
} pylist;

pylist *pylist_new()
{
    pylist *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
}

void pylist_del(pylist *self)
{
    lnode *cur;
    lnode *next;
    cur = self->head;
    while (cur)
    {
        // free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

void pylist_print(pylist *self)
{
    lnode *cur;
    cur = self->head;
    printf("[");
    while (cur->next)
    {
        printf("\'%s\', ", cur->text);
        cur = cur->next;
    }
    printf("\'%s\'", cur->text);
    printf("]\n");
}

int pylist_len(pylist *self)
{
    return self->count;
}

void pylist_append(pylist *self, char *str)
{
    lnode *node;
    node = (lnode *)malloc(sizeof(lnode));    
    node->text = str;
    node->next = NULL;
    self->tail = node;
    if (self->head == NULL)
    {
        self->head = node;
    }
    else
    {
        lnode *cur = self->head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = node;
    }
    self->count++;
}

int pylist_index(pylist *self, char *str)
{
    lnode *cur = self->head;
    int index = 0;
    while (cur)
    {
        if (strcmp(cur->text, str) == 0)
            return index;
        index++;
        cur = cur->next;
    }
    return -1;
}

int strcmp(char *a, char *b)
{
    if (sizeof(a) != sizeof(b))
        return -1;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
            return -1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    pylist *lst = pylist_new();
    pylist_append(lst, "Hello World");
    pylist_print(lst);
    pylist_append(lst, "Catch");
    pylist_print(lst);
    pylist_append(lst, "Brian");
    pylist_print(lst);
    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? %d\n", pylist_index(lst, "Brian"));
    printf("Bob? %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
    return 0;
}
