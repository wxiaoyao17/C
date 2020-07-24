//linklist.h
#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
} listnode, *linklist;

linklist linklist_create();
int linklist_insert(linklist L, datatype x, int pos);
int linklist_order_insert(linklist L, datatype x);
int linklist_delete(linklist L, int pos);
int linklist_delete(linklist L, datatype data);
int linklist_show(linklist L);
int linklist_reverse(linklist L);
int linklist_clear(linklist L);
int linklist_is_empty(linklist L);
bool linklist_Exist(linklist L, datatype data);

#endif