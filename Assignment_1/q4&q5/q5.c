/*5. Write a function to delete all duplicate elements from SLL.*/


#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

List* remove_duplicates(List *list) {
    Node *cur = list->head;

    while (cur != NULL) {
        Node *temp = cur;
        Node *ptr = cur->next;

        while (ptr != NULL) {
            if (cur->data == ptr->data) {
                temp->next = ptr->next;

                if (ptr == list->tail)
                    list->tail = temp;

                free(ptr);
                list->length--;

                ptr = temp->next;
            }
            else {
                temp = ptr;
                ptr = ptr->next;
            }
        }

        cur = cur->next;
    }

    return list;
}

void display(List *list) {
    Node *temp = list->head;

    while (temp != NULL) {
        printf("%u -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    List *list = malloc(sizeof(List));

    if (list == NULL)
        return 1;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    uint32_t arr[] = {10, 20, 30, 20, 40, 10, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        Node *node = malloc(sizeof(Node));

        if (node == NULL)
            return 1;

        node->data = arr[i];
        node->next = NULL;

        if (list->head == NULL) {
            list->head = node;
            list->tail = node;
        }
        else {
            list->tail->next = node;
            list->tail = node;
        }

        list->length++;
    }

    printf("Original List: ");
    display(list);

    remove_duplicates(list);

    printf("After Removing Duplicates: ");
    display(list);

    Node *temp = list->head;

    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(list);

    return 0;
}
