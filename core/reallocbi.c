#include "../ft_infinite.h"

void reallocbi(bigint_t *bi, int newsize)
{
    uint8_t *t;

    if (newsize <= bi->size)
        return ;

    t = malloc(newsize);
    for (int i = 0; i < bi->size; ++i)
        t[i] = bi->n[i];

    memset(&t[bi->size], 0, newsize - bi->size);
    free(bi->n);

    bi->n = t;
    bi->size = newsize;
}