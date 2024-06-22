#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    int value;
    vector<int> children;
    int d;
};

void BFS(vector<Vertex *> vertices)
{
    vector<int> queue;
    int head = 0;
    int tail = 0;
    queue.push_back(0);
    tail++;
    vertices[0]->d = 1;
    while (head < tail)
    {
        int u = queue[head];
        head++;
        for (int i = 0; i < vertices[u]->children.size(); i++)
        {
            int v = vertices[u]->children[i] - 1;
            if (vertices[v]->d == 0)
            {
                vertices[v]->d = vertices[u]->d + 1;
                queue.push_back(v);
                tail++;
            }
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
        }
    }

    BFS(vertices);

    for (int i = 0; i < n; i++)
    {
        cout << vertices[i]->value << " " << vertices[i]->d - 1 << endl;
    }

    return 0;
}