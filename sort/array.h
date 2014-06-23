int a[8] = {8, 9, 11, 89, 1278, 76, 88, 52};

static void print_array(int a[], int lengh) 
{
    int index;
    printf("###################\n");
    for(index = 0; index < lengh; index++)
    {
        printf("%d\n", a[index]);
    }
    printf("###################\n");
}
