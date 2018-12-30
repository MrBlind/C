#include"stdio.h"
#include"stdlib.h"

typedef struct node{
    struct node *next;
    int data;
}*LinkList;

LinkList Create()
{
    LinkList head;
    head = (LinkList)malloc(sizeof(node));
    head->next = NULL;
    return head;
};

bool GetElem(LinkList L,int i,int *e)
{
    if(i <= 0)
        return false;
    int cou = 0;
    while(cou < i)
    {
        cou ++;
        if(L->next != NULL)
        {
            L = L->next;
        }
        else return false;
    }
    *e = L->next->data;
    return true;
}

bool Insert(LinkList *l,int i,int e)
{
    if(i < 0)
        return false;
    int cou = 0;
    LinkList p = *l;
    while(cou < i)
    {
        cou++;
        if((*l)->next != NULL)
            *l = (*l)->next;
        else return false;
    }
    LinkList s;
    s = (LinkList)malloc(sizeof(node));
    s->data = e;
    s->next = (*l)->next;
    (*l)->next = s;
    return true;
}

bool Delete(LinkList *l,int i,int e)
{
    if(i<=0)
        return false;
    LinkList p = *l;
    LinkList q;
    int cou = 1;
    while(cou < i)
    {
        cou ++;
        if(p->next != NULL)
            p = p->next;
        else return false;
    }
    e = p->data;
    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    LinkList phead = Create();
    LinkList p = phead;
    int e = 0;
    //GetElem(phead,2,&e);
    if(GetElem(p,1,&e))
        printf("%d ",e);
    else
        printf("The number doesn't exist\n");
    phead->next = (LinkList)malloc(sizeof(node));
    phead->next->data = 1;
    phead->next->next = NULL;
    if(e = Insert(&p,1,10))
        printf("%d ",phead->next->next->data);//²åÈëº¯Êı²âÊÔ
    else printf("The number dosen't exist\n");
    p = phead;
    if(Delete(&p,1,e))
        printf("%d ",e);
    else printf("The number dosen't exist\n");
    printf("%d ",phead->next->data);//É¾³ıº¯Êı²âÊÔ
    return 0;
}
