# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab2.zip bit_encode1 bit_encode2

# this target is the .zip file that must be submitted to Carmen
lab2.zip: Makefile bit_encode.c LAB2README
	zip lab2.zip Makefile bit_encode.c LAB2README

# this target is the bit cipher executable that doesn't prompt for input
bit_encode1: bit_encode1.o
	gcc bit_encode1.o -o bit_encode1

# this target is the dependency for bit_encode1
# we use "-o bit_encode1.o" here so that the .o file doesn't have the same name as the .c file
# most of the time we can use the default .o file, but since in this instance we are creating
# two separate .o files using the same .c file, we have to specify a name for the .o file
bit_encode1.o: bit_encode.c
	gcc -ansi -pedantic -g -c -o bit_encode1.o bit_encode.c

# this target is the bit cipher executable that prompts for input from the keyboard
bit_encode2: bit_encode2.o
	gcc bit_encode2.o -o bit_encode2

# this target is the dependency for bit_encode2
# we use "-o bit_encode2.o" here so that the .o file doesn't have the same name as the .c file
# note that this compile includes "-D PROMPT" so that our code where we use ifdef's gets included
bit_encode2.o: bit_encode.c
	gcc -ansi -pedantic -D PROMPT -g -c -o bit_encode2.o bit_encode.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o bit_encode1 bit_encode2 lab2.zip
