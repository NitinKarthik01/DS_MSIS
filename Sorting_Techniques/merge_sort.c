#include <stdio.h>


void Merge(int low, int mid, int high, int A[], int b[])
{
    int h = low;
    int i = low;
    int j = mid+1;

    while(h<=mid && j<=high)
    {
        if(A[h]<A[j])
        {
            b[i++] = A[h++];
        }
        else
        {
            b[i++] = A[j++];
        }
    }

    if(h>mid)
    {
        for(int k=j;k<=high;k++)
        {
            b[i++] = A[k];
        }
    }

    else
    {
        for(int k = h; k<=mid; k++)
        {
            b[i++] = A[k];
        }
    }

    for(int k = low; k<= high; k++)
    {
        A[k] = b[k];
    }
}



void Merge_Sort(int low, int high, int A[], int b[])
{
    if(low<high)
    {
        int mid = (low + high)/2;

        Merge_Sort(low, mid, A, b);
        Merge_Sort(mid+1, high, A, b);


        Merge(low,mid,high, A, b);     //combining all
    }   
}


int main()
{
    int A[] = {10,2,1,5,7,9,11,10,14};
    int b[9];
    int n = 9;
    int low = 0, high = 8;

    Merge_Sort(low, high,A,b);
    for(int i = 0;i<n ; i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}







