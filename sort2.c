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
#define RANGE 100000
#define PRINT_SET false

int main()
{
    //Make randomized set
    int set[SET_SIZE];
    srand(time(0));
    for(int i = 0; i < SET_SIZE; i++) set[i] = rand() % RANGE; 

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

    //Print Set
    if(PRINT_SET == true) for(int i = 0; i < SET_SIZE; i++) printf("\n%.2d", set[i]); 
     
    //Verify set 
    bool ordered = true;
    for(int i = 0; i < SET_SIZE - 1; i++) if(set[i] > set[i+1]) ordered = false;
    if(ordered) printf("\nSet is Ordered");
    if(!ordered) printf("\nSet is NOT Ordered");
 
    return 0;
}
