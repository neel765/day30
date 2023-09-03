#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }


    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}


int findKthLargest(int arr[], int size, int k) {

    if (k > 0 && k <= size) {
  
        quicksort(arr, 0, size - 1);

        return arr[k - 1];
    } else {
        printf("Invalid value of k\n");
        return -1;
    }
}
void main() {
    int arr[] = {12, 3, 1, 45, 7, 34, 56, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    int kthLargest = findKthLargest(arr, size, k);

    if (kthLargest != -1) {
        printf("The %dth largest element is: %d\n", k, kthLargest);
    }

getch();
}
