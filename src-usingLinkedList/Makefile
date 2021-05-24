GCC = gcc

prog:   htags4.o list.o
	$(GCC)  htags4.o list.o
htags4.o: htags4.c
	$(GCC) -c htags4.c
list.o:  list.c
	$(GCC) -c list.c
Test: prog
	./prog Test > output.txt
Test2: prog
	./prog A4.html > output2.txt
