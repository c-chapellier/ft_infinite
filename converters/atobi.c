#include "../ft_infinite.h"

uint8_t ascii_to_hex(char c)
{
    const char values[] = "0123456789abcdef";

    for (int i = 0; i < 16; ++i)
        if (c == values[i])
            return i;

    fprintf(stderr, "char %d '%c' not in base \"%s\"\n", c, c, values);
    exit(1);
}

void atobi(bigint_t *res, const char *s, int base)
{
    assert(base == 16);

    size_t n = strlen(s);

    reallocbi(res, (n + 1) / 2);

    for (int i = 0; i + 1 < n; i += 2)
    {
        res->n[i/2] = ascii_to_hex(s[n - 1 - i - 1])*16 + ascii_to_hex(s[n - 1 - i]);
    }

    if (n & 1)
        res->n[n / 2] = ascii_to_hex(s[0]);
}
