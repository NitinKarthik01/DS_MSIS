#ifndef _INCLUDED_DLIST
#define _INCLUDED_DLIST
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _dlist_ List;

struct _node_{
    int32_t data;
    Node *next;
    Node *prev;
};

struct _dlist_{
    Node *head;
    Node *tail;
    uint32_t length;
};

List* dlist_new();
Node* node_new(uint32_t data);
List* dll_add_head(List *list, uint32_t data);
List* dll_add_bw(List *list, uint32_t data);
List* dll_add_tail(List *list, uint32_t data);
List* dll_add_on_data(List *list, uint32_t key, uint32_t data);
uint32_t dll_length(const List *list);
void dll_lookup( List *list, uint32_t key);
List* dll_del_head(List *list);
List* dll_del_bw(List *list);
List* dll_del_tail(List *list);
List* dll_del_on_data(List *list, uint32_t data);
List* dll_rev(List *list);          
List* dll_rem_dup(List *list);      
void  dll_cycle(const List *list);  
void dll_min_max( List *list);      
void dll_display(const List *list);

#endif