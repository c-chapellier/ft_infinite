#include "../../ft_infinite.h"

void addbi(bigint_t *res, bigint_t a, bigint_t b)
{
    int carry = 0, sum;
    int max_size = MAX(a.size, b.size);

    reallocbi(res, max_size);

    for (int i = 0; i < max_size; ++i)
    {
        sum = carry;
        if (i < a.size)
            sum += a.n[i];
        if (i < b.size)
            sum += b.n[i];
        carry = sum > UINT8_MAX;
        res->n[i] = sum;
    }
    
    if (carry)
    {
        reallocbi(res, max_size + 1);
        res->n[max_size] = 1;
    }
}
