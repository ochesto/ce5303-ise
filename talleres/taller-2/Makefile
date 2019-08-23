
static-lib:
	gcc -c biblioteca.c
	ar rv libbiblioteca.a biblioteca.o
	ranlib libbiblioteca.a
	gcc -o static-test calculadora.c libbiblioteca.a
	gcc -L . -I . -o static-test calculadora.c -lbiblioteca

dynamic-lib:
	gcc -c biblioteca.c
	ld -o libbiblioteca.so biblioteca.o -shared
	gcc -o dynamic-test calculadora.c -I . -L . -Bdynamic libbiblioteca.so
	export LD_LIBRARY_PATH=$ LD_LIBRARY_PATH:$ pwd	

clean:
	rm -fr biblioteca.o libbiblioteca.* static-test dynamic-test
