/* Name: Selection Sort
 *
 * time ./a.out #12900K, DDR4 3600
 * 
 * real	0m2.569s
 * user	0m2.492s
 * sys	0m0.073s
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SET_SIZE 100000 //Using 100,000 as base for comparison

int main()
{
    //Make randomized set
    int set[SET_SIZE];
    srand(time(0));
    for(int i = 0; i < SET_SIZE; i++) set[i] = rand() % 100; 

    int end = SET_SIZE - 1;
    for (int j = 0; j < SET_SIZE; j++) {
        int index = 0;

        for(int i = 0; i <= end; i++) {
            if(set[index] < set[i]) index = i; 
        }

        int tmp = set[end];
        set[end] = set[index];
        set[index] = tmp;
        end--;
    }

    //Verify set
    for(int i = 0; i < SET_SIZE; i++) printf("\n%.2d", set[i]); 
    
    return 0;
}
