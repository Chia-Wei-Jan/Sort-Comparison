all: sort_main.c data_quicksort.o data_mergesort.o data_heapsort.o str_quicksort.o str_mergesort.o str_heapsort.o
	gcc sort_main.c data_quicksort.o data_mergesort.o data_heapsort.o str_quicksort.o str_mergesort.o str_heapsort.o -o sort_main

data_quicksort.o: data_quicksort.c data_quicksort.h
	gcc -c data_quicksort.c -o data_quicksort.o

data_mergesort.o: data_mergesort.c data_mergesort.h
	gcc -c data_mergesort.c -o data_mergesort.o

data_heapsort.o: data_heapsort.c data_heapsort.h
	gcc -c data_heapsort.c -o data_heapsort.o

str_quicksort.o: str_quicksort.c str_quicksort.h
	gcc -c str_quicksort.c -o str_quicksort.o

str_mergesort.o: str_mergesort.c str_mergesort.h
	gcc -c str_mergesort.c -o str_mergesort.o

str_heapsort.o: str_heapsort.c str_heapsort.h
	gcc -c str_heapsort.c -o str_heapsort.o

clean:
	rm -f sort_main.out data_quicksort.o data_mergesort.o data_heapsort.o str_quicksort.o str_mergesort.o str_heapsort.o

