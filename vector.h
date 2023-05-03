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
#endif