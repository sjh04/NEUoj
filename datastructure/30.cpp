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

Node *deleteNode(Node *root, int e)
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
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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

bool find(Node *root, int e)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == e)
    {
        return true;
    }
    if (e <= root->data)
    {
        return find(root->left, e);
    }
    return find(root->right, e);
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
        else if (cmd == "find")
        {
            int e;
            cin >> e;
            cout << (find(root, e) ? "yes" : "no") << endl;
        }
        else if (cmd == "delete")
        {
            int e;
            cin >> e;
            root = deleteNode(root, e);
        }
    }
    free(root);
    return 0;
}