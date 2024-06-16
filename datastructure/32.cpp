#include <iostream>
#include <vector>
#define NIL -2000000001

using namespace std;

struct Node
{
    long long data;
    long long parent;
    long long left;
    long long right;
};

int main()
{
    int n;
    cin >> n;
    vector<Node> tree(n);

    for (int i = 0; i < n; i++)
    {
        tree[i].parent = NIL;
        tree[i].left = NIL;
        tree[i].right = NIL;
    }

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        tree[i].data = k;
        if (i != 0)
        {
            tree[i].parent = tree[(i - 1) / 2].data;
            if (i % 2 == 0)
            {
                tree[(i - 1) / 2].right = k;
            }
            else
            {
                tree[(i - 1) / 2].left = k;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "node " << i + 1 << ": ";
        cout << "key = " << tree[i].data << ", ";
        if (tree[i].parent != NIL)
        {
            cout << "parent key = " << tree[i].parent << ", ";
        }
        if (tree[i].left != NIL)
        {
            cout << "left key = " << tree[i].left << ", ";
        }
        if (tree[i].right != NIL)
        {
            cout << "right key = " << tree[i].right << ", ";
        }
        cout << endl;
    }

    return 0;
}