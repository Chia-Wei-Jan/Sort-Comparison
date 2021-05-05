#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int left, int mid, int right){
        int n_left = mid - left + 1;
        int n_right = right - mid;

        int L[n_left];
        int R[n_right];

        for(int i = 0; i < n_left; i++){
                L[i] = arr[left + i];
        }
        for(int j = 0; j < n_right; j++){
                R[j] = arr[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while(i < n_left && j < n_right){
                if(L[i] <= R[j]){
                        arr[k] = L[i];
                        i++;
                }
                else{
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }

        while(i < n_left){
                arr[k] = L[i];
                i++;
                k++;
        }

        while(j < n_right){
                arr[k] = R[j];
                j++;
                k++;
        }
}

void mergesort(int arr[], int left, int right){
        if(left >= right){
                return;
        }
        int mid = left + (right - left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
}

