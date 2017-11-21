#include <stddef.h>
typedef struct bitperm_t bitperm_t;

typedef struct bitperm_meminit_t bitperm_meminit_t;

size_t bitperm_sz(bitperm_meminit_t *si);
void bitperm_meminit(bitperm_t *ret, bitperm_meminit_t *si);
