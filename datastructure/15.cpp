#include <iostream>

using namespace std;

struct MyTree
{
    string str;
    MyTree *left;
    MyTree *right;
};

MyTree *createTree(string str)
{
    MyTree *tree = new MyTree;
    tree->str = str;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

MyTree *insert(MyTree *tree, string str)
{
    if (tree == NULL)
    {
        return createTree(str);
    }
    if (str < tree->str)
    {
        tree->left = insert(tree->left, str);
    }
    else
    {
        tree->right = insert(tree->right, str);
    }
    return tree;
}

bool search(MyTree *tree, string str)
{
    if (tree == NULL)
    {
        return false;
    }
    if (str == tree->str)
    {
        return true;
    }
    if (str < tree->str)
    {
        return search(tree->left, str);
    }
    return search(tree->right, str);
}

void freeTree(MyTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    delete tree;
}

int main()
{
    MyTree *tree =NULL;
    int q;
    cin >> q;
    string cmd;
    string str;
    for (int i = 0; i < q; i++)
    {
        cin >> cmd;
        if (cmd == "insert")
        {
            cin >> str;
            tree = insert(tree, str);
        }
        else if (cmd == "find")
        {
            cin >> str;
            if (search(tree, str))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
}