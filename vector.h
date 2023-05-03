#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector
{
    int *array_data_;
    int capacity_;
    int size_;

} vector;
// int operator[](vector *v, const int i);
vector *create_vector();
void re_capacity(vector *v, int cap);
void re_capacity(vector *v, int cap);
void resize(vector *v, int size);
void push_back(vector *v, int value);
int size(vector *v);
int pop_back(vector *v);
int vector_get(vector *v, int index);
int pop_front(vector *v);
int vector_front(vector *v);
void vector_delete(vector *v, int index);

// int operator[](vector *v, const int i)
// {
//     return v->array_data_[i];
// }
vector *create_vector()
{
    vector *v = (vector *)malloc(sizeof(vector));
    v->array_data_ = (int *)calloc(1, sizeof(int));
    v->size_ = 0;
    v->capacity_ = 1;
}

void re_capacity(vector *v, int cap)
{
    int *temp = (int *)calloc(v->size_, sizeof(int));
    if (v->array_data_ != NULL)
        memcpy(temp, v->array_data_, v->size_ * sizeof(int));
    free(v->array_data_);
    v->array_data_ = temp;
    v->capacity_ = cap;
}

void resize(vector *v, int size)
{
    int *temp = (int *)calloc(v->size_, sizeof(int));
    if (v->array_data_ != NULL)
        memcpy(temp, v->array_data_, v->size_ * sizeof(int));
    free(v->array_data_);
    v->size_ = size;
    v->array_data_ = temp;
    v->capacity_ = size;
}

// void resize(int size, int default_value)
// {
//     int *temp = (int *)calloc(size_, sizeof(int));
//     free(array_data_);
//     size_ = size;
//     array_data_ = temp;
//     capacity_ = size;
//     for (int i = 0; i < size; i++)
//         array_data_[i] = default_value;
// }
int vector_front(vector *v)
{
    return vector_get(v, 0);
}
void push_back(vector *v, int value)
{
    if (v->capacity_ > v->size_)
    {
        v->array_data_[v->size_] = value;
        v->size_++;
    }
    else
    {
        re_capacity(v, v->capacity_ * 2);
        v->capacity_ *= 2;
        push_back(v, value);
    }
}
int size(vector *v)
{
    return v->size_;
}

int pop_back(vector *v)
{
    v->size_--;
    return v->array_data_[v->size_];
}
int vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->size_)
        return v->array_data_[index];
    return -1;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->size_)
        return;
    v->array_data_[index] = -1;
    int i;
    for (i = 0; i < v->size_ - 1; i++)
    {
        v->array_data_[i] = v->array_data_[i + 1];
        v->array_data_[i + 1] = -1;
    }

    v->size_--;
    if (v->size_ > 0 && v->size_ == v->capacity_ / 4)
        re_capacity(v, v->capacity_ / 2);
}
int pop_front(vector *v)
{
    int item = vector_front(v);
    vector_delete(v, 0);
    return item;
}
#endif