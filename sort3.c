/* Name: Merge Sort
 *
 * time ./a.out #12900K, DDR4 3600
 * 
 * real	0m0.114s
 * user	0m0.043s
 * sys	0m0.071s
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SET_SIZE 100000 //Using 100,000 as base for comparison
#define RANGE 100000
#define PRINT_SET false

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    //Make randomized set
    int set[SET_SIZE];
    srand(time(0));
    for(int i = 0; i < SET_SIZE; i++) set[i] = rand() % RANGE;

    mergeSort(set, 0, SET_SIZE - 1);

    //Print Set
    if(PRINT_SET == true) for(int i = 0; i < SET_SIZE; i++) printf("\n%.2d", set[i]); 
     
    //Verify set 
    bool ordered = true;
    for(int i = 0; i < SET_SIZE - 1; i++) if(set[i] > set[i+1]) ordered = false;
    if(ordered) printf("\nSet is Ordered");
    if(!ordered) printf("\nSet is NOT Ordered");

    return 0;
}
