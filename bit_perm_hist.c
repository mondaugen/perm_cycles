/* Use past permutations when permuting */

typedef struct {
    int perm_size;
    int order;
    int *cur_perm;
    int **perms;
    int _permi;
} permer_t;

void
permer_get_next_perm(permer_t *p, int *result)
{
    int m = p->order;
    int *src = p->cur_perm;
    int *dst = result;
    while (m--) {
        int n = p->perm_size;
        while (n--) {
            dst[n] = src[p->perms[(p->_permi+m)%p->order][n]];
        }
        int *tmp = src;
        src = dst;
        dst = tmp;
    }
    p->_permi = (p->_permi + p->_order - 1) % p->order;
    if (dst == p->cur_perm) {
        /* p->cur_perm wasn't the last destination, but we want to store the last permutation there */
        for (m = 0; m < p->perm_size; p++) {
            p->cur_perm[m] = result[m];
        }
    } else {
        /* We want to return p->cur_perm as it was the last destination */
        for (m = 0; m < p->perm_size; p++) {
             result[m] = p->cur_perm[m];
        }
    }
    for (m = 0; m < p->perm_size; p++) {
        p->perms[p->_permi][m] = result[m];
    }
}

int
permer_sz(int perm_size, int order)
{
    return sizeof(permer_t)
        +sizeof(int)*perm_size*(order+1)
        +sizeof(int*)*order;
}

void
permer_init(permer_t *p, int perm_size, int order)
{
    char *iptr = (char*)(p+1);
    p->perm_size = perm_size;
    p->order = order;
    p->perms = (int**)iptr;
    iptr += sizeof(int*)*order;
    p->cur_perm = iptr;
    iptr += sizeof(int)*perm_size;
    int n;
    for (n = 0; n < order; n++) {
        p->perms[n] = (int*)iptr;
        iptr += sizeof(int)*perm_size;
        int m;
        for (m = 0; m < perm_size; m++) {
            p->perms[n][m] = m; /* Identity permutation */
        }
    }
    for (n = 0; n < perm_size; n++) {
        p->cur_perm[n] = n; /* Identity permutation */
    }
    p->_permi = 0;
}

int
main (int argc, char **argv)
{
    if (argc <= 3) {
        fprintf(stderr,"args: 1st value, nbits, order, "
                "permutation...\n");
        return -1;
    }
    int val1 = atoi(argv[1]),
        nbits = atoi(argv[2]),
        order = atoi(argv[3]);
    int perm_len = argc - 4;
    char __permer[permer_sz(perm_len,order);
    permer_t permer = (permer_t*)__permer;
    permer_init(&permer,perm_len,order);
    int n;
    for (n = 0; n < perm_len; n++) {
        permer.perms[0][n] = atoi(argv[n+4]);
    }
    while (!done) {
        int res;
        int newval = 0;
        permer_get_next_perm(&permer,&res);
        for (n = 0; n < p.perm_size; n++) {
            newval |= ((val1 >> n) & 0x1) << res[n];
        }
        val1 = newval;
        float fval;
        // convert to floating point value
        // write out
    }
    return 0;
}
