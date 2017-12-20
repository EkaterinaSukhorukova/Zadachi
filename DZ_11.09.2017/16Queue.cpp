#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "locale.h"
 
struct QUEUE
{
    int info;
    QUEUE *next;
}
 
int EmptyQ(QUEUE **first)
{
    if ((*first)==NULL)
    return 1;
    else
    return 0;
}
 
void AddQ(QUEUE **last)
{
    QUEUE *tmp = new QUEUE;
    tmp->info=rand()%100;
    tmp->next=NULL;
    (*last)->next=tmp;
    *last=tmp;
}
 
void DelQ(QUEUE *first, QUEUE **last)
{
    QUEUE *tmp=first->next;
    if(first->next==NULL)
    *last=first;
    delete tmp;
}
 
void ShowQ(QUEUE *first)
{
    QUEUE *tmp=first->next;
    while(tmp!=NULL)
    {
        printf("%d ", tmp->info);
        tmp=tmp->next;
    }
}
 
void ClearQ(QUEUE **first, QUEUE **last)
{
    QUEUE *tmp;
    while(first->next!=NULL)
    {
        tmp=first->next;
        first->next = first->tmp;
        delete tmp;
    }
    *last=first;
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    QUEUE *first, *last;
    int n;
    char d;
            AddQ(&last);
            break;
 
            if (EmptyQ(first)==1)
            printf("\nОчередь пустая \n");
            else
            {
                DelQ(first,&last);
                printf("\nЭлемент удален из очереди \n");
            }
            break;
 
            if (EmptyQ(first)==1)
            printf("\nОчередь пустая \n");
            else
            {
                printf("\nЭлементы очереди: ");
                ShowQ(first);
                printf("\n");
            }
            break;
 
            ClearQ(first,&last);
            break;
            default: printf("\nОшибка!\n"); break;
    _getch();
}
