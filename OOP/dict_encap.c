#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MapEntry
{
    char *key;
    int value;
    struct MapEntry *__prev;
    struct MapEntry *__next;

} MapEntry;

typedef struct Map
{
    MapEntry *__head;
    MapEntry *__tail;
    int __count;

    void (*put) (struct Map *self, char *key, int value);
    int (*get) (struct Map *self, char *key, int def);
    int (*size) (struct Map *self);
    void (*dump) (struct Map *self);
    void (*del) (struct Map *self);
} Map;

void __Map_dump(Map *self)
{
    MapEntry *cur = self->__head;
    printf("Object Map count=%d\n", self->__count);
    while (cur)
    {
        printf(" %s=%d\n", cur->key, cur->value);
        cur = cur->__next;
    }    
}

void __Map_del(Map *self)
{
    MapEntry *cur, *next;
    cur = self->__head;
    while (cur)
    {
        free(cur->key);
        next = cur->__next;
        free(cur);
        cur = next;
    }
    free(self);
}

int __Map_size(Map *self)
{
    return self->__count;
}

MapEntry *__Map_find(Map *self, char *key)
{
    MapEntry *cur = self->__head;
    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
            return cur;
        cur = cur->__next;
    }
    return NULL;
}

int __Map_get(Map *self, char *key, int def)
{
    MapEntry *entry = __Map_find(self, key);
    if (entry)
        return entry->value;
    return def;
}

void __Map_put(Map *self, char *key, int value)
{
    MapEntry *old = __Map_find(self, key);
    if (old)
    {
        old->value = value;
    }
    else
    {
        MapEntry *node = (MapEntry *)malloc(sizeof(MapEntry));
        node->key = malloc(strlen(key));
        strcpy(node->key, key);
        node->value = value;
        node->__next = NULL;

        if (self->__head == NULL)
        {
            self->__head = node;            
        }
        else
        {
            MapEntry *cur = self->__head;
            while (cur->__next)
            {
                cur = cur->__next;
            }
            cur->__next = node;
            node->__prev = cur;
            self->__count++;
        }
    }
}

Map *Map_new()
{
    Map *p = (Map *)malloc(sizeof(Map));
    p->__head = NULL;
    p->__tail = NULL;
    p->__count = 0;

    p->del = &__Map_del;
    p->put = &__Map_put;
    p->get = &__Map_get;
    p->dump = &__Map_dump;
    p->size = &__Map_size;

    return p;
}

int main(void)
{
    struct Map *map = Map_new();
    struct MapEntry *cur;

    printf("Map test\n");
    map->put(map, "z", 8);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "a", 4);
    map->dump(map);

    printf("size=%d\n", map->size(map));

    printf("z=%d\n", map->get(map, "z", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    map->del(map);
}