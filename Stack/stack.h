#ifndef _INCLUDE_STACK_
#define _INCLUDE_STACK_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_ {
    int32_t data;
    Node *link;
};

struct _list_ {
    Node *head;
    // Node *tail;
    uint32_t length;
};



List* new_list();
Node* new_node(int32_t data);
List* push(List *list, int32_t data);
List* pop(List *list);
uint32_t isEmpty(const List *list);
// void isFull(const List *list);
void display_stack(const List *list);
uint32_t Stack_len(const List *list);

#endif