compile: main.o
	@gcc -o main main.o

run: main
	@./main

main.o: main.c
	@gcc -c main.c

clean:
	@rm -f *.o main
