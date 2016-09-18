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
CFLAGS += -I $(include)

# Settinf standard of compiler to c99
STD= -std=c99

#Beaglebone scp path : IP address: 192.168.7.2 , Root directory
BBB_PATH= project root@192.168.7.2:/root

# Compiler flag to generate dependancy flag


#including souce.mk file 
include sources.mk

#   PHONY Protection
.PHONY= clean all preprocessor asm-file compile-all build upload build-lib map_dep

all: preprocess asm-file compile-all build build-lib
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
	$(cc) $(STD) $(CFLAGS) $(DEPFLAG)  -c -o $(objdir)/$@ $(asmdir)/$<

	


build: $(o_files) build-lib map_dep
	$(cc) $(objdir)/*.o -o project	
	size -d project
	objdump -a $(obj_path)

	
	

map_dep:	
	$(cc) -Wl,-Map=abc.map $(objdir)/*.o --output abc.map
	$(cc) $(CFLAGS) -M ./source/*.c > project.dep

	

	
		
build-lib:  build libproject1.a

libproject1.a: data.c memory.c
	ar cr $@ source/*.c 
	
upload: clean build
	@scp $(BBB_PATH)
	

clean:
	rm -rf $(predir)
	rm -rf $(asmdir)
	rm -rf $(objdir)
	rm  -f project
	rm -f libproject1.a
	rm -f *.dep
	rm -f *.map

