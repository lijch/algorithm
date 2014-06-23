#include <stdio.h>

#include "array.h"

void selection_sort(int *a, int len) 
{
    int i = 0;
    int j = 0;
    int smallest_index = -1;
    int smallest;
    while(i < len - 1) {
	smallest = a[i];
        for(j = i; j < len; j++) {
            if(a[j] < smallest) {
                 smallest = a[j];
                 smallest_index = j;
            }
        }
        if(smallest_index != i) {
            a[smallest_index] = a[i];
            a[i] = smallest;
        }
	i++;
    }
}

int main()
{
    int length = sizeof(a)/sizeof(int);
    selection_sort(a, length);
    print_array(a, length);
}

/*
 Best case & Worst case : theta(n*n)
*/
