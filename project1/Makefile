#     *-Makefile-*    #

# Compiler selection depending on platform
ifeq ($(platform),bbb)
cc := arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)
cc := arm-none-eabi-gcc
else
cc := gcc
endif

include sources.mk

#   PHONY Protection
.PHONY= clean all preprocessor asm-file compile-all

#     Pre-Processing  

preprocess: $(i_files)


%.i:%.c
	@mkdir -p -- "$(predir)"
	$(cc) -E -o $(predir)/$@ $<

 
asm-file: $(s_files)

%.s: %.i
	@mkdir -p -- "$(asmdir)"
	$(cc) -S -o $(asmdir)/$@ $(predir)/$<


compile-all: $(obj_files)
%.o: %.s memory.h
	@mkdir -p -- "$(objdir)"
	$(cc) -c -o $(objdir)/$@ $(asmdir)/$<

	


clean:
	rm -rf $(predir)
	rm -rf $(asmdir)
	rm -rf $(objdir)

