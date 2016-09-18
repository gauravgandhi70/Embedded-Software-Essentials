#Paths
vpath %.c source
vpath %.h headers
vpath %.i processed
vpath %.s assembled
vpath %.o object
obj_path= object/test.o object/memory.o


# Files
src=test.c memory.c memory.h
i_files= test.i memory.i
s_files= test.s memory.s
o_files= test.o memory.o
hd= memory.h data.h


#         Directories     
predir=processed
asmdir=assembled
objdir=object


