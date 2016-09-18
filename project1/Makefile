#     *-Makefile-*    #

# Compiler selection depending on platform
ifeq ($(platform),bbb)
cc := arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)
cc := arm-none-eabi-gcc
else
cc := gcc
endif


# Compiler options

CFLAGS = -Wall
CFLAGS += -g
CFLAGS += -O0

# Settinf standard of compiler to c99
STD= -std=c99

# Compiler flag to generate dependancy flag
#DPFLAG


#including souce.mk file 
include sources.mk

#   PHONY Protection
.PHONY= clean all preprocessor asm-file compile-all build upload build-lib

#     Pre-Processing  

preprocess: $(i_files)
%.i:%.c memory.h
	@mkdir -p -- "$(predir)"
	$(cc) $(STD) $(CFLAGS) -E -o $(predir)/$@ $<

 
asm-file: $(s_files)
%.s: %.i memory.h
	@mkdir -p -- "$(asmdir)"
	$(cc) $(STD) $(CFLAGS) -S -o $(asmdir)/$@ $(predir)/$<


compile-all: $(obj_files)
%.o: %.s memory.h
	@mkdir -p -- "$(objdir)"
	$(cc) $(STD) $(CFLAGS) -c -o $(objdir)/$@ $(asmdir)/$<

#build: compile-all
#	$(cc) $(obj_files) -o build	


clean:
	rm -rf $(predir)
	rm -rf $(asmdir)
	rm -rf $(objdir)

