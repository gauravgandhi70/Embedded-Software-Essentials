#Paths
vpath %.c source
vpath %.h headers
vpath %.i processed
vpath %.s assembled
vpath %.o object
include= headers


# Files
src=memory.c project_1.c main.c 
i_files= memory.i project_1.i main.i 
s_files= memory.s project_1.s main.s
o_files= memory.o project_1.o main.o 

src=main.c memory.c data.c project_1.c
i_files= main.i memory.i data.i project_1.i
s_files= main.s memory.s data.c project_1.s
o_files= main.o memory.o data.o project_1.o




#         Directories     
predir=processed
asmdir=assembled
objdir=object


