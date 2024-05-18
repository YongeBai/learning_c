#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int value;
    struct lnode *next;
};

struct list
{
    struct lnode *head;
    struct lnode *tail;
};

int main()
{
    void list_add();
    void list_dump();
    struct lnode *list_find();

    struct list mylist;
    struct lnode *mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42);

    list_remove(&mylist, 10);
    list_dump(&mylist);

    list_remove(&mylist, 30);
    list_dump(&mylist);

    list_add(&mylist, 40);
    list_dump(&mylist);
}

void list_dump(lst) struct list *lst;
{
    struct lnode *cur;
    printf("\nDump:\n");
    for (cur = lst->head; cur != NULL; cur = cur->next)
    {
        printf("  %d\n", cur->value);
    }
}

void list_add(lst, value) struct list *lst;
int value;
{
    /* Append the value to the end of the linked list. */
    struct lnode *node, *cur;
    node = (struct lnode *)malloc(sizeof(struct lnode));
    node->value = value;
    node->next = NULL;
    lst->tail = node;
    if (lst->head == NULL)
    {
        lst->head = node;
    }
    else
    {
        cur = lst->head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = node;
    }
}

struct lnode *list_find(lst, value)
struct list *lst;
int value;
{
    struct lnode *cur;
    cur = lst->head;    
    while (cur != NULL)
    {
        if (cur->value == value)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void list_remove(lst, value) struct list *lst;
int value;
{
    struct lnode *cur, *prev;
    cur = lst->head;
    while (cur != NULL)
    {
        if (cur->value == value) {
            if (cur == lst->head) 
                lst->head=cur->next;
            else
                prev->next = cur->next;
        }
            
        prev = cur;
        cur = cur->next;
    }
}