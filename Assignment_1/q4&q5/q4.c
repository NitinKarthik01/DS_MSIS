/* 4. Design data structure for single linked list. 
    Write function to insert element in O(1) time and 
    find the maximum and minimum element in O(1) time */

    
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sll.h"

List* q4_new() {
    List *list = malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->min = NULL;
    list->max = NULL;
    list->length = 0;

    return list;
}

List* q4_insert(List *list, uint32_t data) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return list;

    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->min = node;
        list->max = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;

        if (data < list->min->data)
            list->min = node;

        if (data > list->max->data)
            list->max = node;
    }

    list->length++;
    return list;
}

void q4_min_max(List *list) {
    if (list->head == NULL) {
        printf("EMPTY LIST\n");
        return;
    }

    printf("Minimum: %u\n", list->min->data);
    printf("Maximum: %u\n", list->max->data);
}

void q4_display(List *list) {
    Node *temp = list->head;

    while (temp != NULL) {
        printf("%u -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    List *list = q4_new();

    if (list == NULL)
        return 1;

    q4_insert(list, 40);
    q4_insert(list, 10);
    q4_insert(list, 70);
    q4_insert(list, 20);
    q4_insert(list, 5);

    printf("Linked List: ");
    q4_display(list);

    q4_min_max(list);

    Node *temp = list->head;

    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(list);
    return 0;
}
