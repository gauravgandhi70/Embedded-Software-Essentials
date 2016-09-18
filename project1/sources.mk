# Files
src=test.c memory.c memory.h
i_files= test.i memory.i
s_files= test.s memory.s


#         Directories     
objdir=
predir=processed_files
asmdir=assembled_files
objdir=object_files

vpath %.c source
vpath %.h headers
vpath %.i processed_files
vpath %.s assembled_files
vpath %.o object_files
