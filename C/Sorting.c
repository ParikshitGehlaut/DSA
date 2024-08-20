#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Bubblesort(int a[], int s)
{
    int size = s;
    for (int j = 0; j < size-1; j++)
    {
        for (int i = 0; i < size-1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i],&a[i + 1]);
            }
        }
    }
    for(int k=0;k<size;k++){
        printf("%d ",a[k]);
    }
}

int main()
{
    int a[] = {8, 0, 3, 7, 1};
    Bubblesort(a, 5);

    return 0;
}