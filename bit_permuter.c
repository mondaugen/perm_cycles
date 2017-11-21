#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include "bitperm_decls.h"
#include "bitperm_sdefs.h"
#include "bitperm_defs.h"

static volatile int done = 0;

uint16_t
bitperm_perm(bitperm_t *bp, uint16_t x)
{
    uint16_t result = 0;
    size_t n;
    for (n = 0; n < bp->perm_sz; n++) {
        result |= (((x >> bp->perm[n]) & 0x1) << n);
    }
    return result;
}

void setdone (int signum)
{
    done = 1;
}

int main (int argc, char **argv)
{
    if (argc <= 1) {
        fprintf(stderr,"Specify permutation ...\n");
        return -1;
    }
    if (argc != 17) {
        fprintf(stderr,"Permutation must have 17 items ...\n");
        return -2;
    }
    bitperm_meminit_t bmi = { .perm_sz = argc - 1 };
    char __perm[bitperm_sz(&bmi)];
    bitperm_t *perm = (bitperm_t*)__perm;
    bitperm_meminit(perm,&bmi);
    size_t i;
    for (i = 0; i < bmi.perm_sz; i++) {
        perm->perm[i] = atoi(argv[i+1]);
    }
    srandom(time(NULL));
    //uint16_t x = random() % (1 << bmi.perm_sz);
    uint16_t x = 0xaaaa;
    signal(SIGINT,setdone);
    while (!done) {
        fwrite(&x,sizeof(uint16_t),1,stdout);
        x = bitperm_perm(perm,x);
    }
    return 0;
}

