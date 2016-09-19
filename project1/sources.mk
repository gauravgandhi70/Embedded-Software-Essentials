#Paths
vpath %.c source
vpath %.h headers
vpath %.i processed
vpath %.s assembled
vpath %.o object
obj_path= object/test.o object/memory.o
include= headers


# Files
src=memory.c project_1.c main.c 
i_files= memory.i project_1.i main.i 
s_files= memory.s project_1.s main.s
o_files= memory.o project_1.o main.o 



#         Directories     
predir=processed
asmdir=assembled
objdir=object


