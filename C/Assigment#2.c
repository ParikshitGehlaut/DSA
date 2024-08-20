#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Partition(int A[],int low,int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void Sort(int A[], int low, int high)
{
    int Partitionindex; // Index of pivot

    if (low < high)
    {
        Partitionindex = Partition(A, low, high); 
        Sort(A, low, Partitionindex - 1);     
        Sort(A, Partitionindex + 1, high);
    }
}


int main(int argc, char* argv[]) {
  
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error no input file\n");
        exit(1);
    }

    FILE* OUT = fopen("output.txt", "w");
    if (OUT == NULL) {
        printf("Error no output file!\n");
        exit(1);
    }

    int array[2500];
    int i = 0;
    int number;
    while (fscanf(fp, "%d", &number) != EOF) {
        array[i] = number;
        i++;
    }
    int n = i;
    Sort(array, 0, n - 1);

    for (int k = 0; k < n; k++) {
        fprintf(OUT, "%d\n", array[k]);
    }

    fclose(fp);
    fclose(OUT);

    return 0;
}