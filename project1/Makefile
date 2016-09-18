#     *-Makefile-*    #


# Compilers
cc=gcc

# Files
src=test.c memory.c memory.h
i_files= test.i memory.i
s_files= test.s memory.s


#         Directories     
objdir=
predir=processed_files
assmdir=assembled_files

vpath %.c source
vpath %.h source
vpath %.i processed_files


#     Pre-Processing  

preprocess: $(i_files)


%.i:$(src)
	@mkdir -p -- "$(predir)"
	$(cc) -E -o ./$(predir)/$@ $<






clean:
	rm -r $(predir)
	rm -r $(assmdir)

