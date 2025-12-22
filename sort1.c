/* Name: Multi Pass Flag Sort
 *
 * time ./a.out #12900K, DDR4 3600
 *
 * real	0m14.818s
 * user	0m14.712s
 * sys	0m0.076s
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

    //Sort set
    bool unsorted;
    do {
        unsorted = false;
        for(int i = 0; i < SET_SIZE - 1; i++) {

            if(set[i] > set[i+1]) {
                unsorted = true;
                int temp = set[i+1];
                set[i+1] = set[i];
                set[i] = temp;
            }
        }
    }
    while (unsorted);

    //Verify set
    for(int i = 0; i < SET_SIZE; i++) printf("\n%.2d", set[i]); 
    
    return 0;
}
