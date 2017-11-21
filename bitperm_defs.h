size_t bitperm_sz(bitperm_meminit_t *si)
{
size_t sz = sizeof(bitperm_t);
sz += si->perm_sz * sizeof(int);
return sz;
}

void bitperm_meminit(bitperm_t *ret, bitperm_meminit_t *si)
{
char *ptr = (char*)(ret+1);
char *tmp;
size_t n;
ret->perm = (int*)ptr;
ptr += si->perm_sz * sizeof(int);
ret->perm_sz = si->perm_sz;
}

