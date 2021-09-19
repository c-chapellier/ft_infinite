#include "../ft_infinite.h"

void deepbi(bigint_t *dst, bigint_t src)
{
    reallocbi(dst, src.size);

    for (int i = 0; i < src.size; ++i)
        dst->n[i] = src.n[i];

    dst->neg = src.neg;
}
