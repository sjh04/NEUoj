#include <iostream>

using namespace std;

struct TreapNode
{
    int data;
    int priority;
    TreapNode *left;
    TreapNode *right;
};

TreapNode *createNode(int e, int pri)
{
    TreapNode *newNode = new TreapNode();
    newNode->data = e;
    newNode->priority = pri;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreapNode *rightRotate(TreapNode *t)
{
    TreapNode *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

TreapNode *leftRotate(TreapNode *t)
{
    TreapNode *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

TreapNode *insert(TreapNode *root, int e, int pri)
{
    if (root == NULL)
    {
        root = createNode(e, pri);
        return root;
    }
    if (e == root->data)
    {
        return root;
    }
    if (e < root->data)
    {
        root->left = insert(root->left, e, pri);
        if (root->left->priority > root->priority)
        {
            root = rightRotate(root);
        }
    }
    else
    {
        root->right = insert(root->right, e, pri);
        if (root->right->priority > root->priority)
        {
            root = leftRotate(root);
        }
    }
    return root;
}

bool find(TreapNode *root, int e)
{
    if (root ==NULL)
    {
        return false;
    }
    if (root->data == e)
    {
        return true;
    }
    if (e < root->data)
    {
        return find(root->left, e);
    }
    else
    {
        return find(root->right, e);
    }
}

TreapNode *deleteNode(TreapNode *root, int e)
{
    if (root == NULL)
    {
        return root;
    }
    if (e < root->data)
    {
        root->left = deleteNode(root->left, e);
    }
    else if (e > root->data)
    {
        root->right = deleteNode(root->right, e);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left ==NULL)
        {
            root = leftRotate(root);
        }
        else if (root->right == NULL)
        {
            root = rightRotate(root);
        }
        else
        {
            if (root->left->priority >root->right->priority)
            {
                root = rightRotate(root);
            }
            else
            {
                root = leftRotate(root);
            }
        }
        return deleteNode(root, e);
    }
    return root;
}

void inOrder(TreapNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(TreapNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int n;
    cin >> n;
    TreapNode *root = NULL;
    string cmd;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "insert")
        {
            int e, pri;
            cin >> e >> pri;
            root = insert(root, e, pri);
        }
        else if (cmd == "delete")
        {
            int e;
            cin >> e;
            root = deleteNode(root, e);
        }
        else if (cmd == "find")
        {
            int e;
            cin >> e;
            cout << (find(root, e) ? "yes" : "no") << endl;
        }
        else if (cmd == "print")
        {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
    return 0;
}