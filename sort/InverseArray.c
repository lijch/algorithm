#include <stdio.h>
#include "array.h"

int inverse_between_array(int *a, int start, int mid, int end)
{
    int length1 = mid - start;
    int length2 = end - mid + 1;
    
    
    int i = 0;
    int j = 0;
    int inverse_number = 0;
    int count_inverse_i = length1;

    while(i < length1 && j < length2) {
        if(a[start + i] > a[mid + j]) {
            inverse_number += (mid - start);
            j++;
        } else {
	    i++;
        }
    }

//Merge sort
    i = 0;
    j = 0;
    int index = 0;
    int total_len = end - start + 1;
    int b[total_len];
    while(i < length1 && j < length2) {
       if(a[start + i] < a[mid + j]) {
            b[index] = a[start + i];
            i++;
       } else {
            b[index] = a[mid + j];
            j++;
       }
       index++;	
    }

    if(i < length1) {
        for( ; i< length1;i++) {
            b[index++] = a[start + i];
        }
    }
    if(j < length2) {
        for(; j < length2; j++) {
            b[index++] = a[mid + j];
        }
    }
    
    
    for(index = 0; index < total_len; index++) {
         a[start + index] = b[index];
    }
    
    return inverse_number;
}


int inverse_array(int *a, int start, int end)
{
    if((end - start) == 0) {
        return 0;
    }
    int length = end - start + 1;
    int mid = start + (length / 2);
    
    int inverse_part1 = inverse_array(a, start, mid - 1);
    int inverse_part2 = inverse_array(a, mid, end); 
    int inverseBetweenArray = inverse_between_array(a, start, mid, end);

    return inverse_part1 + inverse_part2 + inverseBetweenArray;
}


int main()
{
    int b[] = {2, 3, 8, 6, 1};
    printf("The inverse of b is:%d\n", inverse_array(b, 0, 4));
    print_array(b, 5);
}
