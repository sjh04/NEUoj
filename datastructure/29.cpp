#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int e)
{
    Node *newNode = new Node();
    newNode->data = e;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int e)
{
    if (root == NULL)
    {
        root = createNode(e);
    }
    else if (e <= root->data)
    {
        root->left = insert(root->left, e);
    }
    else
    {
        root->right = insert(root->right, e);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void free(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root;
}

int main()
{
    int n;
    string cmd;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "insert")
        {
            int e;
            cin >> e;
            root = insert(root, e);
        }
        else if (cmd == "print")
        {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
    free(root);
    return 0;
}