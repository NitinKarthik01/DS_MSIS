#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_ {
    uint32_t data;  
    Node *next;
};

struct _list_ {
    Node *head;
    Node *tail;
    Node *min;
    Node *max;
    uint32_t length;
};

#endif