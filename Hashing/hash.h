#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdint.h>

typedef struct _list_node_ List;
typedef struct _hash_table_ HashTable;

struct _list_node_
{
    char element[30];
    List *next;
};

struct _hash_table_
{
    uint32_t table_size;
    List **thelist;
};

HashTable hashtable_new(uint32_t size);
uint32_t hashtable_find (Hashtable *htb, chr *element);
HashTable *hash_table_insert_element (HashTable *htb, char *element);
HashTable *hash_table_delete_element (HashTable *htb, char *element);
void HashTable_destroy(HashTable *htb);

#endif // HASH_H_INCLUDED
