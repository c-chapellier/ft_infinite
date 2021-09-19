#include "../ft_infinite.h"

int notbi(bigint_t a)
{
    if (a.size == 0)
        return 1;
    if (a.size != 1)
        return 0;

    return !a.n[0];
}

int andbi(bigint_t a, bigint_t b)
{
    return !notbi(a) && !notbi(b);
}

int orbi(bigint_t a, bigint_t b)
{
    return !notbi(a) || !notbi(b);
}

