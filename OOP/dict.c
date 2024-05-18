#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MapEntryu
{
    char *key;
    char *value;
    struct MapEntryu *next;
} MapEntryu;

typedef struct Map
{
    MapEntryu *head;
    MapEntryu *tail;
    int count;
} Map;

Map *pydict_new()
{
    Map *p = (Map *)malloc(sizeof(Map));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

void pydict_del(Map *self)
{
    MapEntryu *cur, *next;
    cur = self->head;
    while (cur)
    {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

int pydict_len(Map *self)
{
    return self->count;
}

void pydict_print(Map *self)
{
    MapEntryu *cur = self->head;
    printf("{");
    while (cur->next)
    {
        printf("\'%s\': \'%s\', ", cur->key, cur->value);
        cur = cur->next;
    }
    printf("\'%s\': \'%s\'}\n", cur->key, cur->value);
}

MapEntryu *pydict_find(Map *self, char *key)
{
    MapEntryu *cur = self->head;
    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

char *pydict_get(Map *self, char *key)
{
    MapEntryu *entry = pydict_find(self, key);
    if (entry)
        return entry->value;
    return NULL;
}

void pydict_put(Map *self, char *key, char *value)
{
    MapEntryu *old = pydict_find(self, key);
    if (old)
    {
        free(old->value);
        old->value = malloc(strlen(value));
        strcpy(old->value, value);
    }
    else
    {
        MapEntryu *node = (MapEntryu *)malloc(sizeof(MapEntryu));
        node->key = malloc(strlen(key));
        strcpy(node->key, key);
        node->value = malloc(strlen(value));
        strcpy(node->value, value);
        node->next = NULL;

        if (self->head == NULL)
        {
            self->head = node;
        }
        else
        {
            MapEntryu *cur = self->head;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = node;
            self->count++;
        }
    }
}

int main(int argc, char const *argv[])
{
    MapEntryu *cur;
    struct Map *dct = pydict_new();

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n", pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for (cur = dct->head; cur != NULL; cur = cur->next)
    {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);

    return 0;
}
