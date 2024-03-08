#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 9

int totalSwaps = 0; // Global variable to track total swaps

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    totalSwaps++; // Increment total swaps on each swap
}


void bubbleSort(int arr[], int n, int swapCounts[]) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swapCounts[arr[j]]++; // Track swap for the current value
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


void selectionSort(int arr[], int n, int swapCounts[]) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapCounts[arr[min_idx]]++; // Track swap for the selected value
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void sortAndCountSwaps(int arr[], int n, char *sortType) {
    int swapCounts[100] = {0}; // Assuming no value exceeds 99 for simplicity
    totalSwaps = 0; // Reset total swaps before sorting

    if (strcmp(sortType, "bubble") == 0) {
        bubbleSort(arr, n, swapCounts);
    } else if (strcmp(sortType, "selection") == 0) {
        selectionSort(arr, n, swapCounts);
    } else {
        printf("Invalid sort type\n");
        return;
    }

    printf("%s Sort:\n", sortType);
    for (int i = 0; i < n; i++) {
        if (swapCounts[arr[i]] > 0) {
            printf("%d: %d times swapped\n", arr[i], swapCounts[arr[i]]);
            swapCounts[arr[i]] = 0; // Reset to avoid duplicate printing
        }
    }
    printf("Total number of swaps: %d\n", totalSwaps);
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    sortAndCountSwaps(arr1, ARRAY_SIZE, "bubble");
    printf("\n");
    sortAndCountSwaps(arr2, ARRAY_SIZE, "selection");

    return 0;
}