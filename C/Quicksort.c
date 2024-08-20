#include<stdio.h>

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


void quicksort(int arr[],int low,int high){
if(low < high){
int partitionindex = Partition(arr,low,high);
quicksort(arr,low,partitionindex-1);
quicksort(arr,partitionindex+1,high); 
}
}

void printarray(int arr[],int n){
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}

int main(){
    int A[] = {2,4,3,9,1,4,8,7,5,6};
    int n = 10;

 printf("Array before sorting\n");
 printarray(A,n);
 quicksort(A,0,n-1);
 printf("Array after sorting\n");
 printarray(A,n);

 return 0;
}