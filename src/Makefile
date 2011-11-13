all: 
	cc -c -g -Wall fill.c
	cc -c -g -Wall check.c
	cc -c -g -Wall input.c
	cc -c -g -Wall main.c
	cc -c -g -Wall print.c
	cc -c -g -Wall search.c
	cc -Wall fill.o input.o main.o print.o search.o check.o -o susol

clean:
	rm *.o susol
