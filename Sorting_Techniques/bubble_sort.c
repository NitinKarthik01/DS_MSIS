#include<stdio.h>

void Bubble_Sort(int A[],int n)
{
    for (int i = n-1; i>=0; i--)
    {
        for(int j = 1; j<=i; j++)
        {
            if(A[j-1]<A[j])
            {
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }

        }
    }
}

int main()
{
    int A[] = {10,2,1,5,7,9,11,10,14};
    int n = 9;

    Bubble_Sort(A,n);
    for(int i = 0;i<n ; i++)
    {
        printf("%d ",A[i]);
    }
}