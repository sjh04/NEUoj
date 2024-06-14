#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *buildTree(vector<int> preOrder, vector<int> inOrder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd)
    {
        return NULL;
    }

    Node *root = new Node();
    root->data = preOrder[preStart];

    int rootIndex;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inOrder[i] == preOrder[preStart])
        {
            rootIndex = i;
            break;
        }
    }

    int leftSize = rootIndex - inStart;
    root->left = buildTree(preOrder, inOrder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
    root->right = buildTree(preOrder, inOrder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);

    return root;
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << " " << root->data;
}

int main()
{
    Node *root = new Node();

    int n;
    cin >> n;
    vector<int> preOrder(n), inOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    root = buildTree(preOrder, inOrder, 0, n - 1, 0, n - 1);

    postOrder(root);
    return 0;
}