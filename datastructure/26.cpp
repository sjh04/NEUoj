#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
    int left;
    int right;
};

void getHeight(vector<Node> &nodes, int id)
{
    int left = nodes[id].left;
    int right = nodes[id].right;
    int height = 0;
    if (left != -1)
    {
        getHeight(nodes, left);
        height = max(height, nodes[left].height + 1);
    }
    if (right != -1)
    {
        getHeight(nodes, right);
        height = max(height, nodes[right].height + 1);
    }
    nodes[id].height = height;
}

int main()
{
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++)
    {
        nodes[i].parent = -1;
        nodes[i].sibling = -1;
        nodes[i].degree = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int id, left, right;
        cin >> id >> left >> right;
        nodes[id].left = left;
        nodes[id].right = right;
        if (left != -1)
        {
            nodes[id].degree++;
            nodes[left].parent = id;
            nodes[left].sibling = right;
        }
        if (right != -1)
        {
            nodes[id].degree++;
            nodes[right].parent = id;
            nodes[right].sibling = left;
        }
    }


    for (int i = 0; i < n; i++)
    {
        int depth = 0;
        int parent = nodes[i].parent;
        while (parent != -1)
        {
            depth++;
            parent = nodes[parent].parent;
        }
        nodes[i].depth = depth;
    }

    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == -1)
        {
            getHeight(nodes, i);
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "node " << i << ": parent = " << nodes[i].parent << ", sibling = " << nodes[i].sibling << ", degree = " << nodes[i].degree << ", depth = " << nodes[i].depth << ", height = " << nodes[i].height << ", ";
        if (nodes[i].parent == -1)
        {
            cout << "root";
        }
        else if (nodes[i].degree == 0)
        {
            cout << "leaf";
        }
        else
        {
            cout << "internal node";
        }
        cout << endl;
    }

    return 0;
}