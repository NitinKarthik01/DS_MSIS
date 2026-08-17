#include<stdio.h>

int add_element_to_queue(int *front, int *rear, int array[],int n )
{
    int x;
    printf("Enter the element\n");
    scanf("%d",&x);
    printf("\n");

    if(*rear==n-1)
    {
        printf("Queue is full\n");
        printf("\n");
        return 0;
    }
    else
    {
        *rear=*rear+1;
        array[*rear]=x;
    }
    if(*front==-1)
    {
        *front=0;
    }
}

int delete_element_from_queue(int *front, int *rear, int array[])
{
    int a;
    if(*rear==-1 && *front==-1)
    {
        printf("Queue is Empty\n");
        printf("\n");
        return 0;
    }
    if(*rear==*front)
    {
        a = array[*front];
        *rear=-1;
        *front=-1;
        return a;
    }
    else
    {
        a = array[*front];
        *front = *front+1;
        return a;
    }
}

int main()
{
    int n = 5;
    int array[n];
    int front = -1;
    int rear = -1;
    int choice;

    printf("what operation you want to do on Queue?\n1. Add element\n2. Delete element\n");
    scanf("%d",&choice);
    printf("\n");
    while(choice)
    {
        switch(choice)
        {
            case 1 : add_element_to_queue(&front, &rear, array, n);
                    break;
            case 2 : delete_element_from_queue(&front, &rear, array);
                    break;
            default : printf("no operation like that\n");
        }
        printf("1. Add\n2. Delete\n0. Exit\n");
        printf("\n");
        scanf("%d",&choice);
        printf("\n");
    }
    
    
    if(rear!=-1 && front!=-1)
    {
        printf("Array has : ");
        for (int i=0; i<=rear; i++)
        {
            printf("%d ",array[i]);
        }
    }
    else
    {
        printf("Queue lo em ledu");
    }
    return 0;
    

}