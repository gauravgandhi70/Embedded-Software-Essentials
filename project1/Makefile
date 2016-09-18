#     *-Makefile-*    #

# Compiler selection depending on platform
ifeq ($(platform),bbb)
cc := arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)
cc := arm-none-eabi-gcc
else
cc := gcc
endif

GNU_UTIL= size
# Compiler options

CFLAGS = -Wall
CFLAGS += -g
CFLAGS += -O0

# Settinf standard of compiler to c99
STD= -std=c99

#Beaglebone scp path
BBB_PATH= project root@192.168.7.2:/root

# Compiler flag to generate dependancy flag

#Dependancy Flag
#DEPFLAG= -M ./*.dep


#including souce.mk file 
include sources.mk

#   PHONY Protection
.PHONY= clean all preprocessor asm-file compile-all build upload build-lib gnu_ut

all: preprocess asm-file compile-all build gnu_ut
#     Pre-Processing  

preprocess: $(i_files)
%.i:%.c 
	@mkdir -p -- "$(predir)"
	$(cc) $(STD) $(CFLAGS) -E -o $(predir)/$@ $<

 
asm-file: $(s_files)
%.s: %.i
	@mkdir -p -- "$(asmdir)"
	$(cc) $(STD) $(CFLAGS) -S -o $(asmdir)/$@ $(predir)/$<


compile-all: $(o_files)
%.o: %.s $(hd)
	@mkdir -p -- "$(objdir)"
	$(cc) $(STD) $(CFLAGS) $(DEPFLAG) -c -o $(objdir)/$@ $(asmdir)/$<

gnu_ut: build
	size project
	objdump -a $(obj_path)


build: $(o_files)
	$(cc) $(obj_path) -o project	
	
upload: build
	@scp $(BBB_PATH)
	

clean:
	rm -rf $(predir)
	rm -rf $(asmdir)
	rm -rf $(objdir)
	rm  -f project

