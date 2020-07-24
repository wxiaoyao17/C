//linklist.c
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

//新建一个空链表
linklist linklist_create()
{
    linklist L;
    if ((L = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc error\n");
        return NULL;
    }
    L->next = NULL;

    return L;
}

//链表在指定位置插入
int linklist_insert(linklist L, datatype x, int pos)
{
    linklist p, q = L;

    while (pos--)
    {
        q = q->next;
        if (q == NULL)
        {
            printf("insert position invalid\n");
            return -1;
        }
    }

    p = (linklist)malloc(sizeof(listnode));
    p->data = x;
    p->next = q->next;
    q->next = p;

    return 0;
}

//链表按顺序插入
int linklist_order_insert(linklist L, datatype x)
{
    linklist p, q;
    p = L;
    while (p->next != NULL && p->next->data < x)
        p = p->next;

    q = (linklist)malloc(sizeof(listnode));
    q->data = x;
    q->next = p->next;
    p->next = q;

    return 0;
}

//链表删除指定位置的节点
int linklist_delete(linklist L, int pos)
{
    linklist p, q;
    p = L;
    while (--pos)
    {

        p = p->next;
        if (p->next == NULL)
        {

            printf("delete position is invalid.\n");
            return -1;
        }
    }
    q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    return 0;
}

//链表删除等于特定值的节点
int linklist_delete(linklist L, datatype data)
{
    linklist p, q;
    p = L;

    while (p->next != NULL)
    {
        if (p->data == data)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
            q = NULL;

            //break;
        }

        p = p->next;
    }

    return 0;
}

//打印链表
int linklist_show(linklist L)
{
    linklist p = L->next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}

//链表逆序
int linklist_reverse(linklist L)
{
    linklist p, q;
    p = L->next;
    L->next = NULL;

    while (p)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }

    return 0;
}

//删除链表
int linklist_clear(linklist L)
{
    linklist p = L;

    while (L->next)
    {
        p = L->next;
        L->next = p->next;
        free(q);
        q = NULL;
    }

    return 0;
}

//判断链表是否为空
int linklist_is_empty(linklist L)
{
    if (L->next != NULL)
        return 0;
    else
        return 1;
}

//查找链表（除头节点外）是否存在特定值得节点

bool linklist_Exist(linklist L, datatype data)
{
    linklist p, q;
    p = L->next;
    bool flag = fase;

    while (p != NULL)
    {
        if (p->data == data)
        {
            flag = true;
            break;
        }

        p = p->next;
    }

    return flag;
}