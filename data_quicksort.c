#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}
int Partition(int *arr, int front, int end){
        int pivot = arr[end];
        int i = front -1;
        for (int j = front; j < end; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        i++;
        swap(&arr[i], &arr[end]);
        return i;
}
void quicksort(int *arr, int front, int end){
        if (front < end) {
            int pivot = Partition(arr, front, end);
            quicksort(arr, front, pivot - 1);
            quicksort(arr, pivot + 1, end);
        }
}

