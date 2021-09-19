#include "../ft_infinite.h"

// & | ^ ~ << >>

void bw_andbi(bigint_t *res, bigint_t a, bigint_t b)
{
    int max_size = MAX(a.size, b.size);
    uint8_t t;

    reallocbi(res, max_size);

    for (int i = 0; i < max_size; ++i)
    {
        if (i < a.size && i < b.size)
            res->n[i] = a.n[i] & b.n[i];
        else
            res->n[i] = 0;
    }
}

void bw_orbi(bigint_t *res, bigint_t a, bigint_t b)
{
    int max_size = MAX(a.size, b.size);
    uint8_t t;

    reallocbi(res, max_size);

    for (int i = 0; i < max_size; ++i)
    {
        if (i < a.size && i < b.size)
            res->n[i] = a.n[i] | b.n[i];
        else if (i < a.size)
            res->n[i] = b.n[i];
        else if (i < b.size)
            res->n[i] = a.n[i];
        else
            res->n[i] = 0;
    }
}

void bw_xorbi(bigint_t *res, bigint_t a, bigint_t b)
{
    int max_size = MAX(a.size, b.size);
    uint8_t t;

    reallocbi(res, max_size);

    for (int i = 0; i < max_size; ++i)
    {
        if (i < a.size && i < b.size)
            res->n[i] = a.n[i] ^ b.n[i];
        else if (i < a.size)
            res->n[i] = b.n[i];
        else if (i < b.size)
            res->n[i] = a.n[i];
        else
            res->n[i] = 0;
    }
}

// one's complement (flipping bits)
void bw_onebi(bigint_t *res, bigint_t a)
{
    uint8_t t;

    reallocbi(res, a.size);

    for (int i = 0; i < a.size; ++i)
        res->n[i] = ~a.n[i];
}

void bw_lsbi(bigint_t *res, bigint_t a, int n)
{
    assert(n > 0);

    deepbi(res, a);
    for (int i = 0; i < n; ++i)
        addbi(res, *res, *res);
}

void bw_rsbi(bigint_t *res, bigint_t a, int n)
{
    bigint_t t = {0};
    int carry = 0;

    deepbi(&t, a);
    reallocbi(res, t.size);

    for (int i = 0; i < n; ++i)
    {
        for (int j = t.size - 1; j >= 0; --j)
        {
            res->n[j] = (carry << 7) | t.n[j] >> 1;
            carry = 0;
            if (t.n[j] & 1)
                carry = 1;
        }
    }

    cleanbi(res);
}
