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
.PHONY= clean all preprocessor 

#     Pre-Processing  

preprocess: $(i_files)


%.i:$(src)
	@mkdir -p -- "$(predir)"
	$(cc) -E -o ./$(predir)/$@ $<



clean:
	rm -r $(predir)


