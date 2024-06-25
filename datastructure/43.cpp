#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Vertex
{
    int value;
    vector<int> children;
};

// BFS to find all reachable nodes from a given node
void BFS(vector<Vertex *> &vertices, int start, vector<int> &component, int component_id)
{
    queue<int> q;
    q.push(start);
    component[start] = component_id;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : vertices[curr]->children)
        {
            if (component[child] == -1)
            { // Not visited
                component[child] = component_id;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Vertex *> vertices(n);
    for (int i = 0; i < n; i++)
    {
        vertices[i] = new Vertex();
        vertices[i]->value = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vertices[u]->children.push_back(v);
        vertices[v]->children.push_back(u); // since the relationship is bidirectional
    }

    // Preprocess to find all connected components
    vector<int> component(n, -1);
    int component_id = 0;

    for (int i = 0; i < n; i++)
    {
        if (component[i] == -1)
        { // If not yet visited
            BFS(vertices, i, component, component_id);
            component_id++;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (component[u] == component[v])
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete vertices[i];
    }

    return 0;
}
