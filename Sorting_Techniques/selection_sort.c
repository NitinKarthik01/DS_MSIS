#include<stdio.h>

void Selection_Sort(int A[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min = i ;
        for(int j = i+1 ; j<n; j++)
        {
            if(A[j]<A[min])
            {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main()
{
    int A[] = {10,2,1,5,7,9,11,10,14};
    int n = 9;

    Selection_Sort(A,n);
    for(int i = 0;i<n ; i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}