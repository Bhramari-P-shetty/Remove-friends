#include<stdio.h>
#include<stdlib.h>
int i;
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void friends(int a[],int x)
{
    struct node *t,*last=NULL;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;

    for(i=1;i<x;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        t->prev=last;
        last=t;
    }

}

void deletefriend(struct node *p,int k)
{
    struct node *q=NULL;
    int i=0;
    q=p->next;
    while(p&&i<k)
    {
        if(p&&p->data<q->data)
        {

            if(p!=first)
                {
                p->prev->next=p->next;
                p->next->prev=p->prev;
                free(p);
                p=q->prev;
                i++;
                }
            else
            {
                first=first->next;
                q=q->next;
                free(p);
                p=first;
                i++;
            }

        }
        else{
            p=p->next;
            q=q->next;
        }
    }
}

void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


void main()
{
    int t;
    scanf("%d",&t);
    while(t)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        friends(a,n);
        deletefriend(first,k);
        display(first);
        printf("\n");
        t--;
    }

}