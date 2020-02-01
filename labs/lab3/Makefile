#
# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.
#

# Author: Yifan Yao.740

# target all means all targets currently defined in this file
all: lab3.zip lab3

# this target is the .zip file that must be submitted to Carmen
lab3.zip: lab3main.c readtitles.c getfavorites.c savedata.c lab3Readme lab3.h Makefile
	zip lab3.zip lab3main.c readtitles.c getfavorites.c savedata.c lab3Readme lab3.h Makefile

# link .o file to executable
lab3: lab3main.o readtitles.o getfavorites.o savedata.o lab3.h
	gcc readtitles.o getfavorites.o savedata.o lab3main.o -o lab3

# compile functions w/o linking
lab3main.o: lab3main.c lab3.h
	gcc -ansi -pedantic -g -c lab3main.c
readtitles.o: readtitles.c lab3.h
	gcc -ansi -pedantic -g -c readtitles.c
getfavorites.o: getfavorites.c lab3.h
	gcc -ansi -pedantic -g -c getfavorites.c
savedata.o: savedata.c lab3.h
	gcc -ansi -pedantic -g -c savedata.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o lab3 lab3.zip
