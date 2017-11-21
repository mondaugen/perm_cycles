SINC=bitperm_decls.h bitperm_defs.h bitperm_sdefs.h

$(SINC) : bitperm.sabrv
	perl gen_struct_alloc.pl $< ./

bin/bit_permuter : bit_permuter.c $(SINC)
	mkdir -p bin
	cc -I. $(filter %.c,$^) -o $@

