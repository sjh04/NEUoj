#include <iostream>

using namespace std;

struct MyStack
{
    int data;
    MyStack *next;
};

MyStack *createStack(int data)
{
    MyStack *stack = new MyStack;
    stack->data = data;
    stack->next = NULL;
    return stack;
}

void push(MyStack **stack, int data)
{
    MyStack *newStack = createStack(data);
    newStack->next = *stack;
    *stack = newStack;
}

int pop(MyStack **stack)
{
    if (*stack == NULL)
    {
        return -1;
    }
    MyStack *temp = *stack;
    *stack = (*stack)->next;
    int data = temp->data;
    delete temp;
    return data;
}

void freeStack(MyStack **stack)
{
    MyStack *temp;
    while (*stack != NULL)
    {
        temp = *stack;
        *stack = (*stack)->next;
        delete temp;
    }
}

int main()
{
    MyStack *s = NULL;
    string str;
    while (cin >> str)
    {
        if (str[0] == '+' || str[0] == '-' || str[0] == '*')
        {
            long long a = pop(&s);
            long long b = pop(&s);
            if (str[0] == '+')
            {
                push(&s, a + b);
            }
            else if (str[0] == '-')
            {
                push(&s, b - a);
            }
            else if (str[0] == '*')
            {
                push(&s, a * b);
            }
        }
        else
        {
            long long int num = 0;
            for (int i = 0; i < str.size(); i++) // 将字符串转化为数字
            {

                num = num * 10 + str[i] - '0';
            }
            push(&s, num);
        }

        if (cin.get() == '\n') // 输入中止条件
            break;
    }
    cout << pop(&s) << endl;
    freeStack(&s);
    return 0;
}