#include "../ft_infinite.h"

void freebi(bigint_t *a)
{
    free(a->n);
}
