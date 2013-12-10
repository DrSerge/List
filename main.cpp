#include<iostream>
#include<sstream>
#include<string>
#include"IntList.h"

using namespace std;

int main()
{
    IntList list1;
    list1.AddLast(2);
    list1.AddLast(3);
    list1.AddFirst(5);



    list1.ShowList();
    cout<<"Quantity of elements = "<<list1.GetItemsCounts()<<endl;

    IntList list2;
    list2.AddLast(9);
    list2.AddLast(7);
    list2.AddLast(11);
    list2.AddLast(45);
    list2.AddLast(34);
    list2.AddLast(55);
    list2.RemoveFirst();
    list2.RemoveFirst();
    list2.AddFirst(1);
    list2.RemoveLast();
    list2.InsertSubList(list1,2);
    list2.ShowList();

    list2.ShowList();
    cout<<"Quantity of elements = "<<list2.GetItemsCounts()<<endl;
    return 0;
}
