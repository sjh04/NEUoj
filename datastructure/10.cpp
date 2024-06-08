#include <iostream>

using namespace std;

struct MyQueue
{
    string name;
    int time;
    MyQueue *next;
};

MyQueue *createQueue(string name, int time)
{
    MyQueue *queue = new MyQueue;
    queue->name = name;
    queue->time = time;
    queue->next = NULL;
    return queue;
}

bool isEmpty(MyQueue *queue)
{
    return queue == NULL;
}

MyQueue *insertQueue(MyQueue *queue, string name, int time, MyQueue **rear)
{
    MyQueue *newQueue = createQueue(name, time);
    if (isEmpty(queue))
    {
        *rear = newQueue;
        return newQueue;
    }
    (*rear)->next = newQueue;
    *rear = newQueue;
    return queue;
}

MyQueue *deleteQueue(MyQueue *queue)
{
    if (isEmpty(queue))
    {
        return NULL;
    }
    MyQueue *temp = queue;
    queue = queue->next;
    delete temp;
    return queue;
}

void freeQueue(MyQueue *queue)
{
    MyQueue *temp;
    while (queue != NULL)
    {
        temp = queue;
        queue = queue->next;
        delete temp;
    }
}

int main()
{
    MyQueue *q = NULL;
    MyQueue *rear = NULL;
    int n, time;
    cin >> n >> time;
    string name;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> t;
        q = insertQueue(q, name, t, &rear);
    }
    int sum = 0;
    while (!isEmpty(q))
    {
        if (q->time <= time)
        {
            sum += q->time;
            cout << q->name << " " << sum << endl;
            q = deleteQueue(q);
        }
        else
        {
            q->time -= time;
            q = insertQueue(q, q->name, q->time, &rear);
            q = deleteQueue(q);
            sum += time;
        }
    }
    freeQueue(q);
    return 0;
}