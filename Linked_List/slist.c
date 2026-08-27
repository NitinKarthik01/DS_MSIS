#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "slist.h"

static Node *_list_new_node_(uint32_t data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

List *slist_new() 
{
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

List *slist_free(List *list)
{
    Node *p;

    if (list == NULL)
        return NULL;

    while (list->head != NULL)
    {
        p = list->head;
        list->head = list->head->next;
        free(p);
    }

    list->tail = NULL;
    list->length = 0;

    free(list);

    return NULL;
}

uint32_t slist_length(List *list)
{
    if (list == NULL)
        return 0;

    return list->length;
}

/*
Node *slist_lookup(List *list, uint32_t key)
{
    if (list == NULL)
        return NULL;

    Node *node = list->head;

    for (; node != NULL; node = node->next)
    {
        if (node->data == key)
            return node;
    }

    return NULL;
}*/

Node *slist_lookup(List *list, uint32_t key)
{
    if (list == NULL)
        return NULL;

    Node *node = list->head;

    while(node!=NULL)
    {
        if(node->data == key)
        {
            return node;
        }
        node=node->next;
    }

    return NULL;
}

List *slist_add_head(List *list, uint32_t data)
{
    if (list == NULL)
        return NULL;

    Node *new_node = _list_new_node_(data);

    if (new_node == NULL)
        return list;

    if (list->head == NULL)
    {
        list->head = list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }

    ++list->length;

    return list;
}

List *slist_add_tail(List *list, uint32_t data)
{
    if (list == NULL)
        return NULL;

    Node *new_node = _list_new_node_(data);

    if (new_node == NULL)
        return list;

    if (list->head == NULL)
    {
        list->head = list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    ++list->length;

    return list;
}

/*
List *slist_delete_head(List *list)
{
    if (list == NULL)
        return NULL;

    Node *node;

    if (list->head != NULL)
    {
        node = list->head;
        list->head = list->head->next;

        if (list->head == NULL)
        {
            list->tail = NULL;
        }

        free(node);
        --list->length;
    }

    return list;
}
*/


List* slist_delete_head(List *list)
{
    if(list == NULL)
    {
        return NULL;
    }

    Node *p = list->head;

    if (p == NULL)
    {
        return list;
    }

    if(list->head == list->tail)
    {
        list->head = list->tail = NULL;
        free(p);
        list->length =0;
    }

    else
    {
        list->head = list->head->next;
        free(p);
        --list->length;
    }

    return list;
}


/*
List *slist_delete_tail(List *list)
{
    if (list == NULL || list->head == NULL)
        return list;

    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;

        return list;
    }

    Node *current = list->head;

    while (current->next != list->tail)
    {
        current = current->next;
    }

    free(list->tail);

    list->tail = current;
    list->tail->next = NULL;

    --list->length;

    return list;
}
*/
List* slist_delete_tail(List *list)
{
    if(list == NULL)
    {
        return NULL;
    }

    Node *p = list->head;

    if (p == NULL)
    {
        return list;
    }

    if(list->head == list->tail)
    {
        list->head = list->tail = NULL;
        free(p);
        list->length =0;
    }

    else
    {
        while(p->next!=list->tail)
        {
            p = p->next;
        }
        free(list->tail);
        list->tail = p;
        list->tail->next = NULL;
        --list->length;
    }

    return list;
}

List *add_in_between(List *list, uint32_t key, uint32_t data)
{
    if (list == NULL)
        return NULL;

    Node *current = slist_lookup(list, key);

    if (current == NULL)
        return list;

    Node *new_node = _list_new_node_(data);

    if (new_node == NULL)
        return list;

    new_node->next = current->next;
    current->next = new_node;

    if (current == list->tail)
        list->tail = new_node;

    ++list->length;

    return list;
}

void display_list(List *list)
{
    if (list == NULL)
    {
        printf("\nList is NULL\n");
        return;
    }

    printf("\nLINKEDLIST{\n\t");

    for (Node *node = list->head; node != NULL; node = node->next)
    {
        printf("%u -> ", node->data);
    }

    printf("NULL\n}\n");
}


List* slist_delete_on_data(List *list,uint32_t key)
{
    if(list==NULL)
    {
        return NULL;
    }
    Node *p = list->head,*q;
    if(p != NULL)
    {
        if(p->data == key)  //deleting the head if it is the head
        {
            if(p==list->tail)
            {
                list->head = list->tail = NULL;
                free(p);
                list->length =0;
                return list;
            }
            list->head = list->head->next;
            free(p);
            --list->length;
            return list;
        }
        q=p;
        p = p->next;
        while(p!=NULL)
        {
            if(p->data == key)
            {
                if(p==list->tail)
                {
                    list->tail = q;
                    free(p);
                    list->tail->next = NULL;
                    --list->length;
                    return list;
                }
                q->next = p->next;
                free(p);
                --list->length;
                return list;
            }
            q=p;
            p=p->next;
        }

    }
    return list;
}


void slist_min_max(List *list)
{
    if(list==NULL)
    {
        return;
    }
    
    if(list->head!=NULL)
    {
        Node *p = list->head;
        int max = p->data;
        int min = p->data;
        for(p=p->next;p!=NULL;p=p->next)
        {
            if(p->data > max)
            {
                max = p->data;
            }

            if(p->data < min)
            {
                min = p->data;
            }
        }
        printf("Max = %d\nMin = %d\n",max,min);
    }    
}


List* slist_rev(List *list)
{
    Node *prev = NULL;
    Node *curr = list -> head;
    Node *next;

    list->tail = list->head;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
    return list;
}


List *slist_remove_dup(List *list)
{
    if(list==NULL)
    {
        return NULL;
    }
    if(list->head == list->tail)
    {
        return list;
    }
    Node *p = list->head;
    while(p!=NULL)
    {
        Node *q = p->next;
        Node *temp = p;
        while(q!=NULL)
        {
            if(p->data == q->data)
            {
                temp->next = q->next;
                Node *next = q->next;
                if (q == list->tail)
                {
                    list->tail = temp;
                }
                free(q);
                q = next;
                --list->length;
            }
            else
            {
                temp = q;
                q = q->next;
            }
        }
        p = p->next;
    }
    return list;
}


void slist_find_nth_node(List *list, int32_t pos)
{
    if(list==NULL)
    {
        return;
    }
    if(pos <= list->length && pos>0)
    {
        Node *p = list->head;
        int count = 0;
        while(p!=NULL && count<pos-1)
        {
            p = p->next;
            count++;
        }
        if(count == pos-1)
        {
            printf("Data @ %dth position = %d\n",pos,p->data);
        }
    }
    return;
}

void slist_find_nth_node_in_reverse(List *list,int32_t pos)
{
    slist_rev(list);
    slist_find_nth_node(list,pos);
    slist_rev(list);
}


List* slist_union(List *list1, List *list2)
{
    List *result = slist_new();
    if(result == NULL)
    {
        return NULL;
    }
    Node *p;

    p = list1->head;

    while(p!=NULL)
    {
        if(slist_lookup(result, p->data) == NULL)
        {
            slist_add_tail(result, p->data);
        }
        p = p->next;
    }

    p = list2->head;

    while(p!=NULL)
    {
        if(slist_lookup(result, p->data) == NULL)
        {
            slist_add_tail(result, p->data);
        }
        p = p->next;
    }
    return result;
}



List* slist_intersection(List *list1, List *list2)
{
    if(list1 == NULL || list2 == NULL)
    {
        return NULL;
    }
    List *result = slist_new();
    if(result == NULL)
    {
        return NULL;
    }

    Node *p, *q;
    
    p = list1->head;

    while(p!=NULL)
    {
        q = list2->head;
        while(q!=NULL)
        {
            if(p->data == q->data && slist_lookup(result, p->data) == NULL)
            {
                slist_add_tail(result, p->data);
            }
            q = q->next;
        }
        p = p->next;
    }
    return result;
}




List* slist_difference(List *list1, List *list2)
{
    if(list1 == NULL)
    {
        return NULL;
    }
    List *result = slist_new();
    if(result == NULL)
    {
        return NULL;
    }
    Node *p, *q;
    
    p = list1->head;

    while(p!=NULL)
    {
        if(list2==NULL || slist_lookup(list2, p->data)==NULL)
        {
            slist_add_tail(result, p->data);
        }
        p = p->next;
    }
    return result;

}