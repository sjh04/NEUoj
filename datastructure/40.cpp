#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    int value;
    vector<int> children;
};

void print(vector<Vertex *> vertices)
{
    int n = vertices.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vertices[i]->children.size(); j++)
        {
            matrix[i][vertices[i]->children[j] - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Vertex *> vertices(n);
    for (int i = 0; i < n; i++)
    {
        vertices[i] = new Vertex();
        cin >> vertices[i]->value;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int child;
            cin >> child;
            vertices[i]->children.push_back(child);
        }
    }

    print(vertices);

    return 0;
}