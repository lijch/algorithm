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

int insertsort(int a[], int length)
{
    int i,j,temp;
    for(i = 1; i <length; i++)
    {
        temp = a[i];
        for(j = i-1; j >=0; j--)
        {
            if(a[j] <= temp) {
		a[j+1] = temp;
                break;
            } else {
                a[j+1] = a[j];
            }
        }
    }
}


int main() {
    int a[8] = {8, 9, 11, 89, 1278, 76, 88, 52};
    insertsort(a, 8);
    int index;
    print_array(a, 8);
}
