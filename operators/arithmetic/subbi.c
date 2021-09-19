#include "../../ft_infinite.h"

static int lenght(uint8_t a)
{
    if (a & 128) return 8;
    if (a & 64) return 7;
    if (a & 32) return 6;
    if (a & 16) return 5;
    if (a & 8) return 4;
    if (a & 4) return 3;
    if (a & 2) return 2;
    if (a & 1) return 1;
    return 0;
}

static void zeros_bi(bigint_t *a, int n)
{
    a->n[a->size - 1] = a->n[a->size - 1] & (~(255 << (8 - n)));
    cleanbi(a);
}

void subbi(bigint_t *res, bigint_t a, bigint_t b)
{
    bigint_t t = {0}, onebi = {0};

    if (equals_bi(a, b))
    {
        atobi(res, "0", 16);
        return ;
    }

    if (smaller_bi(a, b))
        res->neg = 1, swapbi(&a, &b);

    reallocbi(res, a.size);

    bw_onebi(&t, b);
    reallocbi(&t, a.size);
    zeros_bi(&t, 8 - lenght(a.n[a.size - 1]));

    atobi(&onebi, "1", 16);
    addbi(&t, t, onebi);

    addbi(res, a, t);
    zeros_bi(res, 9 - lenght(res->n[res->size - 1]));
}