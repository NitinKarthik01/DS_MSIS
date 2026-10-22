#include "stack.h"

List* new_list(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> length = 0;
    return list;
}

Node* new_node(int32_t data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> link = NULL;
    return node;
}

List* push(List *list, int32_t data){
    Node *temp = new_node(data);
    if(list -> head == NULL){
        list -> head = temp;
        temp -> link = NULL;
    }
    else{
        temp -> link = list -> head;
        list -> head = temp;
    }
    ++list -> length;
    return list;
}

List* pop(List *list){
    printf("\nDELETED ELEMENT : %d\n" ,list -> head -> data);
    list -> head = list -> head -> link;
    --list -> length;
    return list;

}

uint32_t isEmpty(const List *list){
    if(list == NULL){
        return 1;
    }
    else
        return 0;
}

void display_stack(const List *list){
    if( list == NULL){
        printf("\nSTACK IS EMPTY\n");
    }
    else{
        Node *temp = list -> head;
        while(temp -> link != NULL){
            printf("%d -> ",temp -> data);
            temp = temp -> link;
        }
        printf("%d\n" ,temp -> data);
    }
}

uint32_t Stack_len(const List *list){
    return list -> length;
}