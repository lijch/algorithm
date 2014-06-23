#include <stdio.h>

#include "array.h"

void insert(int *a, int start, int end) {
    int j = 0;
    int end_val = a[end];
    for(j = end - 1; j >=0; j--) {
        if(a[j] > end_val) {
            a[j+1] = a[j];
        } else {
            break;
        }
    }
    a[j+1] = end_val;
}

void recusive_insertionsort(int *a, int start, int end)
{
    if((end - start + 1) == 1) {
        return;
    }
    recusive_insertionsort(a, start, end - 1);
    insert(a, start, end);
}

int main()
{
    int length = sizeof(a)/sizeof(int);
    recusive_insertionsort(a, 0, length-1);
    print_array(a, length);
}

