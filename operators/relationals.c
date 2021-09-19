#include "../ft_infinite.h"

int equals_bi(bigint_t a, bigint_t b)
{
    if (a.size != b.size)
        return 0;

    for (int i = 0; i < a.size; ++i)
        if (a.n[i] != b.n[i])
            return 0;

    return 1;
}

int not_equals_bi(bigint_t a, bigint_t b)
{            
    return !equals_bi(a, b);
}

int smaller_bi(bigint_t a, bigint_t b)
{
    if (equals_bi(a, b))
        return 0;

    if (a.size != b.size)
        return a.size < b.size;

    for (int i = a.size - 1; i >= 0; --i)
        if (a.n[i] != b.n[i])
            return a.n[i] < b.n[i];

    assert(0);
}

int greater_bi(bigint_t a, bigint_t b)
{            
    return !(equals_bi(a, b) || smaller_bi(a, b));
}

int smaller_equals_bi(bigint_t a, bigint_t b)
{            
    return !greater_bi(a, b);
}

int greater_equals_bi(bigint_t a, bigint_t b)
{            
    return !smaller_bi(a, b);
}
