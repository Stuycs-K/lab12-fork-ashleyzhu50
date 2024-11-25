compile runthis: main.o
	@gcc -o runthis main.o
run: runthis
	@./runthis
main.o: main.c
	@gcc -c main.c
clean: 
	@rm -f *.o runthis