#include<stdio.h>

int add_element_to_stack(int array[], int n, int *top)
{
    int x;
    
    if(*top>=n-1)
    {
        *top = n-1;
        printf("Stack is full\n");
        return 0;
    }
    else
    {
        printf("Enter the element\n");
        scanf("%d",&x);
        
        *top = *top + 1;
        array[*top]=x;
        return 1;
    }

}
int delete_element_from_stack(int array[],int *top)
{
    int a;
    if(*top<=0)
    {
        *top = -1;
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        a=array[*top];
        *top = *top -1;
        return a;
    }
}

int main()
{
    int n=3, choice, option;
    int array[n];
    int top = -1;
    printf("what operation you want to do on stack?\n1. Add element\n2. Delete element\n");
    scanf("%d",&choice);
    printf("\n");
    
    while(choice)
    {
        
        switch(choice)
        {
            case 1 : add_element_to_stack(array,n,&top);
                    break;
            case 2 : delete_element_from_stack(array,&top);
                    break;
            default : printf("no operation like that");
        }
        printf("1. Add\n2. Delete\n0. Exit\n");
        scanf("%d",&choice);
    }
    
    printf("Array has : ");
    for (int i=0; i<=top; i++)
    {
        printf("%d ",array[i]);
    }
}