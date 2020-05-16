# target all means all FINAL targets currently defined in this file
# all: <any files you want created. For this class, typically one executable and a .zip file>
all: lab6.zip lab6

# you must have a subsequent target for each file listed above on the right side of the colon
# that would be lab6.zip and lab6 here
lab6.zip: *.c *.s Makefile
	zip lab6.zip *.c *.s lab6Readme Makefile

lab6main.o: lab6main.c
	gcc -ansi -pedantic -c -g lab6main.c

encode.o: encode.s
	gcc -lc -m64 -c -g encode.s

lab6: lab6main.o encode.o
	gcc *.o -o lab6

clean:
	rm -rf *.o lab6
