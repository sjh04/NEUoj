#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    int value;
    vector<int> children;
    int d, f;
};

void DFSVisit(vector<Vertex *> vertices, int i, int &time)
{
    time++;
    vertices[i]->d = time;
    for (int j = 0; j < vertices[i]->children.size(); j++)
    {
        if (vertices[vertices[i]->children[j] - 1]->d == 0)
        {
            DFSVisit(vertices, vertices[i]->children[j] - 1, time);
        }
    }
    time++;
    vertices[i]->f = time;
}

void DFS(vector<Vertex *> vertices)
{
    int time = 0;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->d == 0)
        {
            DFSVisit(vertices, i, time);
        }
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
            vertices[i]->d = 0;
            vertices[i]->f = 0;
        }
    }

    DFS(vertices);

    for (int i = 0; i < n; i++)
    {
        cout << vertices[i]->value << " " << vertices[i]->d << " " << vertices[i]->f << endl;
    }

    return 0;
}