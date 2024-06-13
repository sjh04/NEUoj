#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int parent;
    int depth;
    vector<int> children;
};

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
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j ++)
        {
            int child;
            cin >> child;
            nodes[id].children.push_back(child);
            nodes[child].parent = id;
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
        cout << "node " << i << ": parent = " << nodes[i].parent << ", depth = " << nodes[i].depth << ", ";
        if (nodes[i].parent == -1)
        {
            cout << "root, ";
        }
        else if (nodes[i].children.size() == 0)
        {
            cout << "leaf, ";
        }
        else
        {
            cout << "internal node, ";
        }
        cout << "[";
        for (int j = 0; j < nodes[i].children.size(); j++)
        {
            cout << nodes[i].children[j];
            if (j != nodes[i].children.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}