#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_Swap(char **x, char **y){
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

void str_heapify(char **arr, int N, int i){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < N && strcmp(arr[left], arr[largest]) > 0)
		largest = left;
	if(right < N && strcmp(arr[right], arr[largest]) > 0)
		largest = right;
	if(largest != i){
		str_Swap(arr + i, arr + largest);
		str_heapify(arr, N, largest);
	}
}

void str_heapsort(char **arr, int N){
	for(int i = N/2 - 1; i >= 0; i--){
		str_heapify(arr, N, i);
	}

	for(int i = N - 1; i >= 0; i--){
		str_Swap(arr + 0, arr + i);
		str_heapify(arr, i, 0);
	}
}


