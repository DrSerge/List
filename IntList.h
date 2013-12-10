#include<stdlib.h>


using namespace std;
class IntList
{
private:
    struct ListItem
    {
        int item;
        ListItem * next;

        ListItem(int i , ListItem *n = NULL)
        {
            item = i ;
            next = n ;
        }
    };

    int itemsCount;
    ListItem *first;
    ListItem *last;

public:
    IntList()
    {
        itemsCount = 0 ;
        first = last = NULL;
    }

    IntList(const IntList &orig);
    ~IntList();

    void InsertSubList(IntList &orig, int pos);
    void AddLast(const IntList & src);
    void AddFirst(int item);
    void AddLast(int item);
    void RemoveFirst();
    void RemoveLast();

    int GetItemsCounts()
    {
        return itemsCount;
    }
    void ShowList();
};
