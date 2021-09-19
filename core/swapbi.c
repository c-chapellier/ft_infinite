#include "../ft_infinite.h"

void swapbi(bigint_t *a, bigint_t *b)
{
    uint8_t *n;
    int size;

    n = a->n;
    a->n = b->n;
    b->n = n;

    size = a->size;
    a->size = b->size;
    b->size = size;
}