#include "vector.h"

int main()
{
    vector a;
    a.push_back(10);
    a.push_back(12);
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d", a[i]);
    }
}