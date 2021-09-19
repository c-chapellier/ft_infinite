#include "../ft_infinite.h"

void cleanbi(bigint_t *a)
{
    uint8_t *t;
    int i;

    if (a->n == NULL)
        return ;

    i = 0;
    while (a->n[a->size - 1 - i] == 0 && i < a->size - 1)
        ++i;
    
    if (i)
    {
        t = malloc(a->size - i);
        for (int j = 0; j < a->size - i; ++j)
            t[j] = a->n[j];
        free(a->n);
        a->n = t;
        a->size -= i;
    }
}