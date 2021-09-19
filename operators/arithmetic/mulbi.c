#include "../../ft_infinite.h"

void mulbi(bigint_t *res, bigint_t a, bigint_t b)
{
    int i;

    i = 0;
    while (!notbi(b))
    {
        reallocbi(res, a.size);

        if (b.n[0] & 1)
            addbi(res, *res, a);

        addbi(&a, a, a);
        bw_rsbi(&b, b, 1);
    }
}
