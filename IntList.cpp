#include"IntList.h"
#include<iostream>
using namespace std;

IntList::IntList(const IntList &orig):
    itemsCount(0),first(0),last(0) {}

IntList::~IntList()
{
    ListItem *current = NULL;
    ListItem *next = first;
    while(next)
    {
        current = next;
        next = next->next;
        delete current;
    }
}

void IntList::AddFirst(int item)
{
    ListItem *newItem = new ListItem(item,first);
    if (!first)
    {
        last = newItem;
    }
    first = newItem;
    itemsCount++;
}

void IntList::AddLast(int item)
{
    ListItem *newItem = new ListItem(item);
    if(!last)
    {
        first = newItem;
    }
    else
    {
        last->next = newItem;
    }
    last = newItem;
    itemsCount++;
}

void IntList::RemoveFirst()
{
    ListItem* cur = first;
    if(cur==last)
    {
        delete cur;
        first = last = NULL;
    }
    else
    {
        first = first->next;
        delete cur;
        itemsCount--;
    }
}
void IntList::RemoveLast()
{
    ListItem* cur = first;
    if(cur==last)
    {
        delete cur;
        first = last = NULL;
    }
    else
    {
        while(cur->next!=last)
        {
            cur = cur->next;
        }
        delete last;
        last = cur;
        last->next = NULL;
    }
    itemsCount--;
}
void IntList::ShowList()
{
    ListItem* current=first;
    while(current)
    {
        cout<<current->item<<" ";
        current=current->next;
    }
    cout<<endl;
}
void IntList::InsertSubList(IntList &orig, int pos)
{
    cout<<"Inserting SubList from position #"<<pos<<endl;
    if (pos<0 || pos>itemsCount)
    {
        cout<<"Incorrect position"<<endl;
        return;
    }
    if (pos==itemsCount)
    {
        last->next=orig.first;
        last=orig.last;
        return;
    }
    else if (pos==0)
    {
        orig.last->next=first;
        first=orig.first;
        return;
    }
    int i=1;
    ListItem *cur=first;
    while(i<pos)
    {
        cur=cur->next;
        i++;
    }
    ListItem *a=cur->next;
    cur->next=orig.first;
    orig.last->next=a;
    itemsCount+=orig.itemsCount;
}


