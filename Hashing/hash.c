#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include "hash.h"
#include <string.h>


HashTable hashtable_new(uint32_t size)
{
    HashTable H;
    H.table_size = size;
    H.thelist = (List**)malloc(sizef(List*)*H.table_size);
    for(int i = 0; i<H.table_size; i++)
    {
        H.thelist[i] = NULL;
    }
    return H;
}


static uint32_t _hash_(char *key, uint32_t tablesize)
{
    uint23_t hashVal = 0;
    while(key!='\0')
    {
        hashVal = hashVal + *key;
        key ++;
    }

    return hashVal%tablesize;
}


HashTable hashtable_find(HashTable *htb, char *key)
{
    List *list = htb->thelist[_hash_(key, htb->table_size)];
    /*
    lets say _hash_(key, htb->table_size) returned value 2
    htb->thelist[2] will have an address of the list that it is pointing to the elements
    the List *list = also points to that address(to that list)
    its basically like htb->thelist[2] has address = 2000 i.e, it is pointing to address 2000
    then list also stre adress 2000 in it and points to that address only
    */

    while(list!=NULL)
    {
        if(!strcmp(list->element, key))
        {
            return true;
        }
        else{
            list = list->next;
        }
    }
    return false;
}


HashTable *hash_table_insert_element(HashTable *htb, char *data)
{
    if(!hashtable_find(htb, data))
        /*
        we are checking if the data already existing in the list or not
        if not then only we insert it
        or else we dont
        */
    {
        uint32_t bucket = htb->thelist[_hash_(key, htb->table_size)];
        List *old_address = htb->thelist[bucket];
        htb->thelist[bucket] = (List*)malloc(sizeof(List));
        strcpy(htb->thelist[bucket]->element,data);
        htb->thelist[bucket]->next = old_address;
    }
    return htb;
}


HashTable *hash_table_delete_element(HashTable *htb, char *data)
{
    uint32_t bucket = htb->thelist[_hash_(htb, data)];
    List *current, *temp;
    assert(htb->thelist[bucket]!=NULL)
    if(!strcmp(htb->thelist[bucket]->element, data))
        /*
        we are check if the first element itself containing  the element we need to delete
        */
    {
        temp = htb->thelist[bucket];
        htb->thelist[bucket] = htb->thelist[bucket]->next;
        free(temp);
    }
    else{
        current = htb->thelist[bucket]->next;
        while(current!=NULL)
        {
            if(!strcmp(current->element, data))
            {
                temp = current;
                current = current->next;
                free(temp);
                break;
            }
            else{
                current = current->next;
            }

        }
    }
    return htb;
}


void HashTable_destroy(HashTable *htb)
{
    List *current, *temp;
    for(int i = 0; i<htb->table_size; i++)
    {
        current = htb->thelist[i];
        if(current != NULL)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(htb->thelist[i]);
    }
}
