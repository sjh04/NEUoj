#include <iostream>
#include <vector>

using namespace std;

struct MyStack
{
    int pos;
    MyStack *next;
};

MyStack *createStack(int pos)
{
    MyStack *stack = new MyStack;
    stack->pos = pos;
    stack->next = NULL;
    return stack;
}

MyStack *push(MyStack *stack, int pos)
{
    MyStack *newStack = createStack(pos);
    newStack->next = stack;
    return newStack;
}

MyStack *pop(MyStack *stack, int &pos)
{
    if (stack == NULL)
    {
        return NULL;
    }
    MyStack *newStack = stack->next;
    pos = stack->pos;
    delete stack;
    return newStack;
}

bool isEmpty(MyStack *stack)
{
    return stack == NULL;
}

void freeStack(MyStack *stack)
{
    MyStack *temp;
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        delete temp;
    }
}

int main()
{
    MyStack *s = NULL;
    string input;
    getline(cin, input);
    int sum = 0;
    int count = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '\\')
        {
            s = push(s, i);
        }
        else if (input[i] == '/' && !isEmpty(s))
        {
            int pos;
            s = pop(s, pos);
            count = i - pos;
            sum += count;
            while (!v.empty() && v.back().second > pos)
            {
                count += v.back().first;
                v.pop_back();
            }
            v.push_back({count, pos});
        }
    }

    cout << sum << endl;
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }
    cout << endl;
    freeStack(s);
    return 0;
}