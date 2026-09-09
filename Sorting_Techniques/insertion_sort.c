#include <stdio.h>

void Insertion_Sort(int A[],int n)
{
    for(int j = 1; j<n; j++)
    {
        int key = A[j];
        int i = j-1;

        while(i>=0 && A[i]>key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}


int main()
{
    int A[] = {10,2,1,5,7,9,11,10,14};
    int n = 9;

    Insertion_Sort(A,n);
    for(int i = 0;i<n ; i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}