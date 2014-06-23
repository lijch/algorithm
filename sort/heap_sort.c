#include "array.h"

int maxHeapFy(int *a, int index, int heap_len) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if(a[left] > a[largest] && (left < heap_len)) {
        largest = left;
    }
    if(a[right] > a[largest] && (right < heap_len)) {
        largest = right;
    }
    int temp;
    if(largest != index) {
        temp = a[largest];
        a[largest] = a[index];
        a[index] = temp;
        maxHeapFy(a, largest, heap_len);
    }
}

int buildHeap(int *a, int array_len) {
    int end = array_len / 2;
    int index;

    for(index = end; index >= 0; index--) {
        maxHeapFy(a, index, array_len);
    }
}


int main() {
    int length = (sizeof(a)) / (sizeof(int));
    int heapsize = length;
    int index;
    int temp;

    buildHeap(a, length);

    for(index = length - 1; index >= 1; index--) {
        temp = a[index];
        a[index] = a[0];
        a[0] = temp;
  
        maxHeapFy(a, 0, --heapsize);
    } 
    print_array(a, length);
}
