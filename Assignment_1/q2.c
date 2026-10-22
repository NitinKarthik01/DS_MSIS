/* 2. Given a stack[ ] = { 20,45,65,75,33,50} with top pointing to 50. 
        Write a function to display the key 65. */


#include "../Stack/stack.h"

void display_key(List *list, int32_t key) {
    Node *temp = list->head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("KEY FOUND: %d\n", temp->data);
            return;
        }
        temp = temp->link;
    }

    printf("KEY NOT FOUND\n");
}

int main() {
    List *stack = new_list();

    push(stack, 20);
    push(stack, 45);
    push(stack, 65);
    push(stack, 75);
    push(stack, 33);
    push(stack, 50);

    display_key(stack, 65);

    return 0;
}
