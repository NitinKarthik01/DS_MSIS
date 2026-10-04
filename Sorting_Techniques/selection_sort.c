#include <stdio.h>

void Selection_Sort(int a[], int len)
{
    int i, j, temp;
    for (i=0; i<len; i++)
    {
        int min = i;
        for(j = i+1; j< len; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;    
    }
}

int main()
{
    int A[] = {12, 30, 50, 20, 50, 11, 23, 28};
    int len = 8;
    for(int i =0; i<len; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n\n");
    Selection_Sort(A, len);
    for(int i =0; i<len; i++)
    {
        printf("%d ",A[i]);
    }

}