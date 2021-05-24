GCC = gcc

prog: readfile.o searchTags.o printTags.o main.o
	$(GCC) readfile.o searchTags.o printTags.o main.o -o prog

readfile.o: readfile.c
	$(GCC) -c readfile.c

searchTags.o: searchTags.c
	$(GCC)  -c searchTags.c

printTags.o : printTags.c
	$(GCC)  -c printTags.c

main.o: main.c
		$(GCC) -c main.c

test: prog
	./prog A2.html > output.txt

test1: prog 
	./prog output.txt > output2.txt

compare: prog
	diff output.txt output2.txt
