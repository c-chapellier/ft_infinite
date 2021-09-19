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

        if (argv[2][0] == '+')
            addbi(&res, a, b);
        else if (argv[2][0] == '-')
            subbi(&res, a, b);
        else if (argv[2][0] == '*')
            mulbi(&res, a, b);
        else if (argv[2][0] == '/')
            divbi(&res, a, b);
        else if (argv[2][0] == '=')
            printf("%d\n", equals_bi(a, b)), exit(0);
        else if (argv[2][0] == '!' && argv[2][1] == '=')
            printf("%d\n", not_equals_bi(a, b)), exit(0);
        else if (argv[2][0] == '>' && argv[2][1] == '=')
            printf("%d\n", greater_equals_bi(a, b)), exit(0);
        else if (argv[2][0] == '<' && argv[2][1] == '=')
            printf("%d\n", smaller_equals_bi(a, b)), exit(0);
        else if (argv[2][0] == '<' && argv[2][1] == '<')
            bw_lsbi(&res, a, 1);
        else if (argv[2][0] == '>' && argv[2][1] == '>')
            bw_rsbi(&res, a, 1);
        else if (argv[2][0] == '>')
            printf("%d\n", greater_bi(a, b)), exit(0);
        else if (argv[2][0] == '<')
            printf("%d\n", smaller_bi(a, b)), exit(0);
        else if (argv[2][0] == '!')
            printf("%d\n", notbi(a)), exit(0);
        else if (argv[2][0] == '&' && argv[2][1] == '&')
            printf("%d\n", andbi(a, b)), exit(0);
        else if (argv[2][0] == '|' && argv[2][1] == '|')
            printf("%d\n", orbi(a, b)), exit(0);
        else if (argv[2][0] == '&')
            bw_andbi(&res, a, b);
        else if (argv[2][0] == '|')
            bw_orbi(&res, a, b);
        else if (argv[2][0] == '^')
            bw_xorbi(&res, a, b);
        else if (argv[2][0] == '~')
            bw_onebi(&res, a);
        else
            fprintf(stderr, "operation '%c' is not implemented\n", argv[2][0]), exit(1);

        printbi(res);
        return 0;
    }

    fprintf(stderr, "bad number of args\n");
    return 1;
}
