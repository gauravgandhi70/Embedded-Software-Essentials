# This is README file of makefile for building Project_1 on 3 platforms for course Embedded Systems Essentials ECEN-5013#




# Platforms Supported by the Makefile and their names for invoking
1. HOST= default

2. Beaglebone Black (BBB) = bbb

3. FRclean all preprocessor asm-file compile-all build upload build-lib map_depDM_KL25z = frdm



# How to invoke particular platform
syntax: make "target" platform= "bbb or frdm or host"

eg. make all platform= bbb
This will invoke beaglebone platform. And build the target according to it. if no platform is given it will take host platform by default


#Compiler Selection:
Native compilation: platform=host will compile the target using gcc compiler natively either on BBB or host machine
Cross compilation: platform= bbb will cross compile the target using arm-linux-gnueabihf-gcc compiler for BBB
platform= frdm will cross compile the target using arm-linux-gnueabihf-gcc compiler for FRDM


#Targets Supported by makefile and their invoking syntax
#syntax : make target_name
1. clean :

It will remove all the files which are preprocessed,asembled, compiled, .map, .dep, executables

2. all :

it will build preprocess asm-file compile-all build build-lib these targets only by one command
 
3. preprocessor : dependancies  are .c files

Preprocess will give .i files from the .c files; all of them at once. Also You can preprocess single file using make file_name.i command

4. asm-file : dependancies  are .i files or .c files
asm-file will give .s files from the .i files; all of them at once. Also You can assemble single file using make file_name.s command

5. compile-all : dependancies  are .s files or .c files
compile-all will give .o files from the .s files; all of them at once. Also You can assemble single file using make file_name.o command



6. build :dependancies  are .o files or .c files
compile-all will give executable file from the .o files by linking them.


7. upload : It uploads the cross compiled executable file into root folder of beagle bone.

8. build-lib :Builds static library into the archive libproject1.a







