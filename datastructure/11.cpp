#include <iostream>

using namespace std;

struct MyDoubleLinkedList
{
    int data;
    MyDoubleLinkedList *prev;
    MyDoubleLinkedList *next;
};

MyDoubleLinkedList *createDoubleLinkedList(int data)
{
    MyDoubleLinkedList *doubleLinkedList = new MyDoubleLinkedList;
    doubleLinkedList->data = data;
    doubleLinkedList->prev = NULL;
    doubleLinkedList->next = NULL;
    return doubleLinkedList;
}

MyDoubleLinkedList *insertListFront(MyDoubleLinkedList *doubleLinkedList, int data, MyDoubleLinkedList **rear)
{
    MyDoubleLinkedList *newDoubleLinkedList = createDoubleLinkedList(data);
    if (doubleLinkedList == NULL)
    {
        *rear = newDoubleLinkedList;
        return newDoubleLinkedList;
    }
    newDoubleLinkedList->next = doubleLinkedList;
    doubleLinkedList->prev = newDoubleLinkedList;
    return newDoubleLinkedList;
}

MyDoubleLinkedList *deleteList(MyDoubleLinkedList *doubleLinkedList, int data, MyDoubleLinkedList **rear)
{
    MyDoubleLinkedList *temp = doubleLinkedList;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp->prev != NULL && temp->next !=NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else if (temp->prev == NULL && temp->next != NULL)
            {
                doubleLinkedList = temp->next;
                doubleLinkedList->prev = NULL;
            }
            else if (temp->prev != NULL && temp->next == NULL)
            {
                *rear = temp->prev;
                (*rear)->next = NULL;
            }
            else
            {
                doubleLinkedList = NULL;
                *rear = NULL;
            }
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return doubleLinkedList;
}

MyDoubleLinkedList *deleteListFront(MyDoubleLinkedList *doubleLinkedList)
{
    if (doubleLinkedList == NULL)
    {
        return NULL;
    }
    MyDoubleLinkedList *temp = doubleLinkedList;
    if (temp->next == NULL)
    {
        delete temp;
        return NULL;
    }
    doubleLinkedList = doubleLinkedList->next;
    if (doubleLinkedList != NULL)
    {
        doubleLinkedList->prev = NULL;
    }
    delete temp;
    return doubleLinkedList;
}

MyDoubleLinkedList *deleteListBack(MyDoubleLinkedList *doubleLinkedList, MyDoubleLinkedList **rear)
{
    if (doubleLinkedList == NULL)
    {
        return NULL;
    }
    MyDoubleLinkedList *temp = *rear;
    if (temp->prev == NULL)
    {
        delete temp;
        return NULL;
    }
    *rear = (*rear)->prev;
    if (*rear != NULL)
    {
        (*rear)->next = NULL;
    }
    delete temp;
    return doubleLinkedList;
}

void printDoubleLinkedList(MyDoubleLinkedList *doubleLinkedList)
{
    MyDoubleLinkedList *temp = doubleLinkedList;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void freeDoubleLinkedList(MyDoubleLinkedList *doubleLinkedList)
{
    MyDoubleLinkedList *temp;
    while (doubleLinkedList != NULL)
    {
        temp = doubleLinkedList;
        doubleLinkedList = doubleLinkedList->next;
        delete temp;
    }
}

int main()
{
    MyDoubleLinkedList *dll = NULL;
    MyDoubleLinkedList *rear = NULL;
    string str;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "insert")
        {
            int data;
            cin >> data;
            dll = insertListFront(dll, data, &rear);
        }
        else if (str == "delete")
        {
            int data;
            cin >> data;
            dll = deleteList(dll, data, &rear);
        }
        else if (str == "deleteFirst")
        {
            dll = deleteListFront(dll);
        }
        else if (str == "deleteLast")
        {
            dll = deleteListBack(dll, &rear);
        }
    }
    printDoubleLinkedList(dll);
    freeDoubleLinkedList(dll);
    return 0;
}