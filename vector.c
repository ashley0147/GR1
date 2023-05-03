#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector *create_vector()
{

    vector *v = (vector *)malloc(sizeof(vector));
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(int) * v->capacity);
    return v;
}

int vector_total(vector *v)
{
    return v->total;
}

static void vector_resize(vector *v, int capacity)
{
    int *items = realloc(v->items, sizeof(int) * capacity);
    if (items)
    {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_pushback(vector *v, int item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

int vector_popback(vector *v)
{
    int item = vector_back(v);
    vector_delete(v, v->total);
    return item;
}

int vector_popfront(vector *v)
{
    int item = vector_front(v);
    vector_delete(v, 0);
    return item;
}
void vector_set(vector *v, int index, int item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

int vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return -1;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;
    v->items[index] = -1;
    int i;
    for (i = 0; i < v->total - 1; i++)
    {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = -1;
    }

    v->total--;
    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

int vector_front(vector *v)
{
    return vector_get(v, 0);
}

int vector_back(vector *v)
{
    return vector_get(v, v->total);
}

void vector_free(vector *v)
{
    free(v->items);
}