#include "ft_infinite.h"

int debug = 0;

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        bigint_t res = {0};
        bigint_t a = {0}, b = {0};

        atobi(&a, argv[1], 16);
        if (debug) printbi(a);

        atobi(&b, argv[3], 16);
        if (debug) printbi(b);

        switch (argv[2][0])
        {
        case '+':
            addbi(&res, a, b);
            break;
        // case '-':
        //     subbi(&res, a, b);
            // break;
        // case '*':
        //     mulbi(&res, a, b);
        //     break;
        // case '/':
        //     divbi(&res, a, b);
            // break;
        case '=':
            printf("%d\n", equals_bi(a, b));
            exit(0);
        case '!':
            printf("%d\n", not_equals_bi(a, b));
            exit(0);
        case '>':
            printf("%d\n", greater_bi(a, b));
            exit(0);
        case '<':
            printf("%d\n", smaller_bi(a, b));
            exit(0);
        case 'g':
            printf("%d\n", greater_equals_bi(a, b));
            exit(0);
        case 's':
            printf("%d\n", smaller_equals_bi(a, b));
            exit(0);
        case 'n':
            printf("%d\n", notbi(a));
            exit(0);
        case '&':
            printf("%d\n", andbi(a, b));
            exit(0);
        case '|':
            printf("%d\n", orbi(a, b));
            exit(0);

        default:
            fprintf(stderr, "operation '%c' is not implemented\n", argv[2][0]);
            exit(1);
        }

        printbi(res);
        return 0;
    }

    fprintf(stderr, "bad number of args\n");
    return 1;
}
