#ifndef FT_SSL_H
#define FT_SSL_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h> 
#include <sys/stat.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <getopt.h>
#include <stdbool.h>

#define PRINT_UINT64(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2]), printf(" "), print_uint8(&((uint8_t *)n)[3]), printf(" "), print_uint8(&((uint8_t *)n)[4]), printf(" "), print_uint8(&((uint8_t *)n)[5]), printf(" "), print_uint8(&((uint8_t *)n)[6]), printf(" "), print_uint8(&((uint8_t *)n)[7])
#define PRINT_UINT56(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2]), printf(" "), print_uint8(&((uint8_t *)n)[3]), printf(" "), print_uint8(&((uint8_t *)n)[4]), printf(" "), print_uint8(&((uint8_t *)n)[5]), printf(" "), print_uint8(&((uint8_t *)n)[6])
#define PRINT_UINT48(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2]), printf(" "), print_uint8(&((uint8_t *)n)[3]), printf(" "), print_uint8(&((uint8_t *)n)[4]), printf(" "), print_uint8(&((uint8_t *)n)[5]), printf(" ")
#define PRINT_UINT40(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2]), printf(" "), print_uint8(&((uint8_t *)n)[3]), printf(" "), print_uint8(&((uint8_t *)n)[4])
#define PRINT_UINT32(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2]), printf(" "), print_uint8(&((uint8_t *)n)[3])
#define PRINT_UINT24(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1]), printf(" "), print_uint8(&((uint8_t *)n)[2])
#define PRINT_UINT16(n) print_uint8(&((uint8_t *)n)[0]), printf(" "), print_uint8(&((uint8_t *)n)[1])
#define PRINT_UINT8(n) print_uint8(&((uint8_t *)n)[0])

#define MAX(a, b) (a) > (b) ? (a) : (b)

typedef struct  bigint_s
{
    uint8_t *n;
    int     size;
}               bigint_t;

extern int debug;

void print_uint8(uint8_t *n);

void reallocbi(bigint_t *bi, int newsize);

void atobi(bigint_t *res, const char *s, int base);

void addbi(bigint_t *res, bigint_t a, bigint_t b);
void subbi(bigint_t *res, bigint_t a, bigint_t b);
void mulbi(bigint_t *res, bigint_t a, bigint_t b);
void divbi(bigint_t *res, bigint_t a, bigint_t b);

int equals_bi(bigint_t a, bigint_t b);
int not_equals_bi(bigint_t a, bigint_t b);
int smaller_bi(bigint_t a, bigint_t b);
int greater_bi(bigint_t a, bigint_t b);
int smaller_equals_bi(bigint_t a, bigint_t b);
int greater_equals_bi(bigint_t a, bigint_t b);

int notbi(bigint_t a);
int andbi(bigint_t a, bigint_t b);
int orbi(bigint_t a, bigint_t b);

// not tested
void bw_andbi(bigint_t *res, bigint_t a, bigint_t b);
void bw_orbi(bigint_t *res, bigint_t a, bigint_t b);
void bw_xorbi(bigint_t *res, bigint_t a, bigint_t b);
void bw_onebi(bigint_t *res, bigint_t a);

void printbi(bigint_t a);

#endif