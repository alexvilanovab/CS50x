/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int f = 0;
    int l = n - 1;
    int m;
    
    while(f <= l){
        m = (f + l) / 2;
        
        if(values[m] == value){
            return true;
        }
        else if(values[m] > value){
            l = m - 1;
        }else{
            f = m + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int pos, temp;
    
    for(int i = 0; i < n - 1; i++){
        pos = i;
        
        for(int y = i + 1; y < n; y++){
            if(values[y] < values[pos]){
                pos = y;
            }
        }
        
        if(pos != i){
            temp = values[i];
            values[i] = values[pos];
            values[pos] = temp;
        }
    }
}
