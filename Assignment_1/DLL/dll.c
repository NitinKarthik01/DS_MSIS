
#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

List* dlist_new() {
    List *list = malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

Node* node_new(uint32_t data) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

List* dll_add_head(List *list, uint32_t data) {
    Node *node = node_new(data);

    if (node == NULL)
        return list;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->length++;
    return list;
}

List* dll_add_tail(List *list, uint32_t data) {
    Node *node = node_new(data);

    if (node == NULL)
        return list;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;
    return list;
}

List* dll_add_bw(List *list, uint32_t data) {
    int n;

    printf("\nEnter position to insert: ");
    if (scanf("%d", &n) != 1)
        return list;

    if (n <= 1 || n > (int)list->length) {
        printf("\nInvalid middle position\n");
        return list;
    }

    Node *temp = list->head;

    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }

    Node *node = node_new(data);

    if (node == NULL)
        return list;

    node->next = temp->next;
    node->prev = temp;

    temp->next->prev = node;
    temp->next = node;

    list->length++;

    return list;
}

List* dll_add_on_data(List *list, uint32_t key, uint32_t data) {
    Node *temp = list->head;

    while (temp != NULL) {
        if (temp->data == key) {
            Node *node = node_new(data);

            if (node == NULL)
                return list;

            node->next = temp->next;
            node->prev = temp;
            temp->next = node;

            if (node->next != NULL) {
                node->next->prev = node;
            }
            else {
                list->tail = node;
            }

            list->length++;
            return list;
        }

        temp = temp->next;
    }

    printf("\nELEMENT NOT FOUND\n");
    return list;
}

List* dll_del_bw(List *list) {
    int n;

    printf("\nEnter position to delete: ");
    if (scanf("%d", &n) != 1)
        return list;

    if (n <= 1 || n >= (int)list->length) {
        printf("\nInvalid middle position\n");
        return list;
    }

    Node *temp = list->head;

    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    list->length--;

    return list;
}

List* dll_del_on_data(List *list, uint32_t data) {
    Node *temp = list->head;

    while (temp != NULL) {
        if (temp->data == data) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                list->head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                list->tail = temp->prev;

            free(temp);
            list->length--;

            return list;
        }

        temp = temp->next;
    }

    printf("\nDATA NOT FOUND\n");
    return list;
}

List* dll_del_head(List *list) {
    if (list->head == NULL) {
        printf("\nEMPTY LIST\n");
        return list;
    }

    Node *temp = list->head;

    list->head = temp->next;

    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(temp);
    list->length--;

    return list;
}

List* dll_del_tail(List *list) {
    if (list->tail == NULL) {
        printf("\nEMPTY LIST\n");
        return list;
    }

    Node *temp = list->tail;

    list->tail = temp->prev;

    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(temp);
    list->length--;

    return list;
}

void dll_lookup(List *list, uint32_t key) {
    Node *temp = list->head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nKEY FOUND\n");
            return;
        }

        temp = temp->next;
    }

    printf("\nKEY NOT FOUND\n");
}

void dll_min_max(List *list) {
    if (list->head == NULL) {
        printf("\nEMPTY LIST\n");
        return;
    }

    uint32_t min = list->head->data;
    uint32_t max = list->head->data;

    Node *temp = list->head;

    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;

        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }

    printf("\nMINIMUM: %u\n", min);
    printf("MAXIMUM: %u\n", max);
}

List* dll_rev(List *list) {
    Node *temp = list->head;
    Node *curr = NULL;

    while (temp != NULL) {
        curr = temp->prev;
        temp->prev = temp->next;
        temp->next = curr;

        temp = temp->prev;
    }

    curr = list->head;
    list->head = list->tail;
    list->tail = curr;

    return list;
}

List* dll_rem_dup(List *list) {
    Node *cur = list->head;

    while (cur != NULL) {
        Node *ptr = cur->next;

        while (ptr != NULL) {
            if (cur->data == ptr->data) {
                Node *del = ptr;
                ptr = ptr->next;

                del->prev->next = del->next;

                if (del->next != NULL)
                    del->next->prev = del->prev;
                else
                    list->tail = del->prev;

                free(del);
                list->length--;
            }
            else {
                ptr = ptr->next;
            }
        }

        cur = cur->next;
    }

    return list;
}

void dll_cycle(const List *list) {
    Node *slow = list->head;
    Node *fast = list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("\nCYCLE FOUND\n");
            return;
        }
    }

    printf("\nNO CYCLE FOUND\n");
}

uint32_t dll_length(const List *list) {
    return list->length;
}

void dll_display(const List *list) {
    if (list->head == NULL) {
        printf("\nEMPTY LIST\n");
        return;
    }

    Node *temp = list->head;

    printf("\nNULL <-> ");

    while (temp != NULL) {
        printf("%u", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" <-> NULL\n");
}
