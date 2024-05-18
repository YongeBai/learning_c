#include <stdio.h>
#include <stdlib.h>

typedef struct String
{
    int length;
    int alloc;
    char *data;
} String;

String *new_string() {
    String *s = (String *)malloc(sizeof(*s));
    s->length = 0;
    s->alloc = 10;
    s->data = malloc(s->alloc);
    s->data[0] = '\0';
    return s;
}

void del(String *self)
{
    free(self->data);
    free(self);
}

void dump(String *self) {
    printf("Object string@ %p\nlength = %d, alloc = %d\n%s\n", self, self->length, self->alloc, self->data);

}

int len(String *self) {
    return self->length;
} 

void append(String *self, char ch) {    
    if (self->length+2 > self->alloc) {        
        self->alloc+=10;
        self->data = (char *)realloc(self->data, self->alloc);
    }
    int i = 0;
    while (i < len(self))
        i++;
    self->data[i] = ch;
    self->length++;
    self->data[self->length] = '\0';
}

void appends(String *self, char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        append(self, str[i]);
}

void str_assign(String *self, char *str) {
    del(self);
    self =  new_string();
    appends(self, str);
}

int main(int argc, char const *argv[])
{
    String *s = new_string();
    dump(s);

    appends(s, "H");
    dump(s);
    appends(s, "ello world");
    dump(s);

    str_assign(s, "A completely new string");
    dump(s);
    return 0;
}
