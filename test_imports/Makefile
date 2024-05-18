all: main add
	@echo "Linking main.o and add.o"
	gcc -o main main.o add.o
	
main:
	@echo "Compiling main.c"
	gcc -c -o main.o test.c

add:
	@echo "Compiling add.c"
	gcc -c -o add.o add.c