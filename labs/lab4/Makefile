#
# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.
#

# Author: Yifan Yao.740

# define variables
lab:=lab4
executable:=$(lab)
zipFile:=$(lab).zip
header:=$(lab).h
# --------------------------------------------------------
# 	MODIFY ME
# 	Project Specific Objects
objects:=$(lab)main.o readInput.o insertNode.o deleteNode.o \
		menuSelection.o checkDuplicateStock.o totalRevenue_1.o \
		totalWholesaleCost_2.o totalWholesaleInvestment_3.o \
		totalProfit_4.o totalGroceryItemsSold_5.o averageProfit_6.o \
		printInStockItems_7.o printOutStockItems_8.o \
		printByDepartment_9.o addGroceryItem_10.o \
		deleteGroceryItem_11.o fileOutput_12.o
# --------------------------------------------------------

# target all means all targets currently defined in this file
all: $(zipFile) $(executable)

# this target is the .zip file that must be submitted to Carmen
$(zipFile): *.c $(header) $(lab)Readme Makefile
	zip $(zipFile) *.c $(header) $(lab)Readme Makefile

# link .o file to executable
$(executable): $(objects) $(header)
	gcc $(objects) -o $(executable)

# compile functions w/o linking
$(lab)main.o: $(lab)main.c $(header)
	gcc -ansi -pedantic -g -c $(lab)main.c

# --------------------------------------------------------
# 	MODIFY ME
# 	Project Specific Objects
insertNode.o: insertNode.c $(header)
	gcc -ansi -pedantic -g -c insertNode.c
deleteNode.o: deleteNode.c $(header)
	gcc -ansi -pedantic -g -c deleteNode.c
readInput.o: readInput.c $(header)
	gcc -ansi -pedantic -g -c readInput.c
menuSelection.o: menuSelection.c $(header)
	gcc -ansi -pedantic -g -c menuSelection.c
checkDuplicateStock.o: checkDuplicateStock.c $(header)
	gcc -ansi -pedantic -g -c checkDuplicateStock.c
totalRevenue_1.o: totalRevenue_1.c $(header)
	gcc -ansi -pedantic -g -c totalRevenue_1.c
totalWholesaleCost_2.o: totalWholesaleCost_2.c $(header)
	gcc -ansi -pedantic -g -c totalWholesaleCost_2.c
totalWholesaleInvestment_3.o: totalWholesaleInvestment_3.c $(header)
	gcc -ansi -pedantic -g -c totalWholesaleInvestment_3.c
totalProfit_4.o: totalProfit_4.c $(header)
	gcc -ansi -pedantic -g -c totalProfit_4.c
totalGroceryItemsSold_5.o: totalGroceryItemsSold_5.c $(header)
	gcc -ansi -pedantic -g -c totalGroceryItemsSold_5.c
averageProfit_6.o: averageProfit_6.c $(header)
	gcc -ansi -pedantic -g -c averageProfit_6.c
printInStockItems_7.o: printInStockItems_7.c $(header)
	gcc -ansi -pedantic -g -c printInStockItems_7.c
printOutStockItems_8.o: printOutStockItems_8.c $(header)
	gcc -ansi -pedantic -g -c printOutStockItems_8.c
printByDepartment_9.o: printByDepartment_9.c $(header)
	gcc -ansi -pedantic -g -c printByDepartment_9.c
addGroceryItem_10.o: addGroceryItem_10.c $(header)
	gcc -ansi -pedantic -g -c addGroceryItem_10.c
deleteGroceryItem_11.o: deleteGroceryItem_11.c $(header)
	gcc -ansi -pedantic -g -c deleteGroceryItem_11.c
fileOutput_12.o: fileOutput_12.c $(header)
	gcc -ansi -pedantic -g -c fileOutput_12.c
# --------------------------------------------------------

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o $(lab) $(zipFile)
