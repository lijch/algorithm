#include <stdio.h>


void print_array(int a[], int lengh) 
{
    int index;
    printf("###################\n");
    for(index = 0; index < lengh; index++)
    {
        printf("%d\n", a[index]);
    }
    printf("###################\n");
}

void do_union(int *a, int start, int mid, int end)
{
    int i,j;
    int length1 = (mid - start);
    int length2 = (end - mid + 1);
    int temp;
    int total_len = end - start + 1;
    int b[total_len];
    
    i = 0; 
    j = 0;
    int index = 0;

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
}

void merge_sort(int *a, int start, int end)
{
    int length = end - start + 1;
    if(length <= 1) {
        return;
    }

    int mid_len = length / 2;
    merge_sort(a, start, start + mid_len - 1);
    merge_sort(a, start + mid_len, end);
    do_union(a, start, start + mid_len, end);   
}

int main()
{
    int a[8] = {8, 9, 11, 89, 1278, 76, 88, 52};
    merge_sort(a, 0, 7);
    int index;
    print_array(a, 8);
}
