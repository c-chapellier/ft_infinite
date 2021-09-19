#include "../ft_infinite.h"

void printbi(bigint_t a)
{
    if (!debug)
    {
        for (int i = a.size - 1; i >= 0; --i)
            i == a.size - 1 ? printf("%x", a.n[i]) : printf("%02x", a.n[i]);
        printf("\n");
    }

    if (debug)
    {
        printf("bi {\n");

        printf("    hex = ");
        for (int i = a.size - 1; i >= 0; --i)
            printf("      %02x ", a.n[i]);
        printf("\n");

        printf("    bin = ");
        for (int i = a.size - 1; i >= 0; --i)
            PRINT_UINT8(&a.n[i]), printf(" ");
        printf("\n");

        printf("    size = %d\n", a.size);
        printf("}\n");
    }
}
