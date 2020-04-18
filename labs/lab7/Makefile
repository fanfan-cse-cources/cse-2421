#
# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.
#
 
all: calc_lvalues calc_intvalues lab7.zip

lab7.zip: *.c *.s Makefile lab7Readme
	zip lab7 *.c *.s Makefile lab7Readme

calc_lvalues: calc_lvalues.o multlong.o
	gcc calc_lvalues.o multlong.o -o calc_lvalues

calc_lvalues.o: calc_lvalues.c
	gcc -ansi -pedantic -c -g calc_lvalues.c

multlong.o: multlong.s
	gcc -g -lc -m64 -c multlong.s

calc_intvalues: calc_intvalues.o multint.o
	gcc calc_intvalues.o multint.o -o calc_intvalues

calc_intvalues.o: calc_intvalues.c
	gcc -ansi -pedantic -c -g calc_intvalues.c

multint.o: multint.s
	gcc -g -lc -m64 -c multint.s

clean:
	rm -rf *.o calc_lvalues calc_intvalues lab7.zip
