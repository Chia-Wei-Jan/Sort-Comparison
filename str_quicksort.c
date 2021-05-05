#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_swap(char **x, char **y){
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int str_Partition(char **arr, int front, int end){
	char *pivot;
        pivot = strdup(arr[end]);
	int i = front - 1;
	for(int j = front; j < end; j++){
		if(strcmp(arr[j], pivot) < 0){
			i++;
			str_swap(arr + i, arr + j);
		}
	}
	i++;
	str_swap(arr + i, arr + end);
	return i;
}

void str_quicksort(char **arr, int front, int end){
	if(front < end){
		int pivot = str_Partition(arr, front, end);
		str_quicksort(arr, front, pivot - 1);
		str_quicksort(arr, pivot + 1, end);
	}
}
