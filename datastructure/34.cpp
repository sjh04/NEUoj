#include <iostream>

using namespace std;

struct PriorityQueue
{
    int data;
    PriorityQueue *next;
};

PriorityQueue *createNode(int e)
{
    PriorityQueue *newNode = new PriorityQueue();
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue *insert(PriorityQueue *head, int e)
{
    PriorityQueue *newNode = createNode(e);
    if (head == NULL || e > head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        PriorityQueue *current = head;
        while (current->next != NULL && e <= current->next->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

int extractMax(PriorityQueue *&head)
{
    if (head == NULL)
    {
        return -1; // or any other appropriate error code
    }
    int maxVal = head->data;
    PriorityQueue *temp = head;
    head = head->next;
    delete temp;
    return maxVal;
}

void free(PriorityQueue *head)
{
    PriorityQueue *current = head;
    while (current != NULL)
    {
        PriorityQueue *temp = current;
        current = current->next;
        delete temp;
    }
}

int main()
{
    PriorityQueue *head = NULL;
    string cmd;
    while (true)
    {
        cin >> cmd;
        if (cmd == "insert")
        {
            int e;
            cin >> e;
            head = insert(head, e);
        }
        else if (cmd == "extract")
        {
            cout << extractMax(head) << endl;
        }
        else if (cmd == "end")
        {
            break;
        }
    }
    free(head);
    return 0;
}