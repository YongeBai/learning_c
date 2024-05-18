#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;

    void (*del) (struct Point *self);
    void (*display) (struct Point *self);
    double (*origin) (struct Point *self);
} Point;

void del(Point *self)
{
    free(self);
}

void display(Point *self)
{
    printf("Object point@ %p\nx = %f, y = %f\n", self, self->x, self->y);
}

double origin(Point *self)
{
    return sqrt(self->x*self->x+self->y*self->y);
}

Point *new_point(double x, double y) {
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->del = &del;
    p->display = &display;
    p->origin = &origin;
    return p;
}
int main(int argc, char const *argv[])
{
    Point *p = new_point(4.0, 5.0);
    p->display(p);
    printf("Origin = %f\n", p->origin(p));
    p->del(p);
    return 0;
}

