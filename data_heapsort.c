#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int *x, int *y){
        int tmp = *x;
        *x = *y;
        *y = tmp;
}

void heapify(int arr[], int N, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < N && arr[left] > arr[largest])
                largest = left;
        if(right < N && arr[right] > arr[largest])
                largest = right;
        if(largest != i){
                Swap(&arr[i], &arr[largest]);
                heapify(arr, N, largest);
        }
}

void heapsort(int arr[], int N){
        for(int i = N / 2 - 1; i >= 0; i--){
                heapify(arr, N, i);
        }

        for(int i = N - 1; i >= 0; i--){
                Swap(&arr[0], &arr[i]);
                heapify(arr, i , 0);
        }
}

