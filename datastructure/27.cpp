#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int parent;
    int left;
    int right;
};

void preOrder(Node *nodes, int id)
{
    if (id == -1)
    {
        return;
    }
    cout << " " << id;
    preOrder(nodes, nodes[id].left);
    preOrder(nodes, nodes[id].right);
}

void inOrder(Node *nodes, int id)
{
    if (id == -1)
    {
        return;
    }
    inOrder(nodes, nodes[id].left);
    cout << " " << id;
    inOrder(nodes, nodes[id].right);
}

void postOrder(Node *nodes, int id)
{
    if (id == -1)
    {
        return;
    }
    postOrder(nodes, nodes[id].left);
    postOrder(nodes, nodes[id].right);
    cout << " " << id;
}

int main()
{
    int n;
    cin >> n;
    vector<Node> nodes(n);

    for (int i = 0; i < n; i++)
    {
        nodes[i].parent = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int id, left, right;
        cin >> id >> left >> right;
        nodes[id].left = left;
        nodes[id].right = right;
        if (left != -1)
        {
            nodes[left].parent = id;
        }
        if (right != -1)
        {
            nodes[right].parent = id;
        }
    }

    int root;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == -1)
        {
            root = i;
        }
    }

    cout << "Preorder" << endl;
    preOrder(&nodes[0], root);
    cout << endl;
    cout << "Inorder" << endl;
    inOrder(&nodes[0], root);
    cout << endl;
    cout << "Postorder" << endl;
    postOrder(&nodes[0], root);
    cout << endl;

    return 0;
}